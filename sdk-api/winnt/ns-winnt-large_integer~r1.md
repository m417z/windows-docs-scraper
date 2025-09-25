# LARGE_INTEGER structure

## Description

Represents a 64-bit signed integer value.

**Note** Your C compiler may support 64-bit integers natively. For example, Microsoft Visual C++ supports the [__int64](https://learn.microsoft.com/windows/desktop/Midl/--int64) sized integer type. For more information, see the documentation included with your C compiler.

## Members

### `DUMMYSTRUCTNAME`

### `LowPart`

The low-order 32 bits.

### `HighPart`

The high-order 32 bits.

### `u`

### `QuadPart`

A signed 64-bit integer.

## Remarks

The **LARGE_INTEGER** structure is actually a union. If your compiler has built-in support for 64-bit integers, use the **QuadPart** member to store the 64-bit integer. Otherwise, use the **LowPart** and **HighPart** members to store the 64-bit integer.

## See also

[ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer~r1)