# PINT10_WRITE_MEMORY callback function

## Description

The *Int10WriteMemory* function writes the contents of an input buffer to memory in the context of another thread.

## Parameters

### `Context` [in]

Pointer to a video port driver-defined context for the interface. This should be the same as the value in the **Context** member of the [VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface) structure after [VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices) returns.

### `Seg` [in]

Specifies the segment address of the buffer to be written.

### `Off` [in]

Specifies the offset within the segment indicated by the *Seg* parameter.

### `Buffer` [in]

Pointer to the memory location that marks the beginning of the input buffer.

### `Length` [in]

Is the length, in bytes, of the input buffer specified by the *Buffer* parameter.

## Return value

The *Int10WriteMemory* function returns NO_ERROR upon success. Otherwise it returns an appropriate error code.

## Remarks

The video port implements this function, which can be accessed through a pointer in the [VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface) structure.

## See also

[VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface)