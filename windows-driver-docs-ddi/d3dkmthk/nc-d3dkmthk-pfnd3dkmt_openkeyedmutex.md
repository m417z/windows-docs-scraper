# PFND3DKMT_OPENKEYEDMUTEX callback function

## Description

Pfnd3dkmtOpenkeyedmutex opens a keyed mutex object that includes private data.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENKEYEDMUTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openkeyedmutex) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OPENKEYEDMUTEX Pfnd3dkmtOpenkeyedmutex;

// Definition

NTSTATUS Pfnd3dkmtOpenkeyedmutex
(
	D3DKMT_OPENKEYEDMUTEX *
)
{...}

```

## Remarks

## See also