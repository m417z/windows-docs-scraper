## Description

Determines whether the address argument (which is permitted to be unaligned) is an IPv4 link-local address.

## Parameters

### `a`

Type: \_In\_ **CONST [IN_ADDR](https://learn.microsoft.com/windows/win32/api/inaddr/ns-inaddr-in_addr) \***

Pointer (which is permitted to be unaligned) to the address to test.

## Return value

`true` if the address is an IPv4 link-local address; otherwise, `false`.

Returns `true` for local-use IPv4 unicast addresses. Returns `false` for the IPv4 loopback address. Doesn't return `true` for IPv4 multicast addresses of link-local scope.

## Remarks

## See also