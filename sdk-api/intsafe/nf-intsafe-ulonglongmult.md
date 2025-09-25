## Description

Multiplies one value of type **size_t** by another.

## Parameters

### `ullMultiplicand` [in]

The value to be multiplied by *cbMultiplier*.

### `ullMultiplier` [in]

The value by which to multiply *cbMultiplicand*.

### `pullResult` [out]

A pointer to the result. If the operation results in a value that overflows or underflows the capacity of the type, the function returns INTSAFE_E_ARITHMETIC_OVERFLOW and this parameter is not valid.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is one of a set of inline functions designed to provide arithmetic operations and perform validity checks with minimal impact on performance.