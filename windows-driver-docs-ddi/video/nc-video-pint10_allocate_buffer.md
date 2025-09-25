# PINT10_ALLOCATE_BUFFER callback function

## Description

The *Int10AllocateBuffer* function can be used to allocate a single 4 KB block of memory in the context of another thread. After the block of memory has been allocated, it must be freed before another block of memory can be allocated.

## Parameters

### `Context` [in]

Pointer to a video port driver-defined context for the interface. This should be the same as the value in the **Context** member of the [VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface) structure after [VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices) returns.

### `Seg` [out]

Pointer to a memory location that will receive the segment address of the allocated memory buffer.

### `Off` [out]

Pointer to a memory location that will receive the offset within the segment specified by **Seg*, of the allocated memory buffer.

### `Length` [in, out]

Pointer to a memory location that contains the length, in bytes, of the requested memory buffer, which can be as large as 4096. When the function returns, this memory location will contain the value 4096, whether the memory was actually allocated.

## Return value

The *Int10AllocateBuffer* function returns NO_ERROR upon success. It returns STATUS_INSUFFICIENT_RESOURCES if the buffer has been allocated previously or if a buffer size larger than 4096 bytes is requested.

## Remarks

The video port implements this function, which can be accessed through a pointer in the [VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface) structure.

## See also

[VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface)