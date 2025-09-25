# SerializationBufferAllocate function

## Description

Exported memory allocation function for allocating a serialized buffer.

## Parameters

### `SizeInBytes` [in]

The size (in bytes) of the buffer to allocate.

### `pBuffer` [in/out]

Pointer to the buffer to allocate.

## Return value

This function returns the following NTSTATUS codes:

* STATUS_NO_MEMORY if there is no more memory.
* STATUS_SUCCESS on success.

## Remarks

## See also