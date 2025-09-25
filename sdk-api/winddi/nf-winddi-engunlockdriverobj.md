# EngUnlockDriverObj function

## Description

The **EngUnlockDriverObj** function causes GDI to unlock the driver object.

## Parameters

### `hdo`

Identifies the object to be unlocked.

## Return value

The return value is **TRUE** if the function is successful; otherwise, it is **FALSE**.

## Remarks

The specified driver object must have been previously locked by a call to [EngLockDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-englockdriverobj). The object is not unlockable by another thread while it is locked down.

## See also

[EngLockDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-englockdriverobj)