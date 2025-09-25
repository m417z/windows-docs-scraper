## Description

Creates a new [ID2D1SolidColorBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1solidcolorbrush) that has the specified color and opacity.

## Parameters

### `color`

Type: [in] **const [D2D1_COLOR_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-color-f) &**

The red, green, blue, and alpha values of the brush's color.

### `brushProperties`

Type: [in] **const [D2D1_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_brush_properties) &**

The base opacity of the brush.

### `solidColorBrush`

Type: [out] **[ID2D1SolidColorBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1solidcolorbrush)****

When this method returns, contains the address of a pointer to the new brush. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview)

[Direct2D QuickStart](https://learn.microsoft.com/windows/win32/Direct2D/getting-started-with-direct2d)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)