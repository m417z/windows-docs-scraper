# IWICPalette::InitializeCustom

## Description

Initializes a palette to the custom color entries provided.

## Parameters

### `pColors` [in]

Type: **WICColor***

Pointer to the color array.

### `cCount` [in]

Type: **UINT**

The number of colors in *pColors*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If a transparent color is required, provide it as part of the custom entries. To add a transparent value to the palette, its alpha value must be 0 (0x00RRGGBB).

The entry count is limited to 256.