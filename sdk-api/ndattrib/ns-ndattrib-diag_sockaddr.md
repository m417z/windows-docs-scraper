# DIAG_SOCKADDR structure

## Description

The **DIAG_SOCKADDR** structure stores an
Internet Protocol (IP) address for a computer that is participating in a Windows Sockets
communication.

## Members

### `family`

Type: **USHORT**

Socket address group.

### `data`

Type: **CHAR[126]**

The maximum size of all the different socket address structures.

## Remarks

This data structure is designed to be used as a
**SOCKADDR** structure.