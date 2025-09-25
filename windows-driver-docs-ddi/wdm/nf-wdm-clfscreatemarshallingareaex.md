# ClfsCreateMarshallingAreaEx function

## Description

Initializes a marshalling area for a physical or client log file stream.

## Parameters

### `plfoLog`

The handle associated with new marshalling area.

### `ePoolType`

Paged or non-paged pool buffers.

### `pfnAllocBuffer`

Optional. A pointer to the block allocation callback function.

### `pfnFreeBuffer`

Optional. A pointer to the block deallocation callback function.

### `cbMarshallingBuffer`

The size of marshalling buffers.

### `cMaxWriteBuffers`

The maximum number of allocated write buffers.

### `cMaxReadBuffers`

The maximum number of allocated read buffers.

### `cAlignmentSize`

The alignment size of marshalling buffers.

### `fFlags`

buffer management flag

### `ppvMarshalContext`

marshalling context

## Return value

This function returns CLFSUSER_API NTSTATUS.

## Remarks

## See also