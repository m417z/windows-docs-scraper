# D3D12DDI_EXISTING_COLLECTION_DESC_0054 structure

## Description

An existing collection. A collection is a state object type that contains any amount of subobjects, but doesn't have constraints.

## Members

### `hExistingCollection`

A handle to an existing collection.

### `NumExports`

The number of [D3D12DDI_EXPORT_DESC_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_export_desc_0054) structures that pExports points to.

### `pExports`

Pointer to an array of D3D12DDI_EXPORT_DESC_0054 structures.

## Remarks

The purpose of a collection is to allow an application to pass an arbitrarily large or small collection of state to drivers to compile at once.

## See also