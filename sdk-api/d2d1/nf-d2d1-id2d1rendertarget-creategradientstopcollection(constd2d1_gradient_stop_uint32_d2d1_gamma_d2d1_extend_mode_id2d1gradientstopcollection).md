## Description

Creates an [ID2D1GradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1gradientstopcollection) from the specified array of [D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_gradient_stop) structures.

## Parameters

### `gradientStops`

Type: [in] **[D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_gradient_stop)***

A pointer to an array of [D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_gradient_stop) structures.

### `gradientStopsCount`

Type: [in] **UINT**

A value greater than or equal to 1 that specifies the number of gradient stops in the *gradientStops* array.

### `colorInterpolationGamma`

Type: [in] **D2D1_GAMMA**

The space in which color interpolation between the gradient stops is performed.

### `extendMode`

Type: [in] **D2D1_EXTEND_MODE**

The behavior of the gradient outside the [0,1] normalized range.

### `gradientStopCollection`

Type: [out] **[ID2D1GradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1gradientstopcollection)****

When this method returns, contains a pointer to a pointer to the new gradient stop collection.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview)

[D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_gradient_stop)

[How to Create a Linear Gradient Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-linear-gradient-brush)

[How to Create a Radial Gradient Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-radial-gradient-brush)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)