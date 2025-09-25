# CollectionsListAllocateBufferAndSerialize function

## Description

This routine allocates a buffer and then serializes a sensor collection list to it. On success, callers must use [SerializationBufferFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsutils/nf-sensorsutils-serializationbufferfree) to free the buffer.

## Parameters

### `SourceCollection` [in]

Pointer to a collection list.

### `pTargetBufferSizeInBytes` [out]

The allocated buffer size (in bytes).

### `pTargetBuffer` [out]

Pointer to the allocated buffer, to hold the serialized data.

## Return value

This function returns NTSTATUS.

## Remarks

## See also