# DdAttachSurface function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

The **DdAttachSurface** function attaches two kernel-mode surface representations.

**GdiEntry11** is defined as an alias for this function.

## Parameters

### `pSurfaceFrom` [in]

Pointer to a kernel-mode surface object that will be the start point of the new attachment.

### `pSurfaceTo` [in]

Pointer to a kernel-mode surface object that will be the end point of the new attachment.

## Return value

**DdAttachSurface** returns one of the following:

| Return code | Description |
| --- | --- |
| **TRUE** | The function call succeeded. |
| **FALSE** | The function call failed. |

## Remarks

See the DirectDraw
software development kit (SDK) and Driver Development Kit (DDK) for a full description of surface attachments.

**Note** As with other surface attachments, the resulting attachment is one-way. After this function is called, *pSurfaceTo* will not be attached to *pSurfaceFrom*.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)