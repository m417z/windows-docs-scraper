# NtGdiDdCanCreateSurface function

\[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Indicates whether the driver can create a surface of the specified surface description.

## Parameters

*hDirectDraw* \[in\]

Handle to the [**DD\_DIRECTDRAW\_GLOBAL**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure representing the DirectDraw object.

*puCanCreateSurfaceData* \[in, out\]

Pointer to a [**DD\_CANCREATESURFACEDATA**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_cancreatesurfacedata) structure containing the information required for the driver to determine whether a surface can be created.

## Return value

**NtGdiDdCanCreateSurface** returns one of the following callback codes.

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

