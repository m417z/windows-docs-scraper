# PFND3DKMT_SETHYBRIDLISTVVALUE callback function

## Description

The PFND3DKMT_SETHYBRIDLISTVVALUE callback function sets the hybrid list value.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_HYBRID_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_hybrid_list) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETHYBRIDLISTVVALUE Pfnd3dkmtSethybridlistvvalue;

// Definition

NTSTATUS Pfnd3dkmtSethybridlistvvalue
(
	D3DKMT_HYBRID_LIST *
)
{...}

```

## Remarks

## See also