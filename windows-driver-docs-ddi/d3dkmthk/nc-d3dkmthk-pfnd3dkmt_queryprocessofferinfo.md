# PFND3DKMT_QUERYPROCESSOFFERINFO callback function

## Description

The PFND3DKMT_QUERYPROCESSOFFERINFO callback function queries the process offer info.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_QUERYPROCESSOFFERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryprocessofferinfo) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_QUERYPROCESSOFFERINFO Pfnd3dkmtQueryprocessofferinfo;

// Definition

NTSTATUS Pfnd3dkmtQueryprocessofferinfo
(
	D3DKMT_QUERYPROCESSOFFERINFO *
)
{...}

```

## Remarks

## See also