# WdfMemoryCopyFromBuffer function

## Description

[Applies to KMDF and UMDF]

The **WdfMemoryCopyFromBuffer** method copies the contents of a specified source buffer into a specified memory object's buffer.

## Parameters

### `DestinationMemory` [in]

A handle to a framework memory object that represents the destination buffer.

### `DestinationOffset` [in]

An offset, in bytes, from the beginning of the destination buffer. The copy operation begins at the specified offset in the destination buffer.

### `Buffer` [in]

A pointer to a source buffer.

### `NumBytesToCopyFrom` [in]

The number of bytes to copy from the source buffer to the destination buffer. This value must not be greater than the size of the source buffer.

## Return value

**WdfMemoryCopyFromBuffer** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INVALID_BUFFER_SIZE** | The byte offset that the *DestinationOffset* parameter specified was too large. |
| **STATUS_BUFFER_TOO_SMALL** | The size of the destination buffer that the *DestinationOffset* parameter specified, starting at the destination offset, was greater than the *NumBytesToCopyFrom* parameter. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The framework verifies that the destination buffer is large enough to receive the amount of data that the *NumBytesToCopyFrom* parameter specifies.

For more information about framework memory objects, see [Using Memory Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-memory-buffers).

If the source or destination buffer was allocated from the pageable memory pool, the **WdfMemoryCopyFromBuffer** method must be called at IRQL <= APC_LEVEL. Otherwise, the method can be called at any IRQL.

#### Examples

The following code example obtains a handle to the framework memory object that represents an I/O request's output buffer, and then it copies the contents of another buffer into the I/O request's output buffer.

```cpp
WDFMEMORY  memoryBuffer;
NTSTATUS  status;

status = WdfRequestRetrieveOutputMemory(
                                        Request,
                                        &memoryBuffer
                                        );
if (!NT_SUCCESS(status)) {
    goto Error;
}
status = WdfMemoryCopyFromBuffer(
                                 memoryBuffer,
                                 0,
                                 deviceContext->Buffer,
                                 Length
                                 );
if (!NT_SUCCESS(status)) {
    goto Error;
}
```

## See also

[WdfMemoryCopyToBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycopytobuffer)

[WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory)