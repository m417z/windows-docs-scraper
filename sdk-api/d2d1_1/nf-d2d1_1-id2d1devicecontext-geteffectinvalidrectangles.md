# ID2D1DeviceContext::GetEffectInvalidRectangles

## Description

Gets the invalid rectangles that have accumulated since the last time the effect was drawn and [EndDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) was then called on the device context.

## Parameters

### `effect` [in]

Type: **[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)***

The effect to get the invalid rectangles from.

### `rectangles` [out]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

An array of [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f) structures. You must allocate this to the correct size. You can get the count of the invalid rectangles using the [GetEffectInvalidRectangleCount](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-geteffectinvalidrectanglecount) method.

### `rectanglesCount` [in]

Type: **UINT32**

The number of rectangles to get.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## Remarks

**Note** Direct2D does not automatically use these invalid rectangles to reduce the region of an effect that is rendered.

You can use the [InvalidateEffectInputRectangle](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-invalidateeffectinputrectangle) method to specify invalidated rectangles for Direct2D to propagate through an effect graph.

If multiple invalid rectangles are requested, the rectangles that this method returns may overlap. When this is the case, the rectangle count might be lower than the count that [GetEffectInvalidRectangleCount](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-geteffectinvalidrectanglecount).

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)