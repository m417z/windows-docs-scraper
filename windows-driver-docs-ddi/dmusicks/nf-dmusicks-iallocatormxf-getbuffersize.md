# IAllocatorMXF::GetBufferSize

## Description

The `GetBufferSize` method gets the buffer size from the allocator.

## Return value

`GetBufferSize` returns the size in bytes of the buffer.

## Remarks

`GetBufferSize` simply returns the size of the buffer that the allocator provides through the [IAllocatorMXF::GetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iallocatormxf-getbuffer) call. (For more information, see [IAllocatorMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iallocatormxf) introduction.) Because this is constant for any version of the port driver, `GetBufferSize` typically needs to be called only once, at the time that the stream is created.

## See also

[IAllocatorMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iallocatormxf)

[IAllocatorMXF::GetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iallocatormxf-getbuffer)