# INTERFACE_INFO structure

## Description

The
**INTERFACE_INFO** structure is used in conjunction with the **SIO_GET_INTERFACE_LIST** ioctl command to obtain information about an interface IP address.

## Members

### `iiFlags`

A bitmask describing the status of the interface. The following flags are possible.

| Flag | Meaning |
| --- | --- |
| **IFF_UP** | The interface is running. |
| **IFF_BROADCAST** | The broadcast feature is supported. |
| **IFF_LOOPBACK** | The loopback interface is running. |
| **IFF_POINTTOPOINT** | The interface is using point-to-point link. |
| **IFF_MULTICAST** | The multicast feature is supported. |

### `iiAddress`

Address of an interface.

### `iiBroadcastAddress`

Broadcast address of the interface or the address of the other side for point-to-point links.

### `iiNetmask`

Netmask used by the interface.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **INTERFACE_INFO** structure is defined in the *Ws2ipdef.h* header file which is automatically included in the *Ws2tcpip.h* header file. The *Ws2ipdef.h* header files should never be used directly.

## See also

[Winsock IOCTLs](https://learn.microsoft.com/windows/desktop/WinSock/winsock-ioctls)