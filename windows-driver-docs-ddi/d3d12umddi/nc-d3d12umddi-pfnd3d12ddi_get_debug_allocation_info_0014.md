# PFND3D12DDI_GET_DEBUG_ALLOCATION_INFO_0014 callback function

## Description

Returns the associated kernel mode allocation handles and GPU Virtual Address ranges.

## Parameters

### `hDevice`

A handle to the device that the resource or allocation is associated with.

### `Object`

A D3D12DDI_HANDLE_AND_TYPE data type that represents a kernel-mode handle to the resource that is associated with the allocations.

### `pNumVirtualAddressInfos`

Pointer to the number of virtual address info.

### `pVirtualAddressInfos`

Pointer to the debug virtual address information structure.

### `pNumKMTInfos`

Pointer to the number of kernel mode thread info.

### `pKMTInfos`

Pointer to the kernel mode thread info.

## Prototype

```cpp
//Declaration

PFND3D12DDI_GET_DEBUG_ALLOCATION_INFO_0014 Pfnd3d12ddiGetDebugAllocationInfo0014;

// Definition

VOID Pfnd3d12ddiGetDebugAllocationInfo0014
(
	D3D12DDI_HDEVICE hDevice
	D3D12DDI_HANDLE_AND_TYPE Object
	UINT *pNumVirtualAddressInfos
	D3D12DDI_DEBUG_VIRTUAL_ADDRESS_ALLOCATION_INFO_0012 *pVirtualAddressInfos
	UINT *pNumKMTInfos
	D3D12DDI_DEBUG_KMT_ALLOCATION_INFO_0014 *pKMTInfos
)
{...}

```

## Remarks

## See also