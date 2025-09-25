# IDirect3DDevice9::GetCurrentTexturePalette

## Description

Retrieves the current texture palette.

## Parameters

### `PaletteNumber` [out, retval]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a returned value that identifies the current texture palette.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be: D3DERR_INVALIDCALL.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetCurrentTexturePalette](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setcurrenttexturepalette)

[Texture Palettes (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/texture-palettes)