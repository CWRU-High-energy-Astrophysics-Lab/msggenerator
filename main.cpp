#include <iostream>
#include "msg.h"
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
#include <cstdio>
#include <cstring>
#include <random>
#include <chrono>


char *port ;
int serial_port;
struct termios tty;

std::string encrypt(const Generalmsg &generalmsg) {
    return std::string(generalmsg.getID() + "[" + generalmsg.getRev() + "]:" + std::to_string(generalmsg.getSize()) +
                       generalmsg.getPayload()+"\n");
}

std::string gen_random_str(const int len) {
    const std::string CHARACTERS=
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            ".?:!,";
    std::string tmp_s;
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += CHARACTERS[distribution(generator)];
    }

    return tmp_s;
}



bool setup() {
    if (tcgetattr(serial_port, &tty) != 0) {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
        //return 1;
    }

    tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
    tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
    tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size
    tty.c_cflag |= CS8; // 8 bits per byte (most common)
    tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

    tty.c_lflag &= ICANON;
    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR |
                     ICRNL); // Disable any special handling of received bytes

    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
    // tty.c_oflag &= ~OXTABS; // Prevent conversion of tabs to spaces (NOT PRESENT ON LINUX)
    // tty.c_oflag &= ~ONOEOT; // Prevent removal of C-d chars (0x004) in output (NOT PRESENT ON LINUX)

    tty.c_cc[VTIME] = 0;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 1;

    // Set in/out baud rate to be 9600
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    // Save tty settings, also checking for error
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
        return false;
    }
    return true;
}
std::string t2_gen(){
    auto time_in_nanoseconds =  std::chrono::duration_cast<std::chrono::microseconds>
            (std::chrono::high_resolution_clock::now().time_since_epoch()).count();

    std::cout << time_in_nanoseconds;
    return "";
}

void send(const std::string& msg) {
        write(serial_port, static_cast<const void*>(msg.c_str()), msg.size() + 1);
}



int main(int argc, char *argv[]) {

    int type;
    int size;
    int number;


    if (argc < 4 || strcmp(argv[1], "--help") == 0) {
        printf("use as: %s <msg type> <quantity> <port> <size>\n\r <msg type> would be: 1,2,3,4,5,6,0\n\r 1- Random General \t 2- T2 \t 3- T3 \n\r 4- Command \t 5- History \t 6- log\n\r"
               "<quantity> is how many msg should be sent\n\r"
               "<port> is the port to output on\n\r"
               "<size> will default to 0 but is the size of the payload of msg where applicable\n\r"
               "Error 2- port not found \n\r",argv[0]);

        exit(0);
    }
    sscanf(argv[1], "%d", &type);
    sscanf(argv[2], "%d", &number);
    port= argv[3];
    if (argc < 5) {
        size = 0;
    } else {
        sscanf(argv[4], "%d", &size);
    }
    serial_port = open(port, O_RDWR);
    if (!setup()) { exit(2);}


    for (int i = 0; i < number; ++i) {

        Generalmsg msg;
        switch (type) {
            case 0:
                exit(0);
            case 1:
                msg = Generalmsg("TEST", "rev1", gen_random_str(size), 1);
                break;
            case 2:




        }
        const std::string temp = encrypt(msg);
        std::cout << "Sending: " << temp << std::endl;
        send(temp);
    }

}
