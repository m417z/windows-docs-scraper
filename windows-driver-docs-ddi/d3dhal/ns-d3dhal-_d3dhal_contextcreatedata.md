# _D3DHAL_CONTEXTCREATEDATA structure

## Description

The D3DHAL_CONTEXTCREATEDATA structure contains all of the information that the [D3dContextCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextcreatecb) function requires to create a new context.

## Members

### `lpDDGbl`

 Driver structure (legacy).

### `lpDDLcl`

Points to the DirectDraw object that an application must create in order to retrieve the COM Interface to Direct3D. This allows context information to be shared between a DirectDraw application and the driver. **lpDDLcl** is the common and binding factor between the application's context and the driver's context. It points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is used to identify the surfaces that belong to a given Direct3D context and is relevant to the current DirectDraw process only. **lpDDLcl** is necessary because surfaces (for example, depth buffers, rendering buffers, and textures) can be created before a Direct3D context is ever created in the driver.

### `lpDDS`

 Surface to be used as target.

### `lpDDSLcl`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local) structure that describes the DirectDraw surface to be used as the rendering target.

### `lpDDSZ`

Surface to be used as Z.

### `lpDDSZLcl`

Points to a DD_SURFACE_LOCAL structure that describes the DirectDraw surface to be used as a depth buffer. If this member is **NULL**, no depth buffering is to be performed.

### `dwPID`

Specifies the current process ID. This is the process ID of the Direct3D application that initiated the creation of the Direct3D device.

### `dwrstates`

Points to a render state array that the driver should update when it parses render state commands from the command buffer. The array buffer must be large enough to contain at least the specified number of ULONG values.

### `dwhContext`

Specifies a location that indicates, on input, the version of the Direct3D user-mode runtime and, on output, where the driver returns the context handle upon successfully creating the context. See Remarks for more information.

### `ddrval`

Specifies the location where the driver writes the return code for [D3dContextCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextcreatecb). A return code of D3D_OK indicates success. A return code of D3DHAL_OUTOFCONTEXTS indicates that the driver cannot create the context. For more information, see [Return Codes for Direct3D Driver Callbacks](https://learn.microsoft.com/windows-hardware/drivers/display/return-codes-for-direct3d-driver-callbacks).

## Remarks

When the Direct3D runtime calls the driver's [D3dContextCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextcreatecb) function, the runtime specifies a number that indicates the runtime's user-mode version in the **dwhContext** member. The following table shows a mapping of numbers and user-mode versions.

|Number|DirectX user-mode version|
|--- |--- |
|5|9.0|
|4|8.0|
|3|7.0|
|2|6.0|
|1|5.0|
|0|3.0|

If the driver successfully creates a context, the driver returns the context ID in **dwhContext** for the Direct3D runtime to use when communicating with the driver.

## See also

[D3dContextCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextcreatecb)

[DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_directdraw_local)

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local)