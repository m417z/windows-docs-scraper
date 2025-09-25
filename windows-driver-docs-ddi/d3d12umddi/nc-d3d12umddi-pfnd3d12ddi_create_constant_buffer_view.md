# PFND3D12DDI_CREATE_CONSTANT_BUFFER_VIEW callback function

## Description

Create constant buffer view.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDI_CONSTANT_BUFFER_VIEW_DESC structure.

### `DestDescriptor`

CPU descriptor handle.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_CONSTANT_BUFFER_VIEW Pfnd3d12ddiCreateConstantBufferView;

// Definition

VOID Pfnd3d12ddiCreateConstantBufferView
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDI_CONSTANT_BUFFER_VIEW_DESC *
	D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptor
)
{...}

PFND3D12DDI_CREATE_CONSTANT_BUFFER_VIEW

```