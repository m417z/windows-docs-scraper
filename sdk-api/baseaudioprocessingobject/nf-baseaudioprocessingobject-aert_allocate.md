# AERT_Allocate function

## Description

The `AERT_Allocate` utility function allocates and locks a segment of memory for use by audio processing objects.

## Parameters

### `size`

The number of bytes to allocate.

### `pMemory`

A pointer to the allocated memory.

## Return value

If the function successfully allocates the requested locked memory, the function returns a value of S_OK. The function returns a value of E_OUTOFMEMORY if it cannot find enough memory to allocate and lock.

## Remarks

None