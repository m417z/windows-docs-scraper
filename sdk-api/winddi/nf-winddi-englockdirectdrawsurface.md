# EngLockDirectDrawSurface function

## Description

The **EngLockDirectDrawSurface** function locks the kernel-mode handle of a DirectDraw surface.

## Parameters

### `hSurface` [in]

Handle to the surface to be locked.

## Return value

**EngLockDirectDrawSurface** returns a pointer to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that describes the surface information upon success. Otherwise, it returns a **NULL** pointer.

## Remarks

**EngLockDirectDrawSurface** allows driver writers to lock DirectDraw surfaces. Locking the handle guarantees synchronized behavior and preserves the handle from being deleted by other threads in the system.

Currently, the driver receives DirectDraw surface handles only from the Direct3D texturing interface. Consequently, only drivers that perform texturing need to lock texture surfaces.

Upon completion of texturing, the driver must release the locked handle by calling [EngUnlockDirectDrawSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunlockdirectdrawsurface).

## See also

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local)

[EngUnlockDirectDrawSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunlockdirectdrawsurface)