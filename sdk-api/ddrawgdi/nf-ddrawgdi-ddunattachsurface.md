# DdUnattachSurface function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

The **DdUnattachSurface** function removes an attachment, created with [DdAttachSurface](https://learn.microsoft.com/windows/desktop/api/ddrawgdi/nf-ddrawgdi-ddattachsurface), between two kernel-mode surface objects.

**GdiEntry12** is defined as an alias for this function.

## Parameters

### `pSurface` [in]

Pointer to the kernel-mode surface object that was passed as the *pSurfaceFrom* parameter to [DdAttachSurface](https://learn.microsoft.com/windows/desktop/api/ddrawgdi/nf-ddrawgdi-ddattachsurface).

### `pSurfaceAttached` [in]

Pointer to the kernel-mode surface object that was passed as the *pSurfaceTo* parameter to [DdAttachSurface](https://learn.microsoft.com/windows/desktop/api/ddrawgdi/nf-ddrawgdi-ddattachsurface)

## Remarks

It is recommended that applications use the DirectDraw
API which handles surface attachments in a higher-level manner.

It is not necessary to call this function since the kernel will automatically destroy all attachments when [DdDestroySurface](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdidddestroysurface) is called.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)