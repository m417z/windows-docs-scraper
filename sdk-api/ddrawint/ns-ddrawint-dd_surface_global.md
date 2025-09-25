# DD_SURFACE_GLOBAL structure

## Description

The DD_SURFACE_GLOBAL structure contains global surface-related data that can be shared between multiple surfaces.

## Members

### `dwBlockSizeY`

Specifies the location in which the driver returns the height, in scan lines, of the offscreen memory block that Microsoft DirectDraw should allocate. The driver should set this value when it returns DDHAL_PLEASEALLOC_BLOCKSIZE in the **fpVidMem** member.

### `lSlicePitch`

Slice pitch for volume textures.

### `lpVidMemHeap`

Points to a [VIDEOMEMORY](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemory) structure from which the heap display memory was allocated.

### `dwBlockSizeX`

Specifies the location in which the driver returns the size in bytes of the width of the offscreen memory block that DirectDraw should allocate. The driver should set this value when it returns DDHAL_PLEASEALLOC_BLOCKSIZE in the **fpVidMem** member.

### `dwUserMemSize`

Specifies the location in which the driver returns the size in bytes of the memory block that DirectDraw should allocate in user-mode system memory. The driver should set this value when it returns DDHAL_PLEASEALLOC_USERMEM in the **fpVidMem** member.

### `fpVidMem`

If the driver allocates the memory block, it should return the offset into display memory in this member. If the driver requests DirectDraw to do the memory allocation, it can instead return one of the following values in this member from its [DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85)) routine:

| Value | Meaning |
| --- | --- |
| DDHAL_PLEASEALLOC_BLOCKSIZE | DirectDraw should allocate a memory block of size **dwBlockSizeX** and **dwBlockSizeY** in offscreen memory. |
| DDHAL_PLEASEALLOC_USERMEM | DirectDraw should allocate a memory block of size **dwUserMemSize** in user-mode memory. |

### `lPitch`

Specifies the pitch of the surface; that is, the distance in bytes to the start of the next line. This is also known as the stride of the surface.

### `dwLinearSize`

Specifies the linear size in bytes of a nonrectangular surface.

### `yHint`

Specifies the y-coordinate of the surface. This member is a 2D Cartesian coordinate specified in device space.

### `xHint`

Specifies the x-coordinate of the surface. This member is a 2D Cartesian coordinate specified in device space.

### `wHeight`

Specifies the height in pixels of the surface.

### `wWidth`

Specifies the width in pixels of the surface.

### `dwReserved1`

Reserved for use by the display driver.

### `ddpfSurface`

Points to the [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure that describes the pixel format of the surface.

### `fpHeapOffset`

Points to the raw offset in the source heap.

### `hCreatorProcess`

Reserved for system use and should be ignored by the driver.

## Remarks

A [vertex buffer](https://learn.microsoft.com/windows-hardware/drivers/display/direct3d-vertex-buffers), which is created by [CreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurface), holds a list of vertices used by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback for rendering primitives. Microsoft Windows represents vertex buffers as DirectDraw surfaces, thereby establishing a connection between vertex buffers and the DD_SURFACE_GLOBAL structure.

When a DirectX driver is working with a vertex buffer, it is important for it to be able to correctly determine the size of this buffer. DirectDraw passes the linear buffer size to the driver in the **lPitch** member of this structure. On Windows 2000 and later versions, but not on Windows 98/Me, the **wWidth** member of this structure is set to the same value. Note that both structure members should be considered to be read-only. The value that DirectDraw places in these members represents the minimum vertex buffer size. Should the need for a larger buffer arise (such as for optimization), a driver writer is free to create a buffer larger than that size. Under no circumstances, however, should the driver report the larger buffer size to DirectDraw.

## See also

[CreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurface)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)

[DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat)

[DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85))

[VIDEOMEMORY](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemory)