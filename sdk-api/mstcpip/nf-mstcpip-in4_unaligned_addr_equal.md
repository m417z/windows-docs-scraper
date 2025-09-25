## Description

Determines whether two IPv4 addresses are equal (where the pointer arguments are permitted to be unaligned).

## Parameters

### `a`

Type: \_In\_ **CONST [IN_ADDR](https://learn.microsoft.com/windows/win32/api/inaddr/ns-inaddr-in_addr) \***

Pointer (which is permitted to be unaligned) to the first address.

### `b`

Type: \_In\_ **CONST [IN_ADDR](https://learn.microsoft.com/windows/win32/api/inaddr/ns-inaddr-in_addr) \***

Pointer (which is permitted to be unaligned) to the second address.

## Return value

`true` if the two addresses arguments point to values that are equal; otherwise, `false`.

## Remarks

## See also