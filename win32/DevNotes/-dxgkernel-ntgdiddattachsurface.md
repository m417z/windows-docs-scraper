# NtGdiDdAttachSurface function

\[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Attaches two kernel-mode surface representations.

## Parameters

*hSurfaceFrom* \[in\]

Handle to kernel-mode surface object that will be the start point of the new attachment.

*hSurfaceTo* \[in\]

Handle to kernel-mode surface object that will be the end point of the new attachment.

## Return value

**NtGdiDdAttachSurface** returns one of the following:

| Return code | Description |
|--------------------------------------------------------------------------------------|-----------------------------------------|
| **TRUE** | The function call succeeded.<br> |
| **FALSE** | The function call failed.<br> |

## Remarks

See the DirectDraw software development kit (SDK) and Driver Development Kit (DDK) for a full description of surface attachments.

> [!Note]
> As with other surface attachments, the resulting attachment is one-way. After this function is called, *hSurfaceTo* will not be attached to *hSurfaceFrom*.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

