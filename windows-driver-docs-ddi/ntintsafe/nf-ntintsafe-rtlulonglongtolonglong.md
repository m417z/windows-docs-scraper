# RtlULongLongToLongLong function

## Description

Converts a value of type **ULONGLONG** to a value of type **LONGLONG**.

## Parameters

### `ullOperand` [in]

The value to be converted.

### `pllResult` [out]

A pointer to the converted value. In the case where the conversion causes a truncation of the original value, the function returns STATUS_INTEGER_OVERFLOW and this parameter is not valid.

## Return value

Returns STATUS_SUCCESS if the operation is successful.

See the implementation of this helper function in `ntintsafe.h` in the WDK for possible error return values.

## Return value

Returns STATUS_SUCCESS if the operation is successful.

See the implementation of this helper function in `ntintsafe.h` in the WDK for possible error return values.

## Remarks

This is one of a set of inline functions designed to provide type conversions and perform validity checks with minimal impact on performance.

This function uses the following alternate name:

* RtlUIntPtrToLongLong
* RtlULongPtrToLongLong
* RtlULongLongToIntPtr
* RtlULongLongToInt64
* RtlULongLongToLong64
* RtlDWordLongToLongLong
* RtlDWordLongToLong64
* RtlDWordLongToInt64
* RtlULong64ToLongLong
* RtlULong64ToLong64
* RtlULong64ToInt64
* RtlDWord64ToLongLong
* RtlDWord64ToLong64
* RtlDWord64ToInt64
* RtlUInt64ToLongLong
* RtlUInt64ToLong64
* RtlUInt64ToInt64