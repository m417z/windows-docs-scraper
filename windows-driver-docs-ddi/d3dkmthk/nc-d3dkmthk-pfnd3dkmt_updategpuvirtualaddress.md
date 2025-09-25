# PFND3DKMT_UPDATEGPUVIRTUALADDRESS callback function

## Description

The PFND3DKMT_UPDATEGPUVIRTUALADDRESS callback function allows the driver to specify a number of mapping operations to be applied to the process virtual address space in a single batch of page table updates.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_UPDATEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_updategpuvirtualaddress) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_UPDATEGPUVIRTUALADDRESS Pfnd3dkmtUpdategpuvirtualaddress;

// Definition

NTSTATUS Pfnd3dkmtUpdategpuvirtualaddress
(
	const D3DKMT_UPDATEGPUVIRTUALADDRESS *
)
{...}

```

## Remarks

## See also