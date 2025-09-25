# PFND3D12DDI_CHECKRESOURCEALLOCATIONINFO_0003 callback function

## Description

The **PFND3D12DDI_CHECKRESOURCEALLOCATIONINFO_0003** callback function supports checking resource allocation information.

## Parameters

### `unnamedParam1`

[in] A handle to the display device (graphics context).

### `unnamedParam2`

[in] Pointer to a D3D12DDIARG_CREATERESOURCE_0003 structure.

### `unnamedParam3`

Resource optimization flags.

### `AlignmentRestriction`

Indicates alignment restriction.

### `VisibleNodeMask`

Indicates the visible node mask.

### `unnamedParam6`

[out] Pointer to a D3D12DDI_RESOURCE_ALLOCATION_INFO structure.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CHECKRESOURCEALLOCATIONINFO_0003 Pfnd3d12ddiCheckresourceallocationinfo0003;

// Definition

VOID Pfnd3d12ddiCheckresourceallocationinfo0003
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATERESOURCE_0003 *
	 D3D12DDI_RESOURCE_OPTIMIZATION_FLAGS
	UINT64 AlignmentRestriction
	UINT VisibleNodeMask
	D3D12DDI_RESOURCE_ALLOCATION_INFO *
)
{...}

PFND3D12DDI_CHECKRESOURCEALLOCATIONINFO_0003

```