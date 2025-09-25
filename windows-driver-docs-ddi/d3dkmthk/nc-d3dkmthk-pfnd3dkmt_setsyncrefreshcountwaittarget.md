# PFND3DKMT_SETSYNCREFRESHCOUNTWAITTARGET callback function

## Description

The PFND3DKMT_SETSYNCREFRESHCOUNTWAITTARGET callback function sets sync refresh count for wait target.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETSYNCREFRESHCOUNTWAITTARGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setsyncrefreshcountwaittarget) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETSYNCREFRESHCOUNTWAITTARGET Pfnd3dkmtSetsyncrefreshcountwaittarget;

// Definition

NTSTATUS Pfnd3dkmtSetsyncrefreshcountwaittarget
(
	const D3DKMT_SETSYNCREFRESHCOUNTWAITTARGET *
)
{...}

```

## Remarks

## See also