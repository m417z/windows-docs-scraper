# SysStringByteLen function

## Description

Returns the length (in bytes) of a BSTR.

## Parameters

### `bstr` [in, optional]

A previously allocated string.

## Return value

The number of bytes in *bstr*, not including the terminating null character. If *bstr* is null the return value is zero.

## Remarks

The returned value may be different from **strlen**(bstr) if the BSTR contains embedded null characters. This function always returns the number of bytes specified in the len parameter of the [SysAllocStringByteLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstringbytelen) function used to allocate the BSTR.

## See also

[String Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/string-manipulation-functions)