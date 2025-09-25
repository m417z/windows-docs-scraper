# EngLockDriverObj function

## Description

The **EngLockDriverObj** function creates an exclusive lock on this object for the calling thread.

## Parameters

### `hdo`

Handle to the [DRIVEROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-driverobj) structure to be locked by GDI.

## Return value

**EngLockDriverObj** returns a DRIVEROBJ structure if the function is successful. If the operation fails, it returns **NULL**.

## Remarks

This function will fail if the handle is invalid, if the object is already locked by another thread, or if the handle is not owned by the calling process.

## See also

[DRIVEROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-driverobj)