# NtGdiDdUnattachSurface function

\[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Removes an attachment, created with [**NtGdiDdAttachSurface**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddattachsurface), between two kernel-mode surface objects.

## Parameters

*hSurface* \[in\]

The kernel-mode surface object that was passed as the hSurfaceFrom parameter to [**NtGdiDdAttachSurface**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddattachsurface).

*hSurfaceAttached* \[in\]

The kernel-mode surface object that was passed as the hSurfaceTo parameter to [**NtGdiDdAttachSurface**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddattachsurface)

## Return value

**NtGdiDdUnattachSurface** returns one of the following callback codes.

| Return code | Description |
|----------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **DDHAL\_DRIVER\_HANDLED** | The driver has performed the operation and returned a valid return code for that operation. If this code is DD\_OK, DirectDraw or Direct3D proceeds with the function. Otherwise, DirectDraw or Direct3D returns the error code provided by the driver and aborts the function.<br> |
| **DDHAL\_DRIVER\_NOTHANDLED** | The driver has no comment on the requested operation. If the driver is required to have implemented a particular callback, DirectDraw or Direct3D reports an error condition. Otherwise, DirectDraw or Direct3D handles the operation as if the driver callback had not been defined by executing the DirectDraw or Direct3D device-independent implementation.<br> |

## Remarks

It is recommended that applications use the DirectDraw API, which handles surface attachments in a higher-level manner.

It is not necessary to call this function because the kernel will automatically destroy all attachments when [**NtGdiDdDestroySurface**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdidddestroysurface) is called.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

