# PFND3DKMT_SETHWPROTECTIONTEARDOWNRECOVERY callback function

## Description

The PFND3DKMT_SETHWPROTECTIONTEARDOWNRECOVERY callback function sets the hardware protection tear down recovery.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETHWPROTECTIONTEARDOWNRECOVERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_sethwprotectionteardownrecovery) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETHWPROTECTIONTEARDOWNRECOVERY Pfnd3dkmtSethwprotectionteardownrecovery;

// Definition

NTSTATUS Pfnd3dkmtSethwprotectionteardownrecovery
(
	D3DKMT_SETHWPROTECTIONTEARDOWNRECOVERY *
)
{...}

```

## Remarks

## See also