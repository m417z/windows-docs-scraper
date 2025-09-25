# PFND3DKMT_UPDATEALLOCATIONPROPERTY callback function

## Description

The PFND3DKMT_UPDATEALLOCATIONPROPERTY callback function updates allocation property of a context.

## Parameters

### `unnamedParam1`

Pointer to a [D3DDDI_UPDATEALLOCPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_updateallocproperty) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_UPDATEALLOCATIONPROPERTY Pfnd3dkmtUpdateallocationproperty;

// Definition

NTSTATUS Pfnd3dkmtUpdateallocationproperty
(
	D3DDDI_UPDATEALLOCPROPERTY *
)
{...}

```

## Remarks

## See also