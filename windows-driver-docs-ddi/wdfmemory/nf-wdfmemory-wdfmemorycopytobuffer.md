# WdfMemoryCopyToBuffer function

## Description

[Applies to KMDF and UMDF]

The **WdfMemoryCopyToBuffer** method copies the contents of a specified memory object's buffer into a specified destination buffer.

## Parameters

### `SourceMemory` [in]

A handle to a framework memory object that represents the source buffer.

### `SourceOffset` [in]

An offset, in bytes, from the beginning of the source buffer. The copy operation begins at the specified offset in the source buffer.

### `Buffer` [out]

A pointer to a destination buffer.

### `NumBytesToCopyTo` [in]

The number of bytes to copy from the source buffer to the destination buffer. This value must not be greater than the size of the source buffer.

## Return value

**WdfMemoryCopyToBuffer** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_BUFFER_TOO_SMALL** | The byte offset that the *SourceOffset* parameter specified was too large, or the *NumBytesToCopyTo* parameter was greater than the size of the source buffer. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The framework does not allow the driver to copy more bytes than the source buffer that the *SourceMemory* parameter specifies can contain.

For more information about framework memory objects, see [Using Memory Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-memory-buffers).

If the source or destination buffer was allocated from the pageable memory pool, the **WdfMemoryCopyToBuffer** method must be called at IRQL <= APC_LEVEL. Otherwise, the method can be called at any IRQL.

#### Examples

The following code example allocates a new buffer and copies the contents of a memory object's buffer into the new buffer.

```cpp
PVOID  pOutputBuffer = NULL;
NTSTATUS  status = STATUS_SUCCESS;

pOutputBuffer = ExAllocatePoolWithTag(
                                      NonPagedPool,
                                      MY_BUFFER_LENGTH,
                                      MY_POOL_TAG
                                      );
if (pOutputBuffer != NULL){
    status = WdfMemoryCopyToBuffer(
                                   outputMemoryHandle,
                                   0,
                                   pOutputBuffer,
                                   MY_BUFFER_LENGTH
                                   );
}
else{
    status = STATUS_INSUFFICIENT_RESOURCES;
}
```

## See also

[WdfMemoryCopyFromBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycopyfrombuffer)