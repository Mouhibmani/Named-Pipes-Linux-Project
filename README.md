# Linux Project

## Overview
This is a simple Linux project that involves client-server communication using named pipes (FIFO). The project consists of a client program and a server program.

## Project Structure
- `client.h`: Contains the main functionality of the client program.
- `serv_cli_fifo.h`: Header file for shared constants and file paths.
- `Handlers_cli.h`: Header file for signal handling functions in the client program.
- `Handlers_serv.h`: Header file for signal handling functions in the server program.
- `serveur.h`: Main server program file.
- `makefile`: Makefile for building and running the project.

## Requirements
- Linux environment

## Building and Running the Project
To build the project, you can use the provided makefile. Open a terminal and navigate to the project directory. Use the following commands:

- Build both server and client:
  ```bash
  make
