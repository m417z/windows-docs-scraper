# IDirect3DDevice9::GetPaletteEntries

## Description

Retrieves palette entries.

## Parameters

### `PaletteNumber` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An ordinal value identifying the particular palette to retrieve.

### `pEntries` [in, out]

Type: **[PALETTEENTRY](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-paletteentry)***

Pointer to a [PALETTEENTRY](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-paletteentry) structure, representing the returned palette entries.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

For more information about [PALETTEENTRY](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-paletteentry), see the Platform SDK.

**Note** As of Direct3D 9, the peFlags member of the [PALETTEENTRY](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-paletteentry) structure does not work the way it is documented in the Platform SDK. The peFlags member is now the alpha channel for 8-bit palettized formats.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetCurrentTexturePalette](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getcurrenttexturepalette)

[IDirect3DDevice9::SetCurrentTexturePalette](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setcurrenttexturepalette)

[IDirect3DDevice9::SetPaletteEntries](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setpaletteentries)

[Texture Palettes (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/texture-palettes)