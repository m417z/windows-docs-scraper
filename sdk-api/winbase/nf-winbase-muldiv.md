# MulDiv function

## Description

Multiplies two 32-bit values and then divides the 64-bit result by a third 32-bit value. The final result is rounded to the nearest integer.

## Parameters

### `nNumber` [in]

The multiplicand.

### `nNumerator` [in]

The multiplier.

### `nDenominator` [in]

The number by which the result of the multiplication operation is to be divided.

## Return value

If the function succeeds, the return value is the result of the multiplication and division, rounded to the nearest integer. If the result is a positive half integer (ends in .5), it is rounded up. If the result is a negative half integer, it is rounded down.

If either an overflow occurred or *nDenominator* was 0, the return value is -1.

## See also

[Int32x32To64](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-int32x32to64)

[Large Integers](https://learn.microsoft.com/windows/desktop/WinProg/large-integers)

[UInt32x32To64](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-uint32x32to64)