# PFND3D11DDI_DISPATCHINDIRECT callback function

## Description

The **DispatchIndirect** function executes the compute shader.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hBufferForArgs* [in]

A handle to a buffer that contains three UINT values that hold the sizes, in thread groups, of the X, Y, and Z dimensions of the thread-group grid. The buffer contains the following tightly packed structure:

```cpp
struct DispatchArgs {
  UINT ThreadGroupCountX;
  UINT ThreadGroupCountY;
  UINT ThreadGroupCountZ;
}
```

### `unnamedParam3`

*AlignedByteOffsetForArgs* [in]

The offset, in bytes, into the buffer that *hBufferForArgs* specifies. *AlignedByteOffsetForArgs* must be a multiple of 4.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The DispatchIndirect function performs the same task as the call to the driver's [Dispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_dispatch) function. The Direct3D runtime calls the driver's **DispatchIndirect** function on the display device to execute the compute shader over a number of threads in a grid of thread groups. However, **DispatchIndirect** obtains the number of thread groups to execute from the contents of the buffer that the *hBufferForArgs* parameter specifies. **DispatchIndirect** reads three UINT values, starting at the byte offset that the *AlignedByteOffsetForArgs* parameter specifies.

When the Direct3D runtime calls the driver's [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource) function to create the buffer resource that the *hBufferForArgs* parameter specifies, the runtime must set the D3D11_DDI_RESOURCE_MISC_DRAWINDIRECT_ARGS flag in the **MiscFlags** member of the [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) structure.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of **DispatchIndirect** (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource)

[D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[Dispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_dispatch)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)