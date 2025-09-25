# _VIDEO_PORT_INT10_INTERFACE structure

## Description

The VIDEO_PORT_INT10_INTERFACE structure provides a way to allocate and deallocate memory in another thread's context, read from and write to that memory, and make INT10 BIOS calls.

## Members

### `Size`

Specifies the size in bytes of this structure.

### `Version`

Specifies the version of the interface to be returned by the video port driver. The current interface version is defined in *video.h* and has the form VIDEO_PORT_INT10_INTERFACE_*N*.

### `Context`

Pointer to a video port driver-defined context for the interface.

### `InterfaceReference`

Pointer to the video port driver-implemented reference routine for this interface.

### `InterfaceDereference`

Pointer to the video port driver-implemented dereference routine for this interface.

### `Int10AllocateBuffer`

Pointer to the video port driver-implemented [Int10AllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pint10_allocate_buffer) routine.

### `Int10FreeBuffer`

Pointer to the video port driver-implemented [Int10FreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pint10_free_buffer) routine.

### `Int10ReadMemory`

Pointer to the video port driver-implemented [Int10ReadMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pint10_read_memory) routine.

### `Int10WriteMemory`

Pointer to the video port driver-implemented [Int10WriteMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pint10_write_memory) routine.

### `Int10CallBios`

Pointer to the video port driver-implemented [Int10CallBios](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pint10_call_bios) routine.

## Remarks

PnP video miniport drivers that intend to make BIOS calls should fill in the **Size** and **Version** members of this structure, and then call [VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices), which initializes the remaining members of this structure.

## See also

[VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices)