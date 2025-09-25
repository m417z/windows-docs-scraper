# StringFromGUID2 function

## Description

Converts a globally unique identifier (GUID) into a string of printable characters.

## Parameters

### `rguid` [in]

The GUID to be converted.

### `lpsz` [out]

 A pointer to a caller-allocated string variable to receive the resulting string. The string that represents *rguid* includes enclosing braces.

### `cchMax` [in]

The number of characters available in the *lpsz* buffer.

## Return value

If the function succeeds, the return value is the number of characters in the returned string, including the null terminator. If the buffer is too small to contain the string, the return value is 0.

## See also

[StringFromCLSID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-stringfromclsid)