# PFND3D12DDI_CREATECOMMANDQUEUE_0023 callback function

## Description

The *pfnCreateCommandQueue* callback function is used to create command queue.

## Parameters

### `unnamedParam1`

The handle of a device.

### `unnamedParam2`

An argument used to create a command queue.

### `unnamedParam3`

The handle of the command queue for the driver to use when it calls back into the runtime.

### `unnamedParam4`

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Access this callback function by using a device functions core structure, such as the **D3D12DDI_DEVICE_FUNCS_CORE_0003** structure.