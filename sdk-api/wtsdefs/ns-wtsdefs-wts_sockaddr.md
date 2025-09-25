# WTS_SOCKADDR structure

## Description

Contains a socket address.

## Members

### `sin_family`

An integer index into the following structure members.

### `u`

### `u.ipv4`

An IPv4 address.

### `u.ipv4.sin_port`

Specifies a TCP or UDP port number.

### `u.ipv4.in_addr`

Specifies the IP address.

### `u.ipv4.sin_zero`

Contains an array of zeros.

### `u.ipv6`

An IPv6 address.

### `u.ipv6.sin6_port`

Specifies a TCP or UDP port number.

### `u.ipv6.sin6_flowinfo`

Contains IPv6 flow information.

### `u.ipv6.sin6_addr`

Specifies the IP address.

### `u.ipv6.sin6_scope_id`

Contains a scope ID