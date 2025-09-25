# D3D12DDI_VIDEO_EXTENSION_COMMAND_INFO_0063 structure

## Description

Describes an extension.

## Members

### `CommandId`

The unique identifier for the video extension command.

### `Name`

Pointer to a wide string, driver allocates and keep for the lifetime of the device.

### `CommandQueueFlags`

Indicates the Video Command Queue that the video extension targets. Only one of the following bits may be set:

* D3D12DDI_COMMAND_QUEUE_FLAG_0022_VIDEO_DECODE
* D3D12DDI_COMMAND_QUEUE_FLAG_0022_VIDEO_PROCESS
* D3D12DDI_COMMAND_QUEUE_FLAG_0053_VIDEO_ENCODE

## Remarks

## See also