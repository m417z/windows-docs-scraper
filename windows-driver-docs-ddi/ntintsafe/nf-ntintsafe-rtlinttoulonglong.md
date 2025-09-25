# RtlIntToULongLong function

## Description

Converts a value of type **INT** to a value of type **ULONGLONG**.

## Parameters

### `iOperand` [in]

The value to be converted.

### `pullResult` [out]

A pointer to the converted value. In the case where the conversion causes a truncation of the original value, the function returns STATUS_INTEGER_OVERFLOW and this parameter is not valid.

## Return value

Returns STATUS_SUCCESS if the operation is successful.

See the implementation of this helper function in `ntintsafe.h` in the WDK for possible error return values.

## Remarks

This is one of a set of inline functions designed to provide type conversions and perform validity checks with minimal impact on performance.

This function uses the following alternate name:

* RtlIntToDWordLong
* RtlIntToULong64
* RtlIntToDWord64
* RtlIntToUInt64
* RtlInt32ToULongLong
* RtlInt32ToDWordLong
* RtlInt32ToULong64
* RtlInt32ToDWord64
* RtlInt32ToUInt64
* RtlIntToUIntPtr
* RtlIntToSizeT
* RtlInt32ToUIntPtr
* RtlInt32ToSizeT
* RtlIntToUIntPtr
* RtlIntToULongPtr
* RtlIntToDWordPtr
* RtlIntToSIZET
* RtlInt32ToULongPtr
* RtlInt32ToDWordPtr
* RtlInt32ToSIZET
* RtlIntToULongPtr