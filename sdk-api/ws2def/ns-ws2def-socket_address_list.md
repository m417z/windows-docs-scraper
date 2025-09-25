# SOCKET_ADDRESS_LIST structure

## Description

The SOCKET_ADDRESS_LIST structure defines a variable-sized list of transport addresses.

## Members

### `iAddressCount`

The number of transport addresses in the list.

### `Address`

A variable-sized array of SOCKET_ADDRESS structures. The SOCKET_ADDRESS structure is defined as
follows:

```
typedef struct _SOCKET_ADDRESS {
  LPSOCKADDR  lpSockaddr;
  INT  iSockaddrLength;
} SOCKET_ADDRESS, *PSOCKET_ADDRESS, *LPSOCKET_ADDRESS;
```

#### lpSockaddr

A pointer to a buffer that contains a transport address.

#### iSockaddrLength

The size, in bytes, of the SOCKADDR structure type that is pointed to by the
**lpSockaddr** member.

## Remarks

A WSK application passes a buffer to the
[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_control_socket) function when the WSK
application queries the current list of local transport addresses that match a socket's address family.
If the call to the
**WskControlSocket** function succeeds, the buffer contains a SOCKET_ADDRESS_LIST structure followed by
the SOCKADDR structures for each of the local transport addresses that match the socket's address family.
The WSK subsystem fills in the
**Address** array and sets the
**iAddressCount** member to the number of entries in the array. The
**lpSockaddr** pointers in each of the SOCKET_ADDRESS structures in the array point to the specific
SOCKADDR structure type that corresponds to the address family that the WSK application specified when it
created the socket.

For more information about querying the current list of local transport addresses, see
[SIO_ADDRESS_LIST_QUERY](https://learn.microsoft.com/windows/win32/winsock/sio-address-list-query).

## See also

[SIO_ADDRESS_LIST_QUERY](https://learn.microsoft.com/windows/win32/winsock/sio-address-list-query)

[SOCKADDR](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-sockaddr)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_control_socket)