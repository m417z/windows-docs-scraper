# SERVENT structure

## Description

The
**servent** structure is used to store or return the name and service number for a given service name.

## Members

### `s_name`

The official name of the service.

### `s_aliases`

A **NULL**-terminated array of alternate names.

### `s_port`

The port number at which the service can be contacted. Port numbers are returned in network byte order.

### `s_proto`

The name of the protocol to use when contacting the service.

## See also

[getservbyname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getservbyname)