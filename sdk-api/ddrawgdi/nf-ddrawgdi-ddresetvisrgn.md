# DdResetVisrgn function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Wrapper for the [NtGdiDdResetVisrgn](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdiddresetvisrgn) function and enables timely user-mode information on the clipping region for windows on the desktop.

**GdiEntry6** is defined as an alias for this function.

## Parameters

### `pSurfaceLocal`

Pointer to the user-mode object of any surface belonging to the DirectDraw device for which clipping is to be reset. See the DDK documentation for details.

### `hWnd`

Reserved.

## Return value

If successful, this function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

Clipping can change asynchronously from the point of view of user-mode threads.
The kernel-mode parts of DirectDraw and Windows Graphics Device Interface (GDI) maintain a counter that is incremented whenever the clipping list for the entire desktop changes. A call to this function records this counter with every existing DirectDraw primary surface on the system.

At any later time when one of these primary surfaces is modified by a [IDirectDrawSurface7::Blt](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-blt) or [IDirectDrawSurface7::Lock](https://learn.microsoft.com/previous-versions/ms858221(v=msdn.10)) operation (see DDK documentation), the counter recorded with the surface is compared with the global counter. If these values are different, an error code DDERR_VISRGNCHANGED is returned to the user-mode code. The user-mode code will then re-query the current clipping for the desktop, call [NtGdiDdResetVisrgn](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdiddresetvisrgn), and re-try the IDirectDrawSurface7::Blt applied to the primary surface, respecting the new clipping. Eventually, the clipping that was sampled by the user-mode code will be the same as the current clipping owned by kernel mode, and the IDirectDrawSurface7::Blt will be allowed to continue.

Applications are advised to use the [IDirectDrawClipper](https://learn.microsoft.com/previous-versions/aa919448(v=msdn.10)) interface or [IDirect3DDevice8::Present](https://learn.microsoft.com/previous-versions/ms889707(v=msdn.10)) method to handle asynchronous clipping changes. These constructs implement asynchronous clipping in an automated and operating-system-independent way.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)