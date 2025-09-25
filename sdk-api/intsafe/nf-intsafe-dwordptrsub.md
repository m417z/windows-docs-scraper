# DWordPtrSub function

## Description

Subtracts one value of type **DWORD_PTR** from another.

## Parameters

### `dwMinuend` [in]

Type: **DWORD_PTR**

The value from which *dwSubtrahend* is subtracted.

### `dwSubtrahend` [in]

Type: **DWORD_PTR**

The value to subtract from *dwMinuend*.

### `pdwResult` [out]

Type: **DWORD_PTR***

A pointer to the result. If the operation results in a value that overflows or underflows the capacity of the type, the function returns INTSAFE_E_ARITHMETIC_OVERFLOW and this parameter is not valid.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is one of a set of inline functions designed to provide arithmetic operations and perform validity checks with minimal impact on performance.