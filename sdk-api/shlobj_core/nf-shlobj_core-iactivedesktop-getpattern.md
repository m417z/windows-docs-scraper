# IActiveDesktop::GetPattern

## Description

Gets the current pattern.

## Parameters

### `pwszPattern` [out]

Type: **PWSTR**

A pointer to a null-terminated, Unicode buffer containing a string of decimals whose bit pattern represents a picture. Each decimal represents the on/off state of the 8 pixels in that row.

### `cchPattern`

Type: **UINT**

The size of the *pwszPattern* string, in characters.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.