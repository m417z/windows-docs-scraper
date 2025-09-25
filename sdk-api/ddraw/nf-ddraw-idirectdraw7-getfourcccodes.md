# IDirectDraw7::GetFourCCCodes

## Description

Retrieves the four-character codes (FOURCC) that are supported by the DirectDraw object. This method can also retrieve the number of codes that are supported.

## Parameters

### `unnamedParam1` [in, out]

A pointer to a variable that contains the number of entries that the array specified by *lpCodes* can hold. If the number of entries is too small to accommodate all the codes, *lpNumCodes* is set to the required number, and the array specified by *lpCodes* is filled with all that fits.

### `unnamedParam2` [in, out]

An array of variables to be filled with FOURCCs that are supported by this DirectDraw object. If you specify NULL, *lpNumCodes* is set to the number of supported FOURCCs, and the method returns.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)