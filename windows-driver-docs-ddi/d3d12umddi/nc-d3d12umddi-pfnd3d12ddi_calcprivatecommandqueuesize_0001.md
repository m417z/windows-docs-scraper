# PFND3D12DDI_CALCPRIVATECOMMANDQUEUESIZE_0001 callback function

## Description

The *pfnCalcPrivateCommandQueueSize* callback function is used to calculate the size of a private command queue.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

An argument used to create a command queue.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATECOMMANDQUEUESIZE_0001 Pfnd3d12ddiCalcprivatecommandqueuesize0001;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatecommandqueuesize0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATECOMMANDQUEUE_0001 *
)
{...}

PFND3D12DDI_CALCPRIVATECOMMANDQUEUESIZE_0001

```

## Remarks

## See also