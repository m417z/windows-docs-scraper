# IBrowserService::GetPalette

## Description

Deprecated. Retrieves the browser's palette.

## Parameters

### `hpal` [out]

Type: **HPALETTE***

A pointer to the browser's palette handle, if one exists.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or E_FAIL if there is no palette.

## Remarks

The calling application should not call [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) on the palette handle retrieved in *hpal*.