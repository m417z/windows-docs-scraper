# ID2D1ConcreteTransform::SetOutputBuffer

## Description

Sets the properties of the output buffer of the specified transform node.

## Parameters

### `bufferPrecision`

Type: **[D2D1_BUFFER_PRECISION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_buffer_precision)**

The number of bits and the type of the output buffer.

### `channelDepth`

Type: **[D2D1_CHANNEL_DEPTH](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_channel_depth)**

The number of channels in the output buffer (1 or 4).

## Return value

Type: **HRESULT**

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_INVALIDARG | One or more arguments are not valid |

## Remarks

You can use the [ID2D1EffectContext::IsBufferPrecisionSupported](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-isbufferprecisionsupported) method to see if buffer precision is supported.

The available channel depth and precision depend on the capabilities of the underlying Microsoft Direct3D device.

## See also

[D2D1_BUFFER_PRECISION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_buffer_precision)

[D2D1_CHANNEL_DEPTH](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_channel_depth)

[ID2D1ConcreteTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1concretetransform)