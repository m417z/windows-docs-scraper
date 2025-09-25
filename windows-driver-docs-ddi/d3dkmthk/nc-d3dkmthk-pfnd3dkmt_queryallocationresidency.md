# PFND3DKMT_QUERYALLOCATIONRESIDENCY callback function

## Description

The PFND3DKMT_QUERYALLOCATIONRESIDENCY callback function retrieves the residency status of a resource or list of allocations.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_QUERYALLOCATIONRESIDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryallocationresidency) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_QUERYALLOCATIONRESIDENCY Pfnd3dkmtQueryallocationresidency;

// Definition

NTSTATUS Pfnd3dkmtQueryallocationresidency
(
	const D3DKMT_QUERYALLOCATIONRESIDENCY *
)
{...}

```

## Remarks

## See also