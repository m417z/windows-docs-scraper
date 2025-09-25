# PFND3D12DDI_CHECKFORMATSUPPORT callback function

## Description

Implemented by the client driver to check the format support.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A DXGI_FORMAT.

### `unnamedParam3`

Pointer to a UINT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CHECKFORMATSUPPORT Pfnd3d12ddiCheckformatsupport;

// Definition

VOID Pfnd3d12ddiCheckformatsupport
(
    D3D12DDI_HDEVICE
    DXGI_FORMAT
    UINT *
)
{...}

PFND3D12DDI_CHECKFORMATSUPPORT

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3D12DDI_DEVICE_FUNCS_CORE_0010](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_device_funcs_core_0010).