# RtlInt8Mult function

## Description

Multiplies one value of type **INT8** by another.

## Parameters

### `i8Multiplicand` [in]

The value to be multiplied by *i8Multiplier*.

### `i8Multiplier` [in]

The value by which to multiply *i8Multiplicand*.

### `pi8Result` [out]

A pointer to the result. If the operation results in a value that overflows or underflows the capacity of the type, the function returns STATUS_INTEGER_OVERFLOW and this parameter is not valid.

## Return value

Returns STATUS_SUCCESS if the operation is successful.

See the implementation of this helper function in `ntintsafe.h` in the WDK for possible error return values.

## Remarks

This is one of a set of inline functions designed to provide arithmetic operations and perform validity checks with minimal impact on performance.