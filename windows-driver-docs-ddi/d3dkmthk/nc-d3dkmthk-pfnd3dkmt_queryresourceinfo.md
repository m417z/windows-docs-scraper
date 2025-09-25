# PFND3DKMT_QUERYRESOURCEINFO callback function

## Description

The PFND3DKMT_QUERYRESOURCEINFO callback function retrieves information about a shared resource.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_QUERYRESOURCEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryresourceinfo) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_QUERYRESOURCEINFO Pfnd3dkmtQueryresourceinfo;

// Definition

NTSTATUS Pfnd3dkmtQueryresourceinfo
(
	D3DKMT_QUERYRESOURCEINFO *
)
{...}

```

## Remarks

## See also