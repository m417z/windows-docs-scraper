# WSANETWORKEVENTS structure

## Description

The
**WSANETWORKEVENTS** structure is used to store a socket's internal information about network events.

## Members

### `lNetworkEvents`

Indicates which of the FD_XXX network events have occurred.

### `iErrorCode`

Array that contains any associated error codes, with an array index that corresponds to the position of event bits in **lNetworkEvents**. The identifiers FD_READ_BIT, FD_WRITE_BIT and others can be used to index the **iErrorCode** array.

## See also

[WSAEnumNetworkEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnetworkevents)

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)