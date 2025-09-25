# PFND3DKMT_DESTROYPAGINGQUEUE callback function

## Description

The PFND3DKMT_DESTROYPAGINGQUEUE callback function destroys paging queue.

## Parameters

### `unnamedParam1`

Pointer to a [D3DDDI_DESTROYPAGINGQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_destroypagingqueue) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_DESTROYPAGINGQUEUE Pfnd3dkmtDestroypagingqueue;

// Definition

NTSTATUS Pfnd3dkmtDestroypagingqueue
(
	D3DDDI_DESTROYPAGINGQUEUE *
)
{...}

```