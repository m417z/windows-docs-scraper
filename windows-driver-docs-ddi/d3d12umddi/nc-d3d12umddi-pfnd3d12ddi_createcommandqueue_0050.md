# PFND3D12DDI_CREATECOMMANDQUEUE_0050 callback function

## Description

The PFND3D12DDI_CREATECOMMANDQUEUE_0050 callback function is used to create command queue.

## Parameters

### `unnamedParam1`

The handle of a device.

### `unnamedParam2`

Pointer to a [D3D12DDIARG_CREATECOMMANDQUEUE_0050](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createcommandqueue_0050) structure that contains arguments used to create a command queue.

### `unnamedParam3`

The handle of the command queue for the driver to use when it calls back into the runtime.

### `unnamedParam4`

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATECOMMANDQUEUE_0050 Pfnd3d12ddiCreatecommandqueue0050;

// Definition

HRESULT Pfnd3d12ddiCreatecommandqueue0050
(
	D3D12DDI_HDEVICE Arg1
	CONST D3D12DDIARG_CREATECOMMANDQUEUE_0050 *
	D3D12DDI_HCOMMANDQUEUE Arg2
	D3D12DDI_HRTCOMMANDQUEUE Arg3
)
{...}

```

## Remarks

Access this callback function by using a device functions core structure, such as the [D3D12DDI_DEVICE_FUNCS_CORE_0050](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_device_funcs_core_0050) structure.

## See also