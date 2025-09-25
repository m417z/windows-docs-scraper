# PROTECT_WC_MEMORY callback function

## Description

The *VideoPortProtectWCMemory* callback routine protects Write Combined (WC) video memory from being accessed by the CPU.

## Parameters

### `Context` [in]

Pointer to a caller-determined context parameter to be passed to the *CallbackRoutine*. It typically points to the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) buffer.

### `HwDeviceExtension` [in]

Pointer to the miniport driver's hardware device extension.

## Return value

*VideoPortProtectWCMemory* returns NO_ERROR if it successfully protects Write Combined video memory; otherwise, it returns an error status of ERROR_INVALID_FUNCTION or ERROR_NOT_ENOUGH_MEMORY.

## Remarks

After *VideoPortProtectWCMemory* is called, the CPU cannot write to Write Combined (WC) memory until the [VideoPortRestoreWCMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-restore_wc_memory) callback routine is called.

When WC memory protection is no longer required, the display miniport driver should call [VideoPortRestoreWCMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-restore_wc_memory) to restore CPU access to WC memory.

## See also

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortRestoreWCMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-restore_wc_memory)