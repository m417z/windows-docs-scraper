# PFND3D12DDI_CREATECOMMANDQUEUE_0001 callback function

## Description

The PFND3D12DDI_CREATECOMMANDQUEUE_0001 callback function is used to create command queue.

## Parameters

### `unnamedParam1`

The handle of a device.

### `unnamedParam2`

Arguments used to create a command queue.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATECOMMANDQUEUE_0001 Pfnd3d12ddiCreatecommandqueue0001;

// Definition

HRESULT Pfnd3d12ddiCreatecommandqueue0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATECOMMANDQUEUE_0001 *
)
{...}

PFND3D12DDI_CREATECOMMANDQUEUE_0001

```

## Remarks

Access this callback function by using a device functions core structure, such as the [D3D12DDI_DEVICE_FUNCS_CORE_0010](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_device_funcs_core_0010) structure.

## See also