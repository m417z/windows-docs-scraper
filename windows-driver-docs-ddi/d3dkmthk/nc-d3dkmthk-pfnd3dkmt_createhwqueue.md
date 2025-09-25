# PFND3DKMT_CREATEHWQUEUE callback function

## Description

Implemented by the client driver to create a new hardware queue.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_CREATEHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createhwqueue) structure that contains information needed to create a new hardware queue.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code.

## Prototype

```cpp
//Declaration

PFND3DKMT_CREATEHWQUEUE Pfnd3dkmtCreatehwqueue;

// Definition

NTSTATUS Pfnd3dkmtCreatehwqueue
(
	D3DKMT_CREATEHWQUEUE *
)
{...}

PFND3DKMT_CREATEHWQUEUE

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_CREATEHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createhwqueue) and then calling Pfnd3dkmtCreateHwQueue.