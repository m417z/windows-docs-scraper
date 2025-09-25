# ID2D1RenderInfo::SetOutputBuffer

## Description

Allows a caller to control the output precision and channel-depth of the transform in which the render information is encapsulated.

## Parameters

### `bufferPrecision`

Type: **[D2D1_BUFFER_PRECISION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_buffer_precision)**

The type of buffer that should be used as an output from this transform.

### `channelDepth`

Type: **[D2D1_CHANNEL_DEPTH](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_channel_depth)**

The number of channels that will be used on the output buffer.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

 If the output precision of the transform is not specified, then it will default to the precision specified on the Direct2D device context. The maximum of 16bpc **UNORM** and 16bpc **FLOAT** is 32bpc **FLOAT**.

The output channel depth will match the maximum of the input channel depths if the channel depth is **D2D1_CHANNEL_DEPTH_DEFAULT**.

There is no global output channel depth, this is always left to the control of the transforms.

## See also

[D2D1_BUFFER_PRECISION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_buffer_precision)

[D2D1_CHANNEL_DEPTH](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_channel_depth)

[ID2D1DeviceContext::SetRenderingControls](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-setrenderingcontrols(constd2d1_rendering_controls_))

[ID2D1RenderInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1renderinfo)