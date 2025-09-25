## Description

The *CreateD3DBuffer* callback function is used to create a driver-level command or vertex buffer of the specified description.

## Parameters

### `unnamedParam1`

Points to a [DD_CREATESURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_createsurfacedata) structure that contains the information required to create the buffer.

## Return value

*CreateD3DBuffer* returns one of the following callback codes:

## Remarks

This callback is used only if the driver manages driver-level command and vertex buffers.

By default, the driver is not notified when a primary surface is created on Windows 2000 and later versions. However, if the driver supports the GUID_NTPrivateDriverCaps GUID in a [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) call and the DDHAL_PRIVATECAP_NOTIFYPRIMARYCREATION flag is set in the **dwPrivateCaps** member of the [DD_NTPRIVATEDRIVERCAPS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntprivatedrivercaps) structure, then the driver is notified.

The pitch must be returned in the **lPitch** member of both the [DD_SURFACE_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_global) and [DDSURFACEDESC](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddsurfacedesc) structures. For linear memory, the driver should set **dwBlockSizeX** to the size, in bytes, of the memory region and set **dwBlockSizeY** to 1. Both are members of the DD_SURFACE_GLOBAL structure.

This call has the same prototype as [DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85)). The *CreateD3DBuffer* callback is used instead when the surface in question has the DDSCAPS_EXECUTEBUFFER flag set in the **ddsCaps** member of the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure. The buffer creation flags are DDSCAPS_WRITEONLY, DDSCAPS2_VERTEXBUFFER and DDSCAPS2_COMMANDBUFFER.

The driver determines the type of buffer being requested by checking the **ddsCaps** member of the DD_SURFACE_LOCAL structure for the following flags:

| Flag | Meaning |
| --- | --- |
| DDSCAPS2_COMMANDBUFFER | The driver should allocate a command buffer. |
| DDSCAPS2_VERTEXBUFFER | The driver should allocate an explicit vertex buffer. |

**Note** If neither flag is set, the driver should allocate an implicit vertex buffer. Implicit vertex buffers should not be placed in video memory because they are expected to be read/write. Only explicit vertex buffers with the DDSCAPS_WRITEONLY flag set can be safely placed in video memory.

The driver can allocate the buffer memory itself or it can request that Microsoft DirectDraw perform the memory management. If the driver performs the allocation, it must write a valid pointer to the memory in the **fpVidMem** member of the [DD_SURFACE_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_global) structure.

Alternatively, the driver can request that DirectDraw allocate the buffer by returning one of the following values in **fpVidMem**:

| Value | Meaning |
| --- | --- |
| DDHAL_PLEASEALLOC_BLOCKSIZE | DirectDraw should allocate the buffer memory from offscreen memory. |
| DDHAL_PLEASEALLOC_USERMEM | DirectDraw should allocate the buffer memory from user memory. The driver must also return the size, in bytes, of the memory region in **dwUserMemSize**. |

## See also

[DDSURFACEDESC](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddsurfacedesc)

[DD_CREATESURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_createsurfacedata)

[DD_NTPRIVATEDRIVERCAPS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntprivatedrivercaps)

[DD_SURFACE_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_global)

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local)

[DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85))

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)