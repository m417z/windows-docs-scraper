# PINT10_READ_MEMORY callback function

## Description

The *Int10ReadMemory* function reads a block of memory in the context of another thread and stores it in an output buffer.

## Parameters

### `Context` [in]

Pointer to a video port driver-defined context for the interface. This should be the same as the value in the **Context** member of the [VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface) structure after [VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices) returns.

### `Seg` [in]

Specifies the segment address of the buffer to be read.

### `Off` [in]

Specifies the offset within the segment indicated by the *Seg* parameter.

### `Buffer` [out]

Pointer to a memory location that indicates the beginning of the output buffer.

### `Length` [in]

Is the length, in bytes, of the output buffer specified by the *Buffer* parameter.

## Return value

The *Int10ReadMemory* function returns NO_ERROR upon success. Otherwise it returns an appropriate error code.

## Remarks

The video port implements this function, which can be accessed through a pointer in the [VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface) structure.

## See also

[VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface)