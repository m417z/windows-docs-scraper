# NtGdiDdCreateSurface function

\[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Attaches a surface to another surface.

## Parameters

*hDirectDraw* \[in\]

Handle to the [**DD\_DIRECTDRAW\_GLOBAL**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure representing the driver.

*hSurface* \[in\]

Previous handle to the same surface. Used if the surface is being re-created after a mode switch.

*puSurfaceDescription* \[in, out\]

Pointer to the [**DDSURFACEDESC**](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddsurfacedesc) structure describing the surface or buffer that the driver should create.

*puSurfaceGlobalData* \[in, out\]

Pointer to the [**DD\_SURFACE\_GLOBAL**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_global) structure containing surface data that is shared globally with multiple surfaces.

*puSurfaceLocalData* \[in, out\]

Pointer to a list of [**DD\_SURFACE\_LOCAL**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local) structures describing the surface objects created by the driver.

*puSurfaceMoreData* \[in, out\]

Pointer to a [**DD\_SURFACE\_MORE**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_more) structure that contains additional local surface data.

*puCreateSurfaceData* \[in, out\]

Pointer to a [**DD\_CREATESURFACEDATA**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_createsurfacedata) structure that contains the information required to create a surface.

*puhSurface* \[out\]

Is used by the DirectDraw API and should not be filled in by the driver.

## Return value

**NtGdiDdCreateSurface** returns one of the following callback codes.

| Return code | Description |
|----------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **DDHAL\_DRIVER\_HANDLED** | The driver has performed the operation and returned a valid return code for that operation. If this code is DD\_OK, DirectDraw or Direct3D proceeds with the function. Otherwise, DirectDraw or Direct3D returns the error code provided by the driver and aborts the function.<br> |
| **DDHAL\_DRIVER\_NOTHANDLED** | The driver has no comment on the requested operation. If the driver is required to have implemented a particular callback, DirectDraw or Direct3D reports an error condition. Otherwise, DirectDraw or Direct3D handles the operation as if the driver callback had not been defined by executing the DirectDraw or Direct3D device-independent implementation.<br> |

## Remarks

It is recommended that your application call [IDirectDraw7::CreateSurface](https://learn.microsoft.com/windows/win32/api/ddraw/nf-ddraw-idirectdraw7-createsurface) instead of using this function.

When creating a chain of attached surfaces, such as a swap chain or chain or mipmaps, [**NtGdiDdCreateSurfaceObject**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddcreatesurfaceobject) should be called for each surface first. Then call [**NtGdiDdAttachSurface**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddattachsurface) to attach them. Finally, call **NtGdiDdCreateSurface** for the first surface in the chain only. In this case, *hSurface* would be the handle returned by **NtGdiDdCreateSurfaceObject** for the first surface in the chain.

**NtGdiDdCreateSurface** should only be called to create surfaces in local and non-local video memory. It should never be called to create system memory surfaces. To create system memory surfaces, use [**NtGdiDdCreateSurfaceObject**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddcreatesurfaceobject) instead.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

