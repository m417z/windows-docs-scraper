# in_addr structure

## Description

The
**in_addr** structure represents an IPv4 Internet address.

## Members

### `S_un`

### `S_un.S_un_b`

An IPv4 address formatted as four **u_char**s.

### `S_un.S_un_b.s_b1`

### `S_un.S_un_b.s_b2`

### `S_un.S_un_b.s_b3`

### `S_un.S_un_b.s_b4`

### `S_un.S_un_w`

An IPv4 address formatted as two **u_short**s.

### `S_un.S_un_w.s_w1`

### `S_un.S_un_w.s_w2`

### `S_un.S_addr`

An IPv4 address formatted as a **u_long**.

## Remarks

The **in_addr** structure is used with IPv4 addresses.

The **in_addr** structure is the IPv4 equivalent of the IPv6-based [in6_addr](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure.

**Note** The **IN_ADDR**, **PIN_ADDR**, and **LPIN_ADDR** derived structures are only defined on the Windows SDK released with Windows Vista and later. The **IN_ADDR**, **PIN_ADDR**, and **LPIN_ADDR** derived structures are defined in the *Inaddr.h* header file. On earlier versions of the Windows SDK, variables of this type should be declared as **struct in_addr**.

## See also

[in6_addr](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85))

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)