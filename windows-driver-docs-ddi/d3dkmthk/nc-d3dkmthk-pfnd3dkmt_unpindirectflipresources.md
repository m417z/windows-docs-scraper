# PFND3DKMT_UNPINDIRECTFLIPRESOURCES callback function

## Description

The PFND3DKMT_UNPINDIRECTFLIPRESOURCES callback function unpins direct flip resources.

## Parameters

### `unnamedParam1`

*\_In\_* *pResources*

Pointer to a [D3DKMT_UNPINDIRECTFLIPRESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_unpindirectflipresources) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_UNPINDIRECTFLIPRESOURCES D3DKMTUnpinDirectFlipResources;

_Check_return_ NTSTATUS APIENTRY* D3DKMTUnpinDirectFlipResources(
  _In_ const D3DKMT_UNPINDIRECTFLIPRESOURCES *pResources
)
{ ... }

```

## Remarks

## See also

[D3DKMT_UNPINDIRECTFLIPRESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_unpindirectflipresources)