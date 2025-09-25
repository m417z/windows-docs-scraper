## Description

Specifies the portion of an overall Direct3D texture that the composition texture represents (and samples from). This allows you to have multiple composition textures referencing the same Direct3D texture.

## Parameters

### `sourceRect`

Type: \_In\_ **[D2D_RECT_U](https://learn.microsoft.com/windows/win32/api/dcommon/ns-dcommon-d2d_rect_u)\&**

The region of a Direct3D texture that the composition texture represents.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) error code.

## Remarks

## See also

* [IDCompositionTexture interface](https://learn.microsoft.com/windows/win32/api/dcomp/nn-dcomp-idcompositiontexture)
* [IDCompositionTexture::GetAvailableFence](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositiontexture-getavailablefence)