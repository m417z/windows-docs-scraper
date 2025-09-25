# PFND3D11DDI_SETSHADER_WITH_IFACES callback function

## Description

The **CsSetShaderWithIfaces** function sets the compute shader code along with a group of interfaces so that all of the subsequent dispatching operations use that code and those interfaces.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hShader* [in]

A handle to the compute shader code object.

### `NumClassInstances` [in]

The number of class instances for implementations of the interfaces.

### `unnamedParam4`

*pPointerData* [in]

An array of [D3D11DDIARG_POINTERDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_pointerdata) structures. Each structure describes the location of the data that is referenced by a class instance that is assigned to an interface implementation. The number of elements in the array is specified by the *NumClassInstances* parameter.

### `unnamedParam5`

*pIfaces* [in]

An array of function table identifiers. Each identifier corresponds to a class instance that is assigned to an interface implementation. The number of elements in the array is specified by the *NumClassInstances* parameter.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

Each class instance for an interface implementation has the following pieces of information:

* Code that is associated with that class instance
* A location for the data that is used by that class instance

The *NumClassInstances* parameter specifies the number of interfaces that must be assigned values at run time. For each interface, each element of the **pIfaces** array provides a function table identifier, and each element of the **pPointerData** array provides the data locations for a class instance that is assigned to the interface.

The driver can pass E_OUTOFMEMORY (if the driver runs out of memory) or D3DDDIERR_DEVICEREMOVED (if the device is removed) in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function. The Direct3D runtime determines that any other errors are critical. If the driver passes any errors, which includes D3DDDIERR_DEVICEREMOVED, the Direct3D runtime determines that the handle is invalid; therefore, the runtime does not call the [DestroyShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshader) function to destroy the handle that the *hShader* parameter specifies.

The **GsSetShaderWithIfaces** function sets the geometry shader code along with a group of interfaces so that all of the subsequent drawing operations use that code and those interfaces.

The **PsSetShaderWithIfaces** function sets the pixel shader code along with a group of interfaces so that all of the subsequent drawing operations use that code and those interfaces.

The **DsSetShaderWithIfaces** function sets the domain shader code along with a group of interfaces so that all of the subsequent drawing operations use that code and those interfaces.

The **HsSetShaderWithIfaces** function sets the hull shader code along with a group of interfaces so that all of the subsequent drawing operations use that code and those interfaces.

The **VsSetShaderWithIfaces** function sets the vertex shader code along with a group of interfaces so that all of the subsequent drawing operations use that code and those interfaces.

## See also

[D3D11DDIARG_POINTERDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_pointerdata)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[DestroyShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshader)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)