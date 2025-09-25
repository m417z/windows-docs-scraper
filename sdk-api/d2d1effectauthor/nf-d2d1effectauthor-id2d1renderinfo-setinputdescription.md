# ID2D1RenderInfo::SetInputDescription

## Description

Sets how a specific input to the transform should be handled by the renderer in terms of sampling.

## Parameters

### `inputIndex`

Type: **UINT32**

The index of the input that will have the input description applied.

### `inputDescription`

Type: **[D2D1_INPUT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_input_description)**

The description of the input to be applied to the transform.

## Return value

Type: **HRESULT**

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## Remarks

The input description must be matched correctly by the effect shader code.

## See also

[D2D1_BUFFER_PRECISION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_buffer_precision)

[D2D1_CHANNEL_DEPTH](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_channel_depth)

[ID2D1DeviceContext::SetRenderingControls](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-setrenderingcontrols(constd2d1_rendering_controls_))

[ID2D1RenderInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1renderinfo)