# PROTOENT structure

## Description

The **protoent** structure contains the name and protocol numbers that correspond to a given protocol name. Applications must never attempt to modify this structure or to free any of its components. Furthermore, only one copy of this structure is allocated per thread, and therefore, the application should copy any information it needs before issuing any other Windows Sockets function calls.

## Members

### `p_name`

Official name of the protocol.

### `p_aliases`

Null-terminated array of alternate names.

### `p_proto`

Protocol number, in host byte order.