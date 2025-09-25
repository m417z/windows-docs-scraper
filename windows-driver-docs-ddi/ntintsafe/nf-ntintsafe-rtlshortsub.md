# RtlShortSub function

## Description

Subtracts one value of type **SHORT** from another.

## Parameters

### `sMinuend` [in]

The value from which *sSubtrahend* is subtracted.

### `sSubtrahend` [in]

The value to subtract from *sMinuend*.

### `psResult` [out]

A pointer to the result. If the operation results in a value that overflows or underflows the capacity of the type, the function returns STATUS_INTEGER_OVERFLOW and this parameter is not valid.

## Return value

Returns STATUS_SUCCESS if the operation is successful.

See the implementation of this helper function in `ntintsafe.h` in the WDK for possible error return values.

## Remarks

This is one of a set of inline functions designed to provide arithmetic operations and perform validity checks with minimal impact on performance.

This function uses the following alternate name:

* RtlInt16Sub