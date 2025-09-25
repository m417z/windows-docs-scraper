# ID2D1EffectContext::CreateOffsetTransform

## Description

Creates and returns an offset transform.

## Parameters

### `offset`

Type: **[D2D1_POINT_2L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847948(v=vs.85))**

The offset amount.

### `transform` [out]

Type: **[ID2D1OffsetTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1offsettransform)****

When this method returns, contains the address of a pointer to an offset transform object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## Remarks

An offset transform is used to offset an input bitmap without having to insert a rendering pass. An offset transform is automatically inserted by an Affine transform if the transform evaluates to a pixel-aligned transform.

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)