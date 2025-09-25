# SysStringLen function

## Description

Returns the length of a BSTR.

## Parameters

### `pbstr` [in, optional]

A previously allocated string.

## Return value

The number of characters in *bstr*, not including the terminating null character. If *bstr* is null the return value is zero.

## Remarks

The returned value may be different from **strlen**(bstr) if the BSTR contains embedded Null characters. This function always returns the number of characters specified in the cch parameter of the [SysAllocStringLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstringlen) function used to allocate the BSTR.

## See also

[String Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/string-manipulation-functions)