# ID2D1EffectContext::CreateBorderTransform

## Description

Creates a transform that extends its input infinitely in every direction based on the passed in extend mode.

## Parameters

### `extendModeX`

Type: **[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_extend_mode)**

The extend mode in the X-axis direction.

### `extendModeY`

Type: **[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_extend_mode)**

The extend mode in the Y-axis direction.

### `transform` [out]

Type: **[ID2D1BorderTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1bordertransform)****

The returned transform.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## See also

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)