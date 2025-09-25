# ID2D1EffectContext::CreateBlendTransform

## Description

This creates a blend transform that can be inserted into a transform graph.

## Parameters

### `numInputs`

Type: **UINT32**

The number of inputs to the blend transform.

### `blendDescription` [in]

Type: **const [D2D1_BLEND_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_blend_description)***

Describes the blend transform that is to be created.

### `transform` [out]

Type: **[ID2D1BlendTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1blendtransform)****

The returned blend transform.

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