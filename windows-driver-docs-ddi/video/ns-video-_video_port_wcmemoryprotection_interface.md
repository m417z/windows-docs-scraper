# _VIDEO_PORT_WCMEMORYPROTECTION_INTERFACE structure

## Description

The VIDEO_PORT_WCMEMORYPROTECTION_INTERFACE structure describes the Write Combined video memory protection service routines implemented by the video port driver. The protected video memory cannot be accessed by the CPU.

## Members

### `Size`

Specifies the size in bytes of this structure.

### `Version`

Specifies the version of the interface to be returned by the miniport driver. The current interface version is defined in *video.h*, and has the form VIDEO_PORT_WCMEMORYPROTECTION_INTERFACE_VERSION_*N*.

### `Context`

Pointer to a miniport driver-defined context for the interface.

### `InterfaceReference`

Pointer to the video port driver-implemented reference routine for this interface.

### `InterfaceDereference`

Pointer to the video port driver-implemented dereference routine for this interface.

### `VideoPortProtectWCMemory`

Pointer to the video port driver's [VideoPortProtectWCMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-protect_wc_memory) callback routine.

### `VideoPortRestoreWCMemory`

Pointer to the video port driver's [VideoPortRestoreWCMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-restore_wc_memory) callback routine.

## See also

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[VideoPortProtectWCMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-protect_wc_memory)

[VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices)

[VideoPortRestoreWCMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-restore_wc_memory)