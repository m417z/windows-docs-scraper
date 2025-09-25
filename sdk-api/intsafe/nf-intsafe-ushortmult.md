# UShortMult function

## Description

Multiplies one value of type **USHORT** by another.

## Parameters

### `usMultiplicand` [in]

Type: **USHORT**

The value to be multiplied by *usMultiplier*.

### `usMultiplier` [in]

Type: **USHORT**

The value by which to multiply *usMultiplicand*.

### `pusResult` [out]

Type: **USHORT***

A pointer to the result. If the operation results in a value that overflows or underflows the capacity of the type, the function returns INTSAFE_E_ARITHMETIC_OVERFLOW and this parameter is not valid.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is one of a set of inline functions designed to provide arithmetic operations and perform validity checks with minimal impact on performance.

**WordMult** is an alias for this function.