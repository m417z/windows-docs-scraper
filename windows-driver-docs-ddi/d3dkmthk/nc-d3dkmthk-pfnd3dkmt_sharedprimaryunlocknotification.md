# PFND3DKMT_SHAREDPRIMARYUNLOCKNOTIFICATION callback function

## Description

The PFND3DKMT_SHAREDPRIMARYUNLOCKNOTIFICATION callback function notifies the operating system that a shared primary surface was unlocked.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SHAREDPRIMARYUNLOCKNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_sharedprimaryunlocknotification) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SHAREDPRIMARYUNLOCKNOTIFICATION Pfnd3dkmtSharedprimaryunlocknotification;

// Definition

NTSTATUS Pfnd3dkmtSharedprimaryunlocknotification
(
	const D3DKMT_SHAREDPRIMARYUNLOCKNOTIFICATION *
)
{...}

```

## Remarks

## See also