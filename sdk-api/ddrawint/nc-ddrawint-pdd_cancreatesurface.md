## Description

The **CanCreateD3DBuffer** callback function determines whether the driver can create a driver-level command or vertex buffer of the specified description.

## Parameters

### `unnamedParam1`

Points to a [DD_CANCREATESURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_cancreatesurfacedata) structure. This structure contains the information required for the driver to determine whether a command or vertex buffer can be created.

## Return value

**CanCreateD3DBuffer** returns a callback code.

## Remarks

This callback is used only if the driver manages driver-level command and vertex buffers.

**CanCreateD3DBuffer** should check the surface description that the **lpDDSurfaceDesc** member of the DD_CANCREATESURFACEDATA structure at **lpCanCreateD3DBuffer** points to in order to determine whether the driver can support the format and capabilities of the requested buffer for the mode that the driver is currently in. The driver should return DD_OK in the **ddRVal** member of the same structure if it supports that type of buffer. Otherwise, it should return the DDERR_*Xxx* error code that best describes why it does not support the buffer.

This call has the same prototype as [DdCanCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549213(v=vs.85)). The **CanCreateD3DBuffer** callback is used, however, when the surface in question has the DDSCAPS_EXECUTEBUFFER flag set in the **ddsCaps** member of the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure.

The driver determines the type of buffer being requested by checking the **ddsCaps** member of the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure for the following flags:

| Flag | Meaning |
| --- | --- |
| DDSCAPS2_COMMANDBUFFER | The driver should allocate a command buffer. |
| DDSCAPS2_VERTEXBUFFER | The driver should allocate an explicit vertex buffer. |

**Note** If neither flag is set, the driver should allocate an implicit vertex buffer. Implicit vertex buffers should not be placed in video memory since they are expected to be read/write. Only explicit vertex buffers with the DDSCAPS_WRITEONLY flag set can be safely placed in video memory.

## See also

[CreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurface)

[DD_CANCREATESURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_cancreatesurfacedata)

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local)

[DdCanCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549213(v=vs.85))