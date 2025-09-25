# PFND3DKMT_SHAREDPRIMARYLOCKNOTIFICATION callback function

## Description

The PFND3DKMT_SHAREDPRIMARYLOCKNOTIFICATION callback function notifies the operating system about an upcoming lock to a shared primary surface.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SHAREDPRIMARYLOCKNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_sharedprimarylocknotification) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SHAREDPRIMARYLOCKNOTIFICATION Pfnd3dkmtSharedprimarylocknotification;

// Definition

NTSTATUS Pfnd3dkmtSharedprimarylocknotification
(
	const D3DKMT_SHAREDPRIMARYLOCKNOTIFICATION *
)
{...}

```

## Remarks

## See also