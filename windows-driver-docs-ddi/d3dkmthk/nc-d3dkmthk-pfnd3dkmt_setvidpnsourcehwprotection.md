# PFND3DKMT_SETVIDPNSOURCEHWPROTECTION callback function

## Description

The PFND3DKMT_SETVIDPNSOURCEHWPROTECTION callback function sets VidPn source hardware protection.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETVIDPNSOURCEHWPROTECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourcehwprotection) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETVIDPNSOURCEHWPROTECTION Pfnd3dkmtSetvidpnsourcehwprotection;

// Definition

NTSTATUS Pfnd3dkmtSetvidpnsourcehwprotection
(
	D3DKMT_SETVIDPNSOURCEHWPROTECTION *
)
{...}

```

## Remarks

## See also