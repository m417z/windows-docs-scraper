# SysAllocStringByteLen function

## Description

Takes an ANSI string as input, and returns a BSTR that contains an ANSI string. Does not perform any ANSI-to-Unicode translation.

## Parameters

### `psz` [in, optional]

The string to copy, or NULL to keep the string uninitialized.

### `len` [in]

The number of bytes to copy. A null character is placed afterwards, allocating a total of *len* plus the size of **OLECHAR** bytes.

## Return value

A copy of the string, or NULL if there is insufficient memory to complete the operation.

## Remarks

This function is provided to create BSTRs that contain binary data. You can use this type of BSTR only in situations where it will not be translated from ANSI to Unicode, or vice versa.

For example, do not use these BSTRs between a 16-bit and a 32-bit application running on a 32-bit Windows system. The OLE 16-bit to 32-bit (and 32-bit to 16-bit) interoperability layer will translate the BSTR and corrupt the binary data. The preferred method of passing binary data is to use a SAFEARRAY of VT_UI1, which will not be translated by OLE.

If psz is Null, a string of the requested length is allocated, but not initialized. The string psz can contain embedded null characters, and does not need to end with a Null. Free the returned string later with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## See also

[String Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/string-manipulation-functions)