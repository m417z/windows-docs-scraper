# ULongLongAdd function

## Description

Adds two values of type **SIZE_T**.

## Parameters

### `ullAugend` [in]

Type: **SIZE_T**

The first value in the equation.

### `ullAddend` [in]

Type: **SIZE_T**

The value to add to *cbAugend*.

### `pullResult` [out]

Type: **SIZE_T***

A pointer to the sum. If the operation results in a value that overflows or underflows the capacity of the type, the function returns INTSAFE_E_ARITHMETIC_OVERFLOW and this parameter is not valid.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is one of a set of inline functions designed to provide arithmetic operations and perform validity checks with minimal impact on performance.