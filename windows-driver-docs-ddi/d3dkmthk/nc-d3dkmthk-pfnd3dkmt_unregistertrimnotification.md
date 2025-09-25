# PFND3DKMT_UNREGISTERTRIMNOTIFICATION callback function

## Description

PFND3DKMT_UNREGISTERTRIMNOTIFICATION callback function removes a callback registration for a kernel mode device receiving notifications from a graphics framework (such as OpenGL).

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_UNREGISTERTRIMNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_unregistertrimnotification) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_UNREGISTERTRIMNOTIFICATION Pfnd3dkmtUnregistertrimnotification;

// Definition

NTSTATUS Pfnd3dkmtUnregistertrimnotification
(
	D3DKMT_UNREGISTERTRIMNOTIFICATION *
)
{...}

```

## Remarks

## See also