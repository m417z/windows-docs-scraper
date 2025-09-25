# RtlIntPtrAdd function

## Description

Adds two values of type **INT_PTR**.

## Parameters

### `iAugend` [in]

The first value in the equation.

### `iAddend` [in]

The value to add to *iAugend*.

### `piResult` [out]

A pointer to the sum. If the operation results in a value that overflows or underflows the capacity of the type, the function returns STATUS_INTEGER_OVERFLOW and this parameter is not valid.

## Return value

Returns STATUS_SUCCESS if the operation is successful.

See the implementation of this helper function in `ntintsafe.h` in the WDK for possible error return values.

## Remarks

This is one of a set of inline functions designed to provide arithmetic operations and perform validity checks with minimal impact on performance.