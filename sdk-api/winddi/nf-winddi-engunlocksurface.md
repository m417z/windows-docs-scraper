# EngUnlockSurface function

## Description

The **EngUnlockSurface** function causes GDI to unlock the surface.

## Parameters

### `pso` [in]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface to be unlocked.

## Return value

None

## Remarks

The specified surface must previously have been locked by a call to [EngLockSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-englocksurface). The pointer to the SURFOBJ structure must not be used after this call.

## See also

[EngLockSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-englocksurface)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)