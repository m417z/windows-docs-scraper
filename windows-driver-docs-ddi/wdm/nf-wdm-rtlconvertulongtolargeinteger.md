# RtlConvertUlongToLargeInteger function

## Description

The **RtlConvertUlongToLargeInteger** routine converts the input unsigned integer to a signed large integer. For Windows XP and later versions of Windows, do not use this routine; use the native support for **__int64**.

## Parameters

### `UnsignedInteger` [in]

Specifies a value of type ULONG.

## Return value

**RtlConvertUlongToLargeInteger** returns the converted large integer.