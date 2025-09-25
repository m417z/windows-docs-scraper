# Int64ShllMod32 macro

## Syntax

```cpp
ULONGLONG Int64ShllMod32(
  [in]  ULONGLONG a,
  [in]  DWORD b
);
```

## Return value

Type: **ULONGLONG**

The return value is the unsigned 64-bit integer result of the left logical shift operation.

## Description

Performs a left logical shift operation on an unsigned 64-bit integer value. The function provides improved shifting code for left logical shifts where the shift count is in the range 0-31.

## Parameters

### `a` [in]

The unsigned 64-bit integer to be shifted.

### `b` [in]

The shift count in the range 0-31.

## Remarks

The shift count is the number of bit positions that the value's bits move.

In a left logical shift operation on an unsigned value, the value's bits move to the left, and vacated bits on the right side of the value are set to zero.

A compiler can generate optimal code for a left logical shift operation when the shift count is a constant. However, if the shift count is a variable whose range of values is unknown, the compiler must assume the worst case, leading to non-optimal code: code that calls a subroutine, or code that is inline but branches. By restricting the shift count to the range 0-31, the
**Int64ShllMod32** function lets the compiler generate optimal or near-optimal code.

Please note that the
**Int64ShllMod32** function's *Value* parameter and return value are 64-bit values, not
[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) structures.

## See also

[Int64ShraMod32](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-int64shramod32)

[Int64ShrlMod32](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-int64shrlmod32)

[Large Integers](https://learn.microsoft.com/windows/desktop/WinProg/large-integers)