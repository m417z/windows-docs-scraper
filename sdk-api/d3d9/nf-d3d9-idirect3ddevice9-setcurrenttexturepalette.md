# IDirect3DDevice9::SetCurrentTexturePalette

## Description

Sets the current texture palette.

## Parameters

### `PaletteNumber` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value that specifies the texture palette to set as the current texture palette.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

A single logical palette is associated with the device, and is shared by all texture stages.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetCurrentTexturePalette](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getcurrenttexturepalette)

[Texture Palettes (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/texture-palettes)