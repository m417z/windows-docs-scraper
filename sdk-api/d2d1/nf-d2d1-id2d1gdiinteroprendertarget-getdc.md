# ID2D1GdiInteropRenderTarget::GetDC

## Description

Retrieves the device context associated with this render target.

## Parameters

### `mode`

Type: **[D2D1_DC_INITIALIZE_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_dc_initialize_mode)**

A value that specifies whether the device context should be cleared.

### `hdc` [out]

Type: **HDC***

When this method returns, contains the device context associated with this render target. You must allocate storage for this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

Calling this method flushes the render target.

This command can be called only after [BeginDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-begindraw) and before [EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw).

**Note** In Windows 7 and earlier, you should not call **GetDC** between [PushAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushaxisalignedclip(constd2d1_rect_f__d2d1_antialias_mode))/[PopAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-popaxisalignedclip) commands or between [PushLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushlayer(constd2d1_layer_parameters__id2d1layer))/[PopLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-poplayer). However, this restriction does not apply to Windows 8 and later.

[ReleaseDC](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1gdiinteroprendertarget-releasedc) must be called once for each call to **GetDC**.

## See also

[ID2D1GdiInteropRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1gdiinteroprendertarget)