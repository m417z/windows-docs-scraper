# ULongPtrSub function

## Description

Subtracts one value of type **ULONG_PTR** from another.

## Parameters

### `ulMinuend` [in]

Type: **ULONG_PTR**

The value from which *ulSubtrahend* is subtracted.

### `ulSubtrahend` [in]

Type: **ULONG_PTR**

The value to subtract from *ulMinuend*.

### `pulResult` [out]

Type: **ULONG_PTR***

A pointer to the result. If the operation results in a value that overflows or underflows the capacity of the type, the function returns INTSAFE_E_ARITHMETIC_OVERFLOW and this parameter is not valid.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is one of a set of inline functions designed to provide arithmetic operations and perform validity checks, and to do so with minimal impact on performance.