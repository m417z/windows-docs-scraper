# PFND3DKMT_OUTPUTDUPLPRESENTTOHWQUEUE callback function

## Description

Outputs duplicate of a handle to a hardware queue.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OUTPUTDUPLPRESENTTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputduplpresenttohwqueue) structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

PFND3DKMT_OUTPUTDUPLPRESENTTOHWQUEUE Pfnd3dkmtOutputduplpresenttohwqueue;

// Definition

NTSTATUS Pfnd3dkmtOutputduplpresenttohwqueue
(
	const D3DKMT_OUTPUTDUPLPRESENTTOHWQUEUE *
)
{...}

```

## Remarks

## See also