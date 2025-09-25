# SOCKADDR_STORAGE_XP structure

## Description

The SOCKADDR_STORAGE structure is a generic structure that specifies a transport address.

## Members

### `ss_family`

The address family for the transport address. For more information about supported address
families, see
[WSK Address Families](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt808757(v=vs.85)).

### `__ss_pad1`

A padding of 6 bytes that puts the
**__ss_align** member on an eight-byte boundary within the structure.

### `__ss_align`

A 64-bit value that forces the structure to be 8-byte aligned.

### `__ss_pad2`

A padding of an additional 112 bytes that brings the total size of the SOCKADDR_STORAGE structure
to 128 bytes.

## Remarks

A WSK application typically does not directly access any of the members of the SOCKADDR_STORAGE
structure except for the
**ss_family** member. Instead, a pointer to a SOCKADDR_STORAGE structure is normally cast to a pointer
to the specific SOCKADDR structure type that corresponds to a particular address family.

## See also

[SOCKADDR](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-sockaddr)