# UInt32x32To64 macro

## Syntax

```cpp
LONGLONG Int32x32To64(
  [in]  LONG a,
  [in]  LONG b
);
```

## Return value

Type: **LONGLONG**

The return value is the signed 64-bit integer result of the multiplication operation.

## Description

Multiplies two unsigned 32-bit integers, returning an unsigned 64-bit integer result. The function performs optimally on 32-bit Windows.

## Parameters

### `a` [in]

The first unsigned 32-bit integer for the multiplication operation.

### `b` [in]

The second unsigned 32-bit integer for the multiplication operation.

## Return value

The value of the product.

## Remarks

This function is implemented on all platforms by optimal inline code: a single multiply instruction that returns a 64-bit result.

Please note that the function's return value is a 64-bit value, not a
[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) structure.

## See also

[Int32x32To64](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-int32x32to64)

[Large Integers](https://learn.microsoft.com/windows/desktop/WinProg/large-integers)