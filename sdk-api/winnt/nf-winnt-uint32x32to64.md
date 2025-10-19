# UInt32x32To64 macro

## Syntax

```cpp
ULONGLONG UInt32x32To64(
  [in]  ULONG a,
  [in]  ULONG b
);
```

## Return value

Type: **ULONGLONG**

The return value is the unsigned 64-bit integer result of the multiplication operation.

## Description

Multiplies two unsigned 32-bit integers, returning an unsigned 64-bit integer result. The function performs optimally on 32-bit Windows.

## Parameters

### `a` [in]

The first unsigned 32-bit integer for the multiplication operation.

### `b` [in]

The second unsigned 32-bit integer for the multiplication operation.

## Remarks

This function is implemented on all platforms by optimal inline code: a single multiply instruction that returns a 64-bit result.

Please note that the function's return value is a 64-bit value, not a
[ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer-r1) structure.

## See also

[Int32x32To64](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-int32x32to64)

[Large Integers](https://learn.microsoft.com/windows/desktop/WinProg/large-integers)