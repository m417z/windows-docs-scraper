## Description

Used to store received ICMP error information.

## Members

### `srcaddress`

Type: **[SOCKADDR_INET](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)**

The source IP address of the ICMP error.

### `protocol`

Type: **IPPROTO**

The protocol of the ICMP error (either **IPPROTO_ICMP** or **IPPROTO_ICMPV6**).

### `type`

Type: **[UINT8](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The ICMP error type.

### `code`

Type: **[UINT8](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The ICMP error code.

## Remarks

## See also