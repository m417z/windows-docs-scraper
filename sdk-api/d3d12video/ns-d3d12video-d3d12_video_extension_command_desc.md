## Description

Describes a video extension command.

## Members

### `NodeMask`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `CommandId`

The unique identifier for the video extension command.

## Remarks

Pass this structure to [ID3D12VideoDevice2::CreateVideoExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice2-createvideoextensioncommand) to create an instance of [ID3D12VideoExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoextensioncommand).

## See also