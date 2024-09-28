# Red Hat Enterprise Linux (RHEL) - `dup2` System Call Implementation

## Overview

This repository contains the implementation and detailed steps of a project focused on:
1. **Installing Red Hat Enterprise Linux (RHEL)** in a virtual environment.
2. **Understanding and implementing the `dup2` system call** in C programming, which is used to duplicate file descriptors and manage input/output redirection in Unix-based operating systems.

The project demonstrates how to set up a Red Hat environment using virtualization software (VMware or VirtualBox) and explores how to work with system calls like `dup2` in Linux system programming.

---

## Table of Contents
- [Introduction](#introduction)
- [Objectives](#objectives)
- [Requirements](#requirements)
- [Installation Guide for RHEL](#installation-guide-for-rhel)
- [System Call: `dup2`](#system-call-dup2)
- [Testing and Usage](#testing-and-usage)
- [Issues and Troubleshooting](#issues-and-troubleshooting)
- [Future Outlook](#future-outlook)

---

## Introduction

Red Hat Enterprise Linux (RHEL) is a powerful Linux distribution widely used in enterprise environments due to its robustness, security, and long-term support. This project offers a practical understanding of RHEL installation, virtualization, and system programming using the `dup2` system call to manage file descriptors.

### Key Features:
- Installation of RHEL on a virtual machine.
- Practical examples and implementations of the `dup2` system call in C.
- Advanced examples of using `dup2` in process forking and redirection.
- Hands-on experience with Linux system programming concepts.

---

## Objectives

The primary objectives of this project are:
1. **Install and Configure Red Hat Enterprise Linux (RHEL)** in a virtualized environment.
2. **Explore Filesystem Options** during installation (ext4, XFS, Btrfs).
3. **Implement and Demonstrate the `dup2` System Call** for file descriptor manipulation.
4. **Learn to Redirect Input/Output Streams** using `dup2` in C programs.
5. **Demonstrate Process Control and Redirection** using `fork()` and `dup2`.

---

## Requirements

### Hardware Requirements:
- Minimum 4 GB of RAM
- 20 GB of hard drive space
- A multi-core processor (e.g., Intel Core i5 or AMD Ryzen)
- Virtualization enabled in BIOS

### Software Requirements:
- VMware Workstation Player or Oracle VirtualBox
- RHEL ISO file (available from the [Red Hat Developer Portal](https://developers.redhat.com/products/rhel/download))
- GCC (GNU Compiler Collection) to compile C programs
- Basic knowledge of Linux commands and C programming

---

## Installation Guide for RHEL

### Steps to Install RHEL in a Virtual Machine:
1. Download the RHEL ISO file from the [Red Hat Developer Portal](https://developers.redhat.com/products/rhel/download).
2. Install VMware Workstation Player or Oracle VirtualBox on your system.
3. Create a new virtual machine, allocating at least 2 CPUs, 4 GB RAM, and 20 GB of storage.
4. Boot the VM from the RHEL ISO image and follow the installation prompts:
   - Choose language and keyboard layout.
   - Select **ext4** or another filesystem option.
   - Configure network settings (optional).
   - Create user accounts and set the root password.
5. Complete the installation and reboot into RHEL.

For more detailed instructions, refer to the [Installation Steps](#installation-guide-for-rhel).

---

## System Call: `dup2`

### What is `dup2`?
`dup2(int oldfd, int newfd)` is a Unix system call used to duplicate a file descriptor. It redirects `newfd` to `oldfd`, allowing developers to manage input/output streams in a controlled manner.

### Key Features of `dup2`:
- Duplicates `oldfd` to `newfd`, closing `newfd` if it is already open.
- Commonly used for input/output redirection, especially in shell programming.
- Useful in network programming, process forking, and inter-process communication.

### Example Usage:

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_fd == -1) {
        perror("Error opening file");
        return 1;
    }
    dup2(file_fd, STDOUT_FILENO);  // Redirect stdout to file
    printf("This will be written to output.txt instead of the terminal.\n");
    close(file_fd);
    return 0;
}
