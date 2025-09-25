# RtlUInt8Sub function

## Description

The **RtlUInt8Sub** routine subtracts one value of type **UINT8** from another.

## Parameters

### `u8Minuend` [in]

The value from which *u8Subtrahend* is subtracted.

### `u8Subtrahend` [in]

The value to subtract from *u8Minuend*.

### `pu8Result` [out]

A pointer to the result. If the operation results in a value that overflows or underflows the capacity of the type, the function returns STATUS_INTEGER_OVERFLOW and this parameter is not valid.

## Return value

**RtlUInt8Sub** returns STATUS_SUCCESS if the routine is successful. Possible error return values include the following status code.

| Return code | Description |
| --- | --- |
| **STATUS_INTEGER_OVERFLOW** | An arithmetic overflow occurred. |

## Remarks

This is one of a set of inline functions designed to provide arithmetic operations and perform validity checks with minimal impact on performance.