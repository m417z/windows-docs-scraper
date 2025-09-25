# PFND3DKMT_REGISTERTRIMNOTIFICATION callback function

## Description

The PFND3DKMT_REGISTERTRIMNOTIFICATION callback function registers trim notifications.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_REGISTERTRIMNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_registertrimnotification) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_REGISTERTRIMNOTIFICATION Pfnd3dkmtRegistertrimnotification;

// Definition

NTSTATUS Pfnd3dkmtRegistertrimnotification
(
	D3DKMT_REGISTERTRIMNOTIFICATION *
)
{...}

```

## Remarks

## See also