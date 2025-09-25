# _WDFMEMORY_OFFSET structure (wdfmemory.h)

## Description

[Applies to KMDF and UMDF]

The **WDFMEMORY_OFFSET** structure identifies a subsection of a memory object's buffer.

## Members

### `BufferOffset`

A byte offset from the beginning of the memory object's buffer. This offset identifies the location of the buffer's subsection. A value of zero represents the beginning of the buffer.

### `BufferLength`

The length, in bytes, of the buffer's subsection. A value of zero represents the entire buffer.

## Remarks

The **WDFMEMORY_OFFSET** structure is used as a member of the [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure and as an input parameter to various I/O target object methods.

## See also

[WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor)