# DD_LOCKDATA structure

## Description

The DD_LOCKDATA structure contains information necessary to do a lock as defined by the Microsoft DirectDraw parameter structures.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurface`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that describes the surface--in the case of [LockD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568216(v=vs.85)), a buffer--associated with the memory region to be locked down.

### `bHasRect`

Specifies whether the area in **rArea** is valid. A value of 0x00000001 indicates a valid area, 0x00000000 indicates an invalid area.

### `rArea`

Specifies a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the area on the surface to lock down.

### `lpSurfData`

Specifies the location in which the driver can return a pointer to the memory region that it locked down.

### `ddRVal`

Specifies the location in which the driver writes the return value of either the [DdLock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_lock) or [LockD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568216(v=vs.85)) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `Lock`

Used by the DirectDraw API and should not be filled in by the driver.

### `dwFlags`

Specifies a bitmask that tells the driver how to perform the memory lockdown. This member is a bitwise OR of any of the following values:

| Flag | Meaning |
| --- | --- |
| DDLOCK_DISCARDCONTENTS | No assumptions are made about the contents of the surface or vertex buffer during this lock. This enables two things:<br><br>1. Microsoft Direct3D or the driver may provide an alternative memory area as the vertex buffer. This is useful when one plans to clear the contents of the vertex buffer and fill in new data.<br><br>2. Drivers sometimes store surface data in a reordered format. When the application locks the surface, the driver is forced to undo this surface data reordering before allowing the application to see the surface contents.<br><br>This flag is a hint to the driver that it can skip the un-reordering process since the application plans to overwrite every single pixel in the surface or locked rectangle (and so erase any un-reordered pixels anyway). Applications should always set this flag when they intend to overwrite the entire surface or locked rectangle. |
| DDLOCK_DONOTWAIT | On **IDirectDrawSurface7** and higher interfaces, the default is DDLOCK_WAIT. If you wish to override the default and use time when the accelerator is busy (as denoted by the DDERR_WASSTILLDRAWING return code) then use this flag. |
| DDLOCK_EVENT | Set if an event handle is being passed to **Lock**, which triggers the event when it can return the surface memory pointer requested. |
| DDLOCK_HASVOLUMETEXTUREBOXRECT | The driver should return a valid memory pointer to the beginning of the subvolume texture specified in the rectangle (RECTL) in **rArea**. The driver obtains the front and back coordinates of the subvolume from the top 16 bits of the left and right coordinates (left and right members of RECTL) respectively. The left and right coordinates are constrained to the lower 16 bits. If no rectangle is specified, the driver should return a pointer to the top of the whole volume. This value is available in DirectX 8.1 and later. |
| DDLOCK_NODIRTYUPDATE | Sent to the driver by the runtime after an application requests to lock down a memory region with the D3DLOCK_NO_DIRTY_UPDATE flag set. In this case, the driver should not consider the memory region that it locks down as dirty when the runtime calls the driver's [DdUnlock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_unlock) function to update a surface that contains this region. Rather, the driver should only consider the regions specified in previous calls to its [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) function using the D3DDP2OP_ADDDIRTYRECT and D3DDP2OP_ADDDIRTYBOX enumerators as dirty.<br><br>By default, a lock on a surface adds a dirty region to that surface. |
| DDLOCK_NOOVERWRITE | Used only with Direct3D vertex buffer locks. Indicates that no vertices that were referred to in **IDirect3DDevice7::DrawPrimitiveVB** and **IDirect3DDevice7::DrawIndexedPrimitiveVB** calls (described in the Direct3D SDK documentation) since the start of the frame (or the last lock without this flag) are modified during the lock. This can be useful when one is only appending data to the vertex buffer. |
| DDLOCK_NOSYSLOCK | Indicates that a system-wide lock should not be taken when this surface is locked. This has several advantages when locking video memory surfaces, such as cursor responsiveness, ability to call more Microsoft Windows functions, and easier debugging. However, an application specifying this flag must comply with a number of conditions documented in the help file.<br><br>This flag cannot be specified when locking the primary. |
| DDLOCK_OKTOSWAP | Same as DDLOCK_DISCARDCONTENTS. |
| DDLOCK_READONLY | The surface being locked will only be read from. On Windows 2000 and later, this flag is never set. |
| DDLOCK_SURFACEMEMORYPTR | The driver should return a valid memory pointer to the top of the rectangle specified in **rArea**. If no rectangle is specified, the driver should return a pointer to the top of the surface. |
| DDLOCK_WAIT | Set to indicate that **Lock** should wait until it can obtain a valid memory pointer before returning. If this bit is set, **Lock** never returns DDERR_WASSTILLDRAWING. |
| DDLOCK_WRITEONLY | The surface being locked will only be written to. On Windows 2000 and later, this flag is never set. |

### `fpProcess`

Specifies a pointer to a user-mode mapping of the driver's memory. The driver performs this mapping in [DdMapMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mapmemory). Windows 2000 and later only.

## See also

[DdLock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_lock)

[DdMapMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mapmemory)

[LockD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568216(v=vs.85))