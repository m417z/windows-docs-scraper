# HTTP_SERVICE_CONFIG_IP_LISTEN_PARAM structure

## Description

The
**HTTP_SERVICE_CONFIG_IP_LISTEN_PARAM** structure is used to specify an IP address to be added to or deleted from the list of IP addresses to which the HTTP service binds.

## Members

### `AddrLength`

The size, in bytes, of the address pointed to by **pAddress**.

### `pAddress`

A pointer to an Internet Protocol (IP) address to be added to or deleted from the listen list.

To specify an IPv6 address, use a [SOCKADDR_IN6](https://learn.microsoft.com/previous-versions/aa915715(v=msdn.10)) structure, declared in the Ws2tcpip.h header file, and cast its address to a PSOCKADDR when you use it to set the **pAddress** member. The **sin_family** member of the SOCKADDR_IN6 should be set to AF_INET6.

 If the **sin_addr** field in [SOCKADDR_IN6](https://learn.microsoft.com/previous-versions/aa915715(v=msdn.10)) structure is set to 0.0.0.0, it means to bind to all IPv4 addresses.
If the **sin6_addr** field in [SOCKADDR_IN6](https://learn.microsoft.com/previous-versions/aa915715(v=msdn.10)) is set to [::], it means to bind to all IPv6 addresses.

## See also

[HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration)

[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)