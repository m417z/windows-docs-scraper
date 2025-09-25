# ID2D1GdiInteropRenderTarget::ReleaseDC

## Description

Indicates that drawing with the device context retrieved using the [GetDC](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1gdiinteroprendertarget-getdc) method is finished.

## Parameters

### `update` [in, optional]

Type: **[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)***

The modified region of the device context, or **NULL** to specify the entire render target.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

**ReleaseDC** must be called once for each call to [GetDC](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1gdiinteroprendertarget-getdc).

## See also

[ID2D1GdiInteropRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1gdiinteroprendertarget)