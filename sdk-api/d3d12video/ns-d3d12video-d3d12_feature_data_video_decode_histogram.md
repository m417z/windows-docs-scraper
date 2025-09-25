# D3D12_FEATURE_DATA_VIDEO_DECODE_HISTOGRAM structure

## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12\_FEATURE\_VIDEO\_DECODE\_HISTOGRAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the histogram capabilities for the specified decoder configuration.

## Members

### `NodeIndex`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `DecodeProfile`

A GUID representing the decode profile for which histogram capabilities will be queried. Get a list of available profile GUIDs by calling [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12\_FEATURE\_VIDEO\_DECODE\_PROFILES](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

### `Width`

The decode width of the source stream.

### `Height`

The decode height of the source stream.

### `DecodeFormat`

The [DXGI\_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) representing the decode format.

### `Components`

A bitwise OR combination of values from the [D3D12_VIDEO_DECODE_HISTOGRAM_COMPONENT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_histogram_component_flags) enumeration specifying the components of a DXGI_FORMAT for which histogram support will be queried.

### `BinCount`

The number of per component bins supported. This value must be greater than or equal to 64 and must be a power of 2 (e.g. 64, 128, 256, 512...).

### `CounterBitDepth`

The bit depth of the bin counter. The counter is always stored in a 32-bit value and therefore this value must specify 32 bits or less. The counter is stored in the lower bits of the 32-bit storage. The upper bits are set to zero. If the bin count exceeds this bit depth, the value is set to the maximum counter value. Valid values for *CounterBitDepth* are 16, 24, and 32.

## Remarks

## See also