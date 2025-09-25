# IActiveDesktop::SetPattern

## Description

Sets the Active Desktop pattern.

## Parameters

### `pwszPattern` [in]

Type: **PCWSTR**

The address of a string value that contains a string of decimals whose bit pattern represents a picture. Each decimal represents the on/off state of the 8 pixels in that row.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)