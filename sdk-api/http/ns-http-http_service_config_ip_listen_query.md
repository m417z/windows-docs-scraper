# HTTP_SERVICE_CONFIG_IP_LISTEN_QUERY structure

## Description

The
**HTTP_SERVICE_CONFIG_IP_LISTEN_QUERY** structure is used by
[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) to return a list of the Internet Protocol (IP) addresses to which the HTTP service binds.

## Members

### `AddrCount`

The number of address structures in the **AddrList** array.

### `AddrList`

An array of
[SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85)) structures that contains IP addresses in either IPv4 or IPv6 form. To determine what form an address in the list has, cast it to a SOCKADDR and examine the **sa_family** element. If **sa_family** is equal to AF_INET, the address is in IPv4 form, or if it is equal to AF_INET6, the address is in IPv6 form.

## Remarks

An IPv4 address may be expressed as a literal string of four dotted decimal numbers, each in the range 0-255, such as 192.168.197.113. IPv4 addresses are contained in **sockaddr_in** structures, declared in the Windows header file Winsock2.h as follows:

``` syntax
  struct sockaddr_in {
    short    sin_family;        /* == AF_INET */
    u_short  sin_port;          /* Transport-level port number */
    struct   in_addr sin_addr;  /* IPv4 address */
    char     sin_zero[8];
  };

```

The **SOCKADDR_IN** structure is exactly equivalent to **sockaddr_in** by typedef.

An IPv6 address can be expressed as a literal string enclosed in square brackets that contains hex numbers separated by colons; examples are: [::1] and [3ffe:ffff:6ECB:0101]. IPv6 addresses are contained in **sockaddr_in6** structures, declared in the Windows header file WS2tcpip.h as follows:

``` syntax
  struct sockaddr_in6 {
    short    sin6_family;       /* == AF_INET6 */
    u_short  sin6_port;         /* Transport-level port number */
    u_long   sin6_flowinfo;     /* IPv6 flow information */
    IN6_ADDR sin6_addr;         /* IPv6 address */
    u_long   sin6_scope_id;     /* set of scope interfaces */
  };

```

The **SOCKADDR_IN6** structure is exactly equivalent to **sockaddr_in6** by typedef.

## See also

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85))