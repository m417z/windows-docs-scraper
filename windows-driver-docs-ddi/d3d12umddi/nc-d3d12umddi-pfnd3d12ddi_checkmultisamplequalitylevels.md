# PFND3D12DDI_CHECKMULTISAMPLEQUALITYLEVELS callback function

## Description

Implemented by the client driver to check multi-sample quality levels.

## Parameters

### `hDevice`

A handle to a device.

### `Format`

A DXGI_FORMAT.

### `SampleCount`

The sample count.

### `Flags`

Multi-sample quality level flags.

### `pNumQualityLevels`

The number of quality levels.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CHECKMULTISAMPLEQUALITYLEVELS Pfnd3d12ddiCheckmultisamplequalitylevels;

// Definition

VOID Pfnd3d12ddiCheckmultisamplequalitylevels
(
	D3D12DDI_HDEVICE hDevice
	DXGI_FORMAT Format
	UINT SampleCount
	D3D12DDI_MULTISAMPLE_QUALITY_LEVEL_FLAGS Flags
	UINT *pNumQualityLevels
)
{...}

PFND3D12DDI_CHECKMULTISAMPLEQUALITYLEVELS

```