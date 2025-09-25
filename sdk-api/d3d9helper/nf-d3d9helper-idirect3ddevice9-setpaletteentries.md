# IDirect3DDevice9::SetPaletteEntries

## Description

Sets palette entries.

## Parameters

### `PaletteNumber` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An ordinal value identifying the particular palette upon which the operation is to be performed.

### `pEntries` [in]

Type: **const [PALETTEENTRY](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-paletteentry)***

Pointer to a [PALETTEENTRY](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-paletteentry) structure, representing the palette entries to set. The number of **PALETTEENTRY** structures pointed to by pEntries is assumed to be 256. See Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

For Direct3D 9 applications, any palette sent to this method must conform to the D3DPTEXTURECAPS_ALPHAPALETTE capability bit of the [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure. If D3DPTEXTURECAPS_ALPHAPALETTE is not set, every entry in the palette must have alpha set to 1.0 or this method will fail with D3DERR_INVALIDCALL. If D3DPTEXTURECAPS_ALPHAPALETTE is set, then any set of alpha values are allowed. Note that the debug runtime will print a warning message if all palette entries have alpha set to 0.

A single logical palette is associated with the device, and is shared by all texture stages.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetCurrentTexturePalette](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getcurrenttexturepalette)

[IDirect3DDevice9::GetPaletteEntries](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getpaletteentries)

[IDirect3DDevice9::SetCurrentTexturePalette](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setcurrenttexturepalette)

[Texture Palettes (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/texture-palettes)