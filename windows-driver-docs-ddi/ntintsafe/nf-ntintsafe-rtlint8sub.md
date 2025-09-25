# RtlInt8Sub function

## Description

Subtracts one value of type **INT8** from another.

## Parameters

### `i8Minuend` [in]

The value from which *i8Subtrahend* is subtracted.

### `i8Subtrahend` [in]

The value to subtract from *i8Minuend*.

### `pi8Result` [out]

A pointer to the result. If the operation results in a value that overflows or underflows the capacity of the type, the function returns STATUS_INTEGER_OVERFLOW and this parameter is not valid.

## Return value

Returns STATUS_SUCCESS if the operation is successful.

See the implementation of this helper function in `ntintsafe.h` in the WDK for possible error return values.

## Remarks

This is one of a set of inline functions designed to provide arithmetic operations and perform validity checks with minimal impact on performance.