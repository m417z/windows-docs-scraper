# StringFromCLSID function

## Description

Converts a CLSID into a string of printable characters. Different CLSIDs always convert to different strings.

## Parameters

### `rclsid` [in]

The CLSID to be converted.

### `lplpsz` [out]

The address of a pointer variable that receives a pointer to the resulting string. The string that represents *rclsid* includes enclosing braces.

## Return value

This function can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

**StringFromCLSID** calls the [StringFromGUID2](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-stringfromguid2) function to convert a globally unique identifier (GUID) into a string of printable characters.

The caller is responsible for freeing the memory allocated for the string by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## See also

[CLSIDFromString](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-clsidfromstring)

[StringFromGUID2](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-stringfromguid2)