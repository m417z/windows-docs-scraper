# IDirect3D9::GetAdapterDisplayMode

## Description

Retrieves the current display mode of the adapter.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number that denotes the display adapter to query. D3DADAPTER_DEFAULT is always the primary display adapter.

### `pMode` [in, out]

Type: **[D3DDISPLAYMODE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymode)***

Pointer to a [D3DDISPLAYMODE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymode) structure, to be filled with information describing the current adapter's mode.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.

If Adapter is out of range or pMode is invalid, this method returns D3DERR_INVALIDCALL.

## Remarks

**GetAdapterDisplayMode** will not return the correct format when the display is in an extended format, such as 2:10:10:10. Instead, it returns the format X8R8G8B8.

## See also

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)