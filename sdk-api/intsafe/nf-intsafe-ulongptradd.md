# ULongPtrAdd function

## Description

Adds two values of type **ULONG_PTR**.

## Parameters

### `ulAugend` [in]

Type: **ULONG_PTR**

The first value in the equation.

### `ulAddend` [in]

Type: **ULONG_PTR**

The value to add to *ulAugend*.

### `pulResult` [out]

Type: **ULONG_PTR***

A pointer to the sum. If the operation results in a value that overflows or underflows the capacity of the type, the function returns INTSAFE_E_ARITHMETIC_OVERFLOW and this parameter is not valid.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is one of a set of inline functions designed to provide arithmetic operations and perform validity checks with minimal impact on performance.