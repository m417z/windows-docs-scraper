# RtlInt8ToUIntPtr function

## Description

Converts a value of type **INT8** to a value of type **UINT_PTR**.

## Parameters

### `i8Operand` [in]

The value to be converted.

### `puResult` [out]

A pointer to the converted value. In the case where the conversion causes a truncation of the original value, the function returns STATUS_INTEGER_OVERFLOW and this parameter is not valid.

## Return value

Returns STATUS_SUCCESS if the operation is successful.

See the implementation of this helper function in `ntintsafe.h` in the WDK for possible error return values.

## Remarks

This is one of a set of inline functions designed to provide type conversions and perform validity checks with minimal impact on performance.

This function uses the following alternate name:

* RtlInt8ToSizeT