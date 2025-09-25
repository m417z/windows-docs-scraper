# ID2D1DeviceContext::InvalidateEffectInputRectangle

## Description

This indicates that a portion of an effect's input is invalid. This method can
be called many times.

You can use this method to propagate invalid rectangles through an effect graph. You can query Direct2D using the [GetEffectInvalidRectangles](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-geteffectinvalidrectangles) method.

**Note** Direct2D does not automatically use these invalid rectangles to reduce the region of an effect that is rendered.

You can also use this method to invalidate caches that have accumulated while rendering effects that have the **D2D1_PROPERTY_CACHED** property set to true.

## Parameters

### `effect` [in]

Type: **[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)***

The effect to invalidate.

### `input`

Type: **UINT32**

The input index.

### `inputRectangle` [in]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The rect to invalidate.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)