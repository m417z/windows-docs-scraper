# EngMulDiv function

## Description

The **EngMulDiv** function multiplies two 32-bit values and then divides the 64-bit result by a third 32-bit value.

## Parameters

### `a` [in]

Specifies the 32-bit signed multiplicand.

### `b` [in]

Specifies the 32-bit signed multiplier.

### `c` [in]

Specifies the 32-bit signed divisor by which the result of *a***b* is to be divided.

## Return value

**EngMulDiv** returns the signed 32-bit result of the multiplication and division. The return value is rounded up or down to the nearest integer.

## Remarks

Drivers should not pass a zero divisor to **EngMulDiv**.