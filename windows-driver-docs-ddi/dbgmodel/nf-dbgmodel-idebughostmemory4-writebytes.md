## Description

Writes a number of bytes to the address space of the target as defined by the inpassed context and location.

The number of bytes written is returned in "bytesWritten" upon success.

## Parameters

### `context`

The host context in which to write bytes. This represents, for example, the address space in which the location exists.

### `location`

The location at which to write bytes. This location may represent a virtual address within the address space defined by context or it may represent something like a register within a context record for a thread.

### `buffer`

The bytes to write to the debug target.

### `bufferSize`

The size of the buffer / number of bytes to write to the debug target.

### `bytesWritten`

The number of bytes actually written to the debug target will be returned here. If the method can complete a partial write, S_FALSE will be returned and the value in bytesWritten may be less than the requested number of bytes. If the method returns S_OK, a full write was completed.

## Return value

This method returns HRESULT.

## Remarks

## See also

[IDebugHostMemory4 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmemory4)