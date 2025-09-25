# D3D12DDIARG_CREATE_VIDEO_DECODER_0032 structure

## Description

Used to create a decoder object for a decode session. The decoder holds state for a decode session, but references any significant allocations from the video decoder heap.

## Members

### `NodeMask`

Represents the set of nodes. For a single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Configuration`

The decode profile and bitstream encryption. See [D3D12DDI_VIDEO_DECODE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_configuration_0020).