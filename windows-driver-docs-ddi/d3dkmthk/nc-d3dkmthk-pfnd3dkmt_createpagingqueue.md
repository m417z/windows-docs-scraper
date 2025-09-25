# PFND3DKMT_CREATEPAGINGQUEUE callback function

## Description

The PFND3DKMT_CREATEPAGINGQUEUE callback function creates a paging queue.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_CREATEPAGINGQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createpagingqueue) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_CREATEPAGINGQUEUE Pfnd3dkmtCreatepagingqueue;

// Definition

NTSTATUS Pfnd3dkmtCreatepagingqueue
(
	D3DKMT_CREATEPAGINGQUEUE *
)
{...}

```