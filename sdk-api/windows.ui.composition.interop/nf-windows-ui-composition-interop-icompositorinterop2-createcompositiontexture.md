## Description

Creates a composition texture referencing the passed-in Direct3D texture.

## Parameters

### `d3dTexture`

Type: \_In\_ **[IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)\***

A Direct3D texture (an [ID3D11Texture2D](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11texture2d) resource) to create a composition texture for.

### `compositionTexture`

Type: \_In\_ **[IDCompositionTexture](https://learn.microsoft.com/windows/win32/api/windows.ui.composition.interop/nn-dcomp-idcompositiontexture)\*\***

Retrieves the composition texture object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) error code. If you try to create a composition texture for a Direct3D texture that's backed by a Direct3D device that doesn't support composition textures, then **CreateCompositionTexture** returns **E_INVALIDARG**.

## Remarks

## See also

* [ICompositorInterop2 interface](https://learn.microsoft.com/windows/win32/api/windows.ui.composition.interop/nn-windows-ui-composition-interop-icompositorinterop2)