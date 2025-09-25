# PFND3DKMT_TRIMPROCESSCOMMITMENT callback function

## Description

Trim process commitment.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_TRIMPROCESSCOMMITMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_trimprocesscommitment) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_TRIMPROCESSCOMMITMENT Pfnd3dkmtTrimprocesscommitment;

// Definition

NTSTATUS Pfnd3dkmtTrimprocesscommitment
(
	D3DKMT_TRIMPROCESSCOMMITMENT *
)
{...}

```

## Remarks

## See also