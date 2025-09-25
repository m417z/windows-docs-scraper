# ID2D1DeviceContext::GetEffectRequiredInputRectangles

## Description

Returns the input rectangles that are required to be supplied by the caller to produce the given output rectangle.

## Parameters

### `renderEffect` [in]

Type: **[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)***

The image whose output is being rendered.

### `renderImageRectangle` [in, optional]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The portion of the output image whose inputs are being inspected.

### `inputDescriptions` [in]

Type: **const [D2D1_EFFECT_INPUT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_effect_input_description)***

A list of the inputs whose rectangles are being queried.

### `requiredInputRects` [out]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The input rectangles returned to the caller.

### `inputCount`

Type: **UINT32**

The number of inputs.

## Return value

Type: **HRESULT**

A failure code, this will typically only be because an effect in the chain returned some error.

## Remarks

The caller should be very careful not to place a reliance on the required input rectangles returned.
Small changes for correctness to an effect's behavior can result in different rectangles being returned.
In addition, different kinds of optimization applied inside the render can also influence the result.

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)