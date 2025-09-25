# RESTORE_WC_MEMORY callback function

## Description

The *VideoPortRestoreWCMemory* callback routine restores Write Combined video memory from a protected state after the [VideoPortProtectWCMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-protect_wc_memory) callback routine was called.

## Parameters

### `Context` [in]

Pointer to a caller-determined context parameter to be passed to the *CallbackRoutine*. It typically points to the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) buffer.

### `HwDeviceExtension` [in]

Pointer to the miniport driver's hardware device extension.

## Return value

*VideoPortRestoreWCMemory* returns NO_ERROR if it successfully restored Write Combined video memory; otherwise, it returns an error status of ERROR_INVALID_FUNCTION or ERROR_NOT_ENOUGH_MEMORY.

## Remarks

After the [VideoPortProtectWCMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-protect_wc_memory) callback routine is called, the CPU cannot write to Write Combined memory until *VideoPortRestoreWCMemory* is called.

## See also

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortProtectWCMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-protect_wc_memory)