# PFND3DKMT_QUERYVIDPNEXCLUSIVEOWNERSHIP callback function

## Description

The PFND3DKMT_QUERYVIDPNEXCLUSIVEOWNERSHIP callback function queries for VidPn exclusive ownership.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_QUERYVIDPNEXCLUSIVEOWNERSHIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryvidpnexclusiveownership) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_QUERYVIDPNEXCLUSIVEOWNERSHIP Pfnd3dkmtQueryvidpnexclusiveownership;

// Definition

NTSTATUS Pfnd3dkmtQueryvidpnexclusiveownership
(
	D3DKMT_QUERYVIDPNEXCLUSIVEOWNERSHIP *
)
{...}

```

## Remarks

## See also