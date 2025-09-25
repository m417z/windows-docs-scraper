# ID2D1EffectContext::CreateBoundsAdjustmentTransform

## Description

Creates and returns a bounds adjustment transform.

## Parameters

### `outputRectangle` [in]

Type: **const [D2D1_RECT_L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847950(v=vs.85))***

The initial output rectangle for the bounds adjustment transform.

### `transform` [out]

Type: **[ID2D1BoundsAdjustmentTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1boundsadjustmenttransform)****

The returned bounds adjustment transform.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## Remarks

A support transform can be used for two different reasons.

* To indicate that a region of its input image is already transparent black. This can increase efficiency for rendering bitmaps.

  **Note** If the indicated region does NOT contain only transparent black pixels, then rendering results are undefined.
* To increase the size of the input image. The expanded area will be treated as transparent black

## See also

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)