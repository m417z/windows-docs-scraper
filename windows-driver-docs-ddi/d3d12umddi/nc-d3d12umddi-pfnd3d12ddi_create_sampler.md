# PFND3D12DDI_CREATE_SAMPLER callback function

## Description

Create sampler.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_SAMPLER structure.

### `DestDescriptor`

A CPU descriptor handle.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_SAMPLER Pfnd3d12ddiCreateSampler;

// Definition

VOID Pfnd3d12ddiCreateSampler
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_SAMPLER *
	D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptor
)
{...}

PFND3D12DDI_CREATE_SAMPLER

```