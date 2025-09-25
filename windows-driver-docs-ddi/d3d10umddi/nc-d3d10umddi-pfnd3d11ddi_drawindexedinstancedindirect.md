# PFND3D11DDI_DRAWINDEXEDINSTANCEDINDIRECT callback function

## Description

The **DrawIndexedInstancedIndirect** function draws particular instances of indexed primitives.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hBufferForArgs*

A handle to a buffer that contains the arguments for **DrawIndexedInstancedIndirect** to process. The buffer contains the following tightly packed structure:

```cpp
struct DrawIndexedInstancedIndirectArgs {
  UINT IndexCountPerInstance;
  UINT InstanceCount;
  UINT StartIndexLocation;
  INT BaseVertexLocation;
  UINT StartInstanceLocation;
}
```

For more information about these arguments, see the [DrawIndexedInstanced](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawindexedinstanced) reference page.

### `unnamedParam3`

*AlignedByteOffsetForArgs*

The offset, in bytes, into the buffer that *hBufferForArgs* specifies. *AlignedByteOffsetForArgs* must be a multiple of 4.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The **DrawIndexedInstancedIndirect** function performs the same task as the call to the driver's [DrawIndexedInstanced](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawindexedinstanced) function. However, **DrawIndexedInstancedIndirect** obtains information about the index primitives from the contents of the buffer that the *hBufferForArgs* parameter specifies. **DrawIndexedInstancedIndirect** reads the contents of the buffer, starting at the byte offset that the *AlignedByteOffsetForArgs* parameter specifies.

When the Direct3D runtime calls the driver's [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource) function to create the buffer resource that the *hBufferForArgs* parameter specifies, the runtime must set the D3D11_DDI_RESOURCE_MISC_DRAWINDIRECT_ARGS flag in the **MiscFlags** member of the [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) structure.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of **DrawIndexedInstancedIndirect** (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource)

[D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[DrawIndexedInstanced](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawindexedinstanced)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)