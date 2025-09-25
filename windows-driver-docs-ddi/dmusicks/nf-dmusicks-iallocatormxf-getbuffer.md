# IAllocatorMXF::GetBuffer

## Description

The `GetBuffer` method allocates a buffer for long MIDI events.

## Parameters

### `ppBuffer` [out]

Output pointer for the buffer. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the buffer.

## Return value

`GetBuffer` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The miniport driver calls this method only when it needs to send large chunks of data to the capture sink. Specifically, the miniport driver uses this method whenever a component needs to package more data than can be stored in the **uData** member of [DMUS_KERNEL_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/ns-dmusicks-_dmus_kernel_event).

The size of the buffer can determined by calling [IAllocatorMXF::GetBufferSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iallocatormxf-getbuffersize). `GetBufferSize` needs to be called only once because the buffer size is constant for any allocator implementation.

## See also

[DMUS_KERNEL_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/ns-dmusicks-_dmus_kernel_event)

[IAllocatorMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iallocatormxf)

[IAllocatorMXF::GetBufferSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iallocatormxf-getbuffersize)