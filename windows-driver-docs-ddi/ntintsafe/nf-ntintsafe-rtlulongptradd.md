# RtlULongPtrAdd function

## Description

Adds two values of type **ULONG_PTR**.

## Parameters

### `ulAugend` [in]

The first value in the equation.

### `ulAddend` [in]

The value to add to *ulAugend*.

### `pulResult` [out]

A pointer to the sum. If the operation results in a value that overflows or underflows the capacity of the type, the function returns STATUS_INTEGER_OVERFLOW and this parameter is not valid.

## Return value

Returns STATUS_SUCCESS if the operation is successful.

See the implementation of this helper function in `ntintsafe.h` in the WDK for possible error return values.