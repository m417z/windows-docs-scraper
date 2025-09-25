# D3D12DDI_VIDEO_DECODE_FORMAT_COUNT_DATA_0032 structure

## Description

Retrieves the number of formats supported for a given decode configuration.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `Configuration`

Specifies the decode configuration for the list of formats. See [D3D12DDI_VIDEO_DECODE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_configuration_0020) for more information.

### `FormatCount`

The count of formats supported for the given node and configuration.