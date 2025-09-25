# PFND3DKMT_PINDIRECTFLIPRESOURCES callback function

## Description

The PFND3DKMT_PINDIRECTFLIPRESOURCES callback function pins direct flip resources.

## Parameters

### `unnamedParam1`

*\_In\_* *pResources*

Pointer to a [D3DKMT_PINDIRECTFLIPRESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_pindirectflipresources) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_PINDIRECTFLIPRESOURCES Pfnd3dkmtPindirectflipresources;

// Definition

NTSTATUS Pfnd3dkmtPindirectflipresources
(
	const D3DKMT_PINDIRECTFLIPRESOURCES *
)
{...}

```

## Remarks

## See also

[D3DKMT_PINDIRECTFLIPRESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_pindirectflipresources)