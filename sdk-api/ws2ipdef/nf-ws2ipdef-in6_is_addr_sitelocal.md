## Description

Determines whether the address argument is an IPv6 site-local address.

## Parameters

### `a`

Type: **CONST [IN6_ADDR](https://learn.microsoft.com/windows/win32/api/in6addr/ns-in6addr-in6_addr) \***

Pointer to the address to test.

## Return value

`true` if the address is an IPv6 site-local address; otherwise, `false`.

Returns `true` for local-use IPv6 unicast addresses.

## Remarks

## See also