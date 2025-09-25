# PFND3D10DDI_DRAWINDEXEDINSTANCED callback function

## Description

The **DrawIndexedInstanced** function draws particular instances of indexed primitives.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*IndexCountPerInstance* [in]

The number of indexes per instance of the index buffer that indexes are read from to draw the primitives.

### `unnamedParam3`

*InstanceCount* [in]

The number of instances of the index buffer that indexes are read from to draw the primitives.

### `unnamedParam4`

*StartIndexLocation* [in]

The first index in the index buffer that indexes are read from to draw the primitives.

### `unnamedParam5`

*BaseVertexLocation* [in]

The number that should be added to each index that is referenced by the various primitives to determine the actual index of the vertex elements in each vertex stream.

### `unnamedParam6`

*StartInstanceLocation* [in]

The first instance of the index buffer that indexes are read from to draw the primitives.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *DrawIndexedInstanced* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)