# PINT10_FREE_BUFFER callback function

## Description

The *Int10FreeBuffer* function frees a buffer previously allocated by *Int10AllocateBuffer*.

## Parameters

### `Context` [in]

Pointer to a video port driver-defined context for the interface. This should be the same as the value in the **Context** member of the [VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface) structure after [VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices) returns.

### `Seg` [in]

Specifies the segment address of the buffer to be freed.

### `Off` [in]

Specifies the offset within the segment indicated by the *Seg* parameter.

## Return value

The *Int10FreeBuffer* function returns NO_ERROR upon success. Otherwise, the function returns an appropriate error code.

## Remarks

The video port implements this function, which can be accessed through a pointer in the [VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface) structure.

## See also

[VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface)