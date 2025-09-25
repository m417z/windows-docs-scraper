# PFND3D12DDI_CALCPRIVATECOMMANDQUEUESIZE_0050 callback function

## Description

The PFND3D12DDI_CALCPRIVATECOMMANDQUEUESIZE_0050 callback function is used to calculate the size of a private command queue.

## Parameters

### `unnamedParam1`

The handle of a device.

### `unnamedParam2`

*_In_ CreateCommandQueue*

Pointer to a [D3D12DDIARG_CREATECOMMANDQUEUE_0050](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createcommandqueue_0050) structure used to create a command queue.

## Return value

Returns SIZE_T that represents the size of the queue.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATECOMMANDQUEUESIZE_0050 Pfnd3d12ddiCalcprivatecommandqueuesize0050;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatecommandqueuesize0050
(
	D3D12DDI_HDEVICE Arg1
	CONST D3D12DDIARG_CREATECOMMANDQUEUE_0050 *
)
{...}

```

## Remarks

Access this callback function by using a device functions core structure, such as the [D3D12DDI_DEVICE_FUNCS_CORE_0050](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_device_funcs_core_0050) structure.

## See also