## Description

Provides data for calls to [ID3D11VideoDevice2::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d11_4/nf-d3d11_4-id3d11videodevice2-checkfeaturesupport) when the feature specified is [D3D11_FEATURE_VIDEO_DECODER_HISTOGRAM](https://learn.microsoft.com/windows/win32/api/d3d11_4/ne-d3d11_4-d3d11_feature_video). Retrieves the histogram capabilities for the specified decoder configuration.

## Members

### `DecoderDesc`

A [D3D11_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_video_decoder_desc) structure containing the decoder description for the decoder to be used with decode histogram.

### `Components`

A bitwise OR combination of values from the [D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d11_4/ne-d3d11_4-d3d11_video_decoder_histogram_component_flags) enumeration specifying the components of a DXGI_FORMAT for which histogram support will be queried.

### `BinCount`

The number of per component bins supported. This value must be greater than or equal to 64 and must be a power of 2 (e.g. 64, 128, 256, 512...).

### `CounterBitDepth`

The bit depth of the bin counter. The counter is always stored in a 32-bit value and therefore this value must specify 32 bits or less. The counter is stored in the lower bits of the 32-bit storage. The upper bits are set to zero. If the bin count exceeds this bit depth, the value is set to the maximum counter value. Valid values for *CounterBitDepth* are 16, 24, and 32.

## Remarks

## See also

[ID3D11VideoDevice2::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d11_4/nf-d3d11_4-id3d11videodevice2-checkfeaturesupport)