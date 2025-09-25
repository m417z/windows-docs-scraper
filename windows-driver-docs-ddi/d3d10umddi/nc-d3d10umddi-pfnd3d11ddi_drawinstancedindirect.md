# PFND3D11DDI_DRAWINSTANCEDINDIRECT callback function

## Description

The **DrawInstancedIndirect** function draws particular instances of non-indexed primitives.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hBufferForArgs* [in]

A handle to a buffer that contains the arguments for **DrawInstancedIndirect** to process. The buffer contains the following tightly packed structure:

```cpp
struct DrawInstancedIndirectArgs {
  UINT VertexCountPerInstance;
  UINT InstanceCount;
  UINT StartVertexLocation;
  UINT StartInstanceLocation;
}
```

For more information about these arguments, see the [DrawInstanced](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawinstanced) reference page.

### `unnamedParam3`

*AlignedByteOffsetForArgs* [in]

The offset, in bytes, into the buffer that *hBufferForArgs* specifies. *AlignedByteOffsetForArgs* must be a multiple of four.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The **DrawInstancedIndirect** function performs the same task as the call to the driver's [DrawInstanced](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawinstanced) function. However, **DrawInstancedIndirect** obtains information about the non-indexed primitives from the contents of the buffer that the *hBufferForArgs* parameter specifies. **DrawInstancedIndirect** reads the contents of the buffer, starting at the byte offset that the *AlignedByteOffsetForArgs* parameter specifies.

When the Direct3D runtime calls the driver's [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource) function to create the buffer resource that the *hBufferForArgs* parameter specifies, the runtime must set the D3D11_DDI_RESOURCE_MISC_DRAWINDIRECT_ARGS flag in the **MiscFlags** member of the [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) structure.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of **DrawInstancedIndirect** (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource)

[D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[DrawInstanced](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawinstanced)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)