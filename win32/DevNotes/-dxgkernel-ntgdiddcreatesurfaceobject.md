# NtGdiDdCreateSurfaceObject function

\[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Creates a kernel-mode surface object that represents the user-mode surface object referenced by *puSurfaceLocal*.

## Parameters

*hDirectDrawLocal* \[in\]

Handle to the kernel-mode DirectDraw object.

*hSurface* \[in\]

Previous handle to the same surface. Used if the surface is being re-created after a mode switch.

*puSurfaceLocal* \[in\]

Pointer to the [**DD\_SURFACE\_LOCAL**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local) structure that represents the DirectDraw user-mode surface object with which to associate the allocated memory. See the DDK documentation for details.

*puSurfaceMore* \[in\]

Pointer to the [**DD\_SURFACE\_MORE**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_more) structure that contains additional local data for each individual surface object. See the DDK documentation for details.

*puSurfaceGlobal* \[in\]

Pointer to the [**DD\_SURFACE\_GLOBAL**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_global) structure that contains surface data shared globally with multiple surfaces. See the DDK documentation for details.

*bComplete* \[in\]

Kernel-mode object completion flag. Can be one of the following values.

(TRUE)

Complete all processing concerning the kernel-mode representation.

(FALSE)

Create the object, but do not set up internal data such as the memory pointer. Objects created using **FALSE** can be attached using [**NtGdiDdAttachSurface**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddattachsurface) and are completed by a call to [**NtGdiDdCreateSurface**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddcreatesurface).

## Return value

If successful, this function returns a handle to the kernel-mode surface representation; otherwise it returns **NULL**.

## Remarks

Applications are advised to use the DirectDraw and [Direct3D](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference) APIs to create and manage graphics device objects. These constructs abstract the device creation process in a simplified and operating-system-independent way.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

[**DdCreateSurfaceObject**](https://learn.microsoft.com/windows/desktop/api/Ddrawgdi/nf-ddrawgdi-ddcreatesurfaceobject)

[**NtGdiDdDeleteSurfaceObject**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdidddeletesurfaceobject)

[**NtGdiDdAttachSurface**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddattachsurface)

[**NtGdiDdCreateSurface**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddcreatesurface)

