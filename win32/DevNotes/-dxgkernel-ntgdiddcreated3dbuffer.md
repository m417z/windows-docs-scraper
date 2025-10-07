# NtGdiDdCreateD3DBuffer function

\[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Used to create a driver-level command or vertex buffer of the specified description.

## Parameters

*hDirectDraw* \[in\]

Handle to the [**DD\_DIRECTDRAW\_GLOBAL**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure representing the driver.

*hSurface* \[in, out\]

Pointer to an array of surface handles. The caller can set these handles to the previous handle values if the surfaces are being re-created after a mode switch. This process is called "restoring" in the DirectDraw documentation.

*puSurfaceDescription* \[in, out\]

Pointer to a [**DDSURFACEDESC**](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddsurfacedesc) structure describing the surface or buffer that the driver should create.

*puSurfaceGlobalData* \[in, out\]

Pointer to a [**DD\_SURFACE\_GLOBAL**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_global) structure containing surface data that is shared globally with multiple surfaces.

*puSurfaceLocalData* \[in, out\]

Pointer to a list of [**DD\_SURFACE\_LOCAL**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local) structures describing the surface objects created by the driver. There is usually only one entry in this array.

*puSurfaceMoreData* \[in, out\]

Pointer to a [**DD\_SURFACE\_MORE**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_more) structure that contains additional local surface data.

*puCreateSurfaceData* \[in, out\]

Pointer to a [**DD\_CREATESURFACEDATA**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_createsurfacedata) structure that contains the information required to create the buffer.

*puhSurface* \[in, out\]

Is used by the DirectDraw API and should not be filled in by the driver.

## Return value

**NtGdiDdCreateD3DBuffer** returns one of the following callback codes.

| Return code | Description |
|----------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **DDHAL\_DRIVER\_HANDLED** | The driver has performed the operation and returned a valid return code for that operation. If this code is DD\_OK, DirectDraw or Direct3D proceeds with the function. Otherwise, DirectDraw or Direct3D returns the error code provided by the driver and aborts the function.<br> |
| **DDHAL\_DRIVER\_NOTHANDLED** | The driver has no comment on the requested operation. If the driver is required to have implemented a particular callback, DirectDraw or Direct3D reports an error condition. Otherwise, DirectDraw or Direct3D handles the operation as if the driver callback had not been defined by executing the DirectDraw or Direct3D device-independent implementation.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

