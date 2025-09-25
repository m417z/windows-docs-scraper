# PFND3D12DDI_CHECKEXISITINGRESOURCEALLOCATIONINFO callback function

## Description

The pfnCheckExistingResourceAllocationInfo callback function supports checking existing resource allocation information.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A handle to the device resource.

### `unnamedParam3`

Pointer to a D3D12DDI_RESOURCE_ALLOCATION_INFO.

### `phAllocation`

Pointer to an array of handles.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CHECKEXISITINGRESOURCEALLOCATIONINFO Pfnd3d12ddiCheckexisitingresourceallocationinfo;

// Definition

VOID Pfnd3d12ddiCheckexisitingresourceallocationinfo
(
	 D3D12DDI_HDEVICE
	 D3D12DDI_HRESOURCE
	D3D12DDI_RESOURCE_ALLOCATION_INFO *
	D3DKMT_HANDLE *phAllocation
)
{...}

PFND3D12DDI_CHECKEXISITINGRESOURCEALLOCATIONINFO

```