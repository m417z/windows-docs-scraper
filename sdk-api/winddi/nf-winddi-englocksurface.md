# EngLockSurface function

## Description

The **EngLockSurface** function creates a user object for a given surface. This function gives drivers access to surfaces they create.

## Parameters

### `hsurf`

Handle to the surface to be locked.

## Return value

**EngLockSurface** returns a pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure if the function is successful. Otherwise, this function returns **NULL**.

## Remarks

This function gives drivers access to surfaces they create.

The driver is responsible for unlocking the surface when it no longer needs it. Surfaces should be locked only for very short periods of time.

Use the [EngUnlockSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunlocksurface) function to unlock the surface.

## See also

[EngUnlockSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunlocksurface)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)