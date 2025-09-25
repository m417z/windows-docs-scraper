# DD_D3DBUFCALLBACKS structure

## Description

The DD_D3DBUFCALLBACKS structure is used only by drivers that implement driver level allocation of command and vertex buffers.

## Members

### `dwSize`

Specifies the size in bytes of this DD_D3DBUFCALLBACKS structure.

### `dwFlags`

Reserved.

### `CanCreateD3DBuffer`

Points to the driver's [CanCreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_cancreatesurface) callback.

### `CreateD3DBuffer`

Points to the driver's [CreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurface) callback.

### `DestroyD3DBuffer`

Points to the driver's [DestroyD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552754(v=vs.85)) callback.

### `LockD3DBuffer`

Points to the driver's [LockD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568216(v=vs.85)) callback.

### `UnlockD3DBuffer`

Points to the driver's [UnlockD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570106(v=vs.85)) callback.

## Remarks

Drivers that manage their own command and vertex buffers must fill out a DD_D3DBUFCALLBACKS structure and point the **lpD3DBufCallbacks** member of [DD_HALINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_halinfo) to it.

The driver must also support the callback functions reported in the DD_D3DBUFCALLBACKS structure. These *XxxD3DBuffer* callbacks are each analogous to the *DdXxxSurface* callback of similar name; they have the same prototypes and are called with the same input parameters. These new callbacks are called only when the surface in question has the DDSCAPS_EXECUTEBUFFER flag set in the surface caps. The buffer creation flags are DDSCAPS_WRITEONLY, DDSCAPS2_VERTEXBUFFER and DDSCAPS2_COMMANDBUFFER.

The driver determines the type of buffer being requested by checking the **ddsCaps** member of the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that is passed to [CanCreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_cancreatesurface) and [CreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurface) for the following flags:

* DDSCAPS_VERTEXBUFFER

  Indicates that the driver should allocate an explicit vertex buffer.
* DDSCAPS_COMMANDBUFFER

  Indicates that the driver should allocate a command buffer.
* The absence of both these flags

  Indicates that the driver should allocate an implicit vertex buffer.

Implicit vertex buffers should not be placed in video memory because they are expected to be read/write. Only explicit vertex buffers with the DDSCAPS_WRITEONLY flag set can be safely placed in video memory.

## See also

[CanCreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_cancreatesurface)

[CreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurface)

[DD_HALINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_halinfo)

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local)

[DestroyD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552754(v=vs.85))

[LockD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568216(v=vs.85))

[UnlockD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570106(v=vs.85))