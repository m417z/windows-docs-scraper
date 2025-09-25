# StringFromIID function

## Description

Converts an interface identifier into a string of printable characters.

## Parameters

### `rclsid` [in]

The interface identifier to be converted.

### `lplpsz` [out]

The address of a pointer variable that receives a pointer to the resulting string. The string that represents *rclsid* includes enclosing braces.

## Return value

This function can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

The caller is responsible for freeing the memory allocated for the string by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## See also

[IIDFromString](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iidfromstring)