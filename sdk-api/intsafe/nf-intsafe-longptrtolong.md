# LongPtrToLong function

## Description

Converts a value of type **LONG_PTR** to a value of type **LONG**.

## Parameters

### `lOperand` [in]

Type: **LONG_PTR**

The value to be converted.

### `plResult` [out]

Type: **LONG***

A pointer to the converted value. In the case where the conversion causes a truncation of the original value, the function returns INTSAFE_E_ARITHMETIC_OVERFLOW and this parameter is not valid.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is one of a set of inline functions designed to provide type conversions and perform validity checks with minimal impact on performance.

**SSIZETToLong** is an alias for this function.