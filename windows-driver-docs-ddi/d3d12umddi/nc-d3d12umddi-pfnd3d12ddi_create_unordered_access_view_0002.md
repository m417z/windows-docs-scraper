# PFND3D12DDI_CREATE_UNORDERED_ACCESS_VIEW_0002 callback function

## Description

Create unordered access view.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_UNORDERED_ACCESS_VIEW_0002 structure.

### `DestDescriptor`

A CPU descriptor handle.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_UNORDERED_ACCESS_VIEW_0002 Pfnd3d12ddiCreateUnorderedAccessView0002;

// Definition

VOID Pfnd3d12ddiCreateUnorderedAccessView0002
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_UNORDERED_ACCESS_VIEW_0002 *
	D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptor
)
{...}

PFND3D12DDI_CREATE_UNORDERED_ACCESS_VIEW_0002

```