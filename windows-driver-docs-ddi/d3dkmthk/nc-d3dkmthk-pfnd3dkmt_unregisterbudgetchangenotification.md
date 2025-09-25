# PFND3DKMT_UNREGISTERBUDGETCHANGENOTIFICATION callback function

## Description

The PFND3DKMT_UNREGISTERBUDGETCHANGENOTIFICATION callback function unregisters budget change notification.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_UNREGISTERBUDGETCHANGENOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_unregisterbudgetchangenotification) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_UNREGISTERBUDGETCHANGENOTIFICATION Pfnd3dkmtUnregisterbudgetchangenotification;

// Definition

NTSTATUS Pfnd3dkmtUnregisterbudgetchangenotification
(
	D3DKMT_UNREGISTERBUDGETCHANGENOTIFICATION *
)
{...}

```

## Remarks

## See also