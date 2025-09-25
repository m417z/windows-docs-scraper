# EngUnlockDirectDrawSurface function

## Description

The **EngUnlockDirectDrawSurface** function releases the lock on the specified surface.

## Parameters

### `pSurface` [in]

Pointer to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that describes the surface to be unlocked.

## Return value

**EngUnlockDirectDrawSurface** returns **TRUE** when it successfully unlocks the specified surface. Otherwise, it returns **FALSE**.

## Remarks

The surface must previously have been locked by [EngLockDirectDrawSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-englockdirectdrawsurface).

## See also

[EngLockDirectDrawSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-englockdirectdrawsurface)