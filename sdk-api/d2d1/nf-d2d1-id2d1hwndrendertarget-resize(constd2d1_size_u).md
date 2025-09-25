## Description

Changes the size of the render target to the specified pixel size.

## Parameters

### `pixelSize`

Type: [in] **const [D2D1_SIZE_U](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-size-u)***

The new size of the render target in device pixels.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

After this method is called, the contents of the render target's back-buffer are not defined, even if the [D2D1_PRESENT_OPTIONS_RETAIN_CONTENTS](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_present_options) option was specified when the render target was created.

## See also

[ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget)