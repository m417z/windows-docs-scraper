## Description

Informs the [Desktop Window Manager (DWM)](https://learn.microsoft.com/windows/win32/dwm/dwm-overview) whether alpha pixels in the texture should be honored or ignored.

## Parameters

### `alphaMode`

Type: \_In\_ **[DXGI_ALPHA_MODE](https://learn.microsoft.com/windows/win32/api/dxgi1_2/ne-dxgi1_2-dxgi_alpha_mode)**

Indicates whether alpha pixels in the texture should be honored or ignored.

| Value | Meaning |
| - | - |
| **DXGI_ALPHA_MODE_UNSPECIFIED** | The alpha channel isn't specified. This value has the same effect as **DXGI_ALPHA_MODE_IGNORE**. |
| **DXGI_ALPHA_MODE_PREMULTIPLIED** | The color channels contain values that are premultiplied with the alpha channel. |
| **DXGI_ALPHA_MODE_IGNORE** | The alpha channel should be ignored, and the bitmap should be rendered opaquely. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) error code.

## Remarks

## See also

* [IDCompositionTexture interface](https://learn.microsoft.com/windows/win32/api/dcomp/nn-dcomp-idcompositiontexture)