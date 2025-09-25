# PFN_GET_NEXT_CHUNK_DATA callback function

## Description

Provides info about the next Miracast encode chunk that was reported to the Microsoft DirectX graphics kernel subsystem when the [DXGK_INTERRUPT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type) interrupt type is **DXGK_INTERRUPT_MICACAST_CHUNK_PROCESSING_COMPLETE**.The data type of this function is **PFN_GET_NEXT_CHUNK_DATA**.

## Parameters

### `hMiracastDeviceHandle` [in]

A handle that represents a Miracast device. The Miracast user-mode driver previously obtained this handle as the *hMiracastDeviceHandle* parameter in a call to the [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) function.

### `TimeoutInMilliseconds` [in]

The timeout interval value, in milliseconds, supplied by the Miracast user-mode driver.

If this value is **INFINITE**, the operating system blocks calls to **GetNextChunkData** until a chunk becomes available.

If this value is zero and a chunk is not ready, the operating system will not block a call to **GetNextChunkData**.

### `AdditionalWaitEventCount` [in]

The number of additional events that are supplied in the *pAdditionalWaitEvents* parameter.

A maximum of 4 wait events can be supplied.

### `pAdditionalWaitEvents` [in, optional]

An optional pointer to an array of events that **GetNextChunkData** will wait on while waiting for a new encode chunk.

### `pChunkDataBufferSize` [in, out]

A pointer to a variable that contains the size, in bytes, of the *pChunkDataBuffer* buffer.

When **GetNextChunkData** is called, this parameter contains the size of *pChunkDataBuffer*.

When **GetNextChunkData** returns a success code, this parameter contains the size of actual encode chunk data returned in *pChunkDataBuffer*.

### `pChunkDataBuffer` [out]

A pointer to a buffer of type [MIRACAST_CHUNK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_data) that the operating system provides to store information about the next encode chunk. This parameter is provided only if the call to **GetNextChunkData** is successful.

### `pOutstandingChunksToProcess` [out]

A pointer to a variable that contains the number of outstanding encode chunks that are available for the driver at the time this call returned. This parameter is provided only if the call to **GetNextChunkData** is successful.

Note that as chunks are completed by the GPU asynchronously, this parameter only gives an indication of the number of outstanding chunks.

## Return value

If info on an encode chunk was returned successfully, the **STATUS_SUCCESS** status code is returned, and the value of **pChunkDataBufferSize* is non-zero.

These additional status codes can be returned:

## Remarks

This function is optional. The user-mode display driver should only call it if the display miniport driver responds to interrupts from the GPU when the GPU completes the encoding of a chunk by passing data in the [MIRACAST_CHUNK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_data).**PrivateDriverData** member at that interrupt time.

The user-mode display driver can use the sizes of the [MIRACAST_CHUNK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_data) structure and the **MIRACAST_CHUNK_DATA**.**PrivateDriverData** member to compute the size of a chunk and hence how to move from chunk to chunk in the returned buffer.

In a call to this function, as many available packets as can fit will be placed sequentially in the supplied buffer. This code snippet shows how to calculate the size of each packet:

```cpp
ChunkSize == FIELD_OFFSET
    (D3DKMT_MIRACAST_CHUNK_DATA, PrivateDriverData) \
    + Chunk->ChunkData.PrivateDriverDataSize;
```

#### Thread Safety

Only one thread should call this function at a time. Otherwise it's unpredictable which call would receive chunk info and which call would fail.

## See also

[CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context)

[DXGK_INTERRUPT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type)

[MIRACAST_CHUNK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_data)