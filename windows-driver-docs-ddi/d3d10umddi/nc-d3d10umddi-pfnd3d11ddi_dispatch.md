# PFND3D11DDI_DISPATCH callback function

## Description

The **Dispatch** function executes the compute shader.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*ThreadGroupCountX* [in]

 The size, in thread groups, of the x-dimension of the thread-group grid. The maximum size is 65535.

### `unnamedParam3`

*ThreadGroupCountY* [in]

 The size, in thread groups, of the y-dimension of the thread-group grid. The maximum size is 65535.

### `unnamedParam4`

*ThreadGroupCountZ* [in]

 The size, in thread groups, of the z-dimension of the thread-group grid. The maximum size is 65535.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The Direct3D runtime calls the driver's **Dispatch** function on the display device to execute the compute shader. A compiled compute shader defines the set of instructions to execute per thread and the number of threads to run per group. The thread-group parameters (*ThreadGroupCountX*, *ThreadGroupCountY*, and *ThreadGroupCountZ*) indicate how many thread groups to execute. Each thread group contains the same number of threads, as defined by the compiled compute shader. The thread groups are organized in a three-dimensional grid. The total number of thread groups that the compiled compute shader executes is determined by the following calculation:

```cpp
ThreadGroupCountX * ThreadGroupCountY * ThreadGroupCountZ
```

In particular, if any of the values in the thread-group parameters are 0, the **Dispatch** function does nothing.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of **Dispatch** (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)