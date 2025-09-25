# SysAllocString function

## Description

Allocates a new string and copies the passed string into it.

## Parameters

### `psz` [in, optional]

The string to copy.

## Return value

If successful, returns the string. If *psz* is a zero-length string, returns a zero-length **BSTR**. If *psz* is NULL or insufficient memory exists, returns NULL.

## Remarks

You can free strings created with **SysAllocString** using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## See also

[String Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/string-manipulation-functions)