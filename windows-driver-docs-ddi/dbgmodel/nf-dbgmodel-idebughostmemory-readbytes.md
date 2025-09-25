# IDebugHostMemory::ReadBytes

## Description

Reads a number of bytes from the address space of the target as defined by the inpassed context and location.
The number of bytes read is returned in "bytesRead" upon success.

## Parameters

### `context`

The host context in which to read bytes. This represents, for example, the address space in which the location exists.

### `location`

The location at which to read bytes. This location may represent a virtual address within the address space defined by context or it may represent something like a register within a context record for a thread.

### `buffer`

The bytes read from the debug target will be written to this buffer.

### `bufferSize`

The size of the buffer and the number of bytes to read.

### `bytesRead`

The number of bytes actually read from the debug target will be returned here. If the method can complete a partial read, S_FALSE will be returned and the value in bytesRead may be less than the requested number of bytes. If the method returns S_OK, a full read was completed.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostMemory interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmemory)