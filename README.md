# ping-pong

## Requirements

Please provide us with a complete C or C++ program in source code form which meets the following requirements.
The program should implement a ping/pong behaviour using TCP as the transport mechanism. It should accept the following command line switches:

 * -s server mode
 * -c client mode
 * -t <target host> (client mode only)
 * -p <port>
 * -m <message>

The ping and pong packets should be in the following format:
><index><message>

Additionally:

The client should send a ping packet once a second with an incrementing 64-bit index.
The server should respond to the client with the received index and its own message string. 
Both the client and server should print to stdout the index and message string for each packet that they receive.
The program should be able to handle improper inputs gracefully and provide feedback to the user.
The program should handle errors gracefully and provide feedback to the user.
The program should be able to compile and run using gcc or g++ on a recent x86 or x86_64 Linux distribution (Debian, Ubuntu, CentOS/Red Hat). 
The program should be able to compile with the following flags: -Wall, -Werror, -Wshadow, and either -std=gnu99 or std=gnu++98 as appropriate for the compiler.
Include a Makefile.

## Build

> make

Resulting binary will be at .bin/pingpong

## Usage:
Ping-Pong commndline tool. Usage:
 * -s server mode
 * -c client mode
 * -t <target host> (client mode only)
 * -p <port> (between 1024 and 65535)
 * -m <message> (between 1 and 255 chars in length)
 * -h display this help message

## Example usage:

### Server
bin/pingpong -s -m "Pong from server" -p 4321

### Client
bin/pingpong -c -m "Ping from client" -p 4321 -t 127.0.0.1

