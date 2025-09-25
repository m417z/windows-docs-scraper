# PFND3D12DDI_CALCPRIVATECOMMANDQUEUESIZE_0023 callback function

## Description

The **PFND3D12DDI_CALCPRIVATECOMMANDQUEUESIZE_0023** callback function is used to calculate the size of a private command queue.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

The CreateCommandQueue argument is used to create a command queue.

## Return value

The size of the queue.

## Remarks

Access this callback function by using a device functions core structure, such as the **D3D12DDI_DEVICE_FUNCS_CORE_0003** structure.