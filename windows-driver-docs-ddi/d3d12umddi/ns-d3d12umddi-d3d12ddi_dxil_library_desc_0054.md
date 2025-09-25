# D3D12DDI_DXIL_LIBRARY_DESC_0054 structure

## Description

Describes the DXIL (DirectX Intermediate Language) library.

## Members

### `pDXILLibrary`

Pointer to a DXIL library.

### `NumExports`

Optional. The number of exports in the DXIL library. If 0, all exports in the library/collection will be surfaced.

### `pExports`

Pointer to an array of [D3D12DDI_EXPORT_DESC_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_export_desc_0054).

## Remarks

If there are multiple explicit subject associations with different subobject definitions that map to a given shader export, this is a conflict. If a conflict is discovered during DXIL library creation, library creation will fail. Otherwise if a conflict is discovered during state object creation, that fails.

## See also