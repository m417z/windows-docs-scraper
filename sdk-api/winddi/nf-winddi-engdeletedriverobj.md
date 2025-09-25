# EngDeleteDriverObj function

## Description

The **EngDeleteDriverObj** function frees the handle used for tracking a device-managed resource.

## Parameters

### `hdo`

Handle to the driver object that is to be deleted. This GDI handle was obtained from [EngCreateDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedriverobj).

### `bCallBack`

Specifies whether the cleanup callback should be called. If **TRUE**, GDI invokes the cleanup callback before removing the [DRIVEROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-driverobj) from the handle manager. If **FALSE**, GDI does not do so. If the callback function returns failure, **EngDeleteDriverObj** will fail.

### `bLocked`

Specifies whether the object was locked by the driver (through a call to [EngLockDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-englockdriverobj)) before **EngDeleteDriverObj** was called. If **TRUE**, the object was locked; if **FALSE**, the object was not locked.

## Return value

The return value is **TRUE** if the function is successful and the handle is freed; it is **FALSE** if the handle has not been freed. If the *pFreeObjProc* driver function specified in **EngCreateDriverObj** returns **FALSE**, then **EngDeleteDriverObj** will fail and the handle won't be freed. This could happen if the cleanup callback needs to lock another DRIVEROBJ structure (in order to free the current DRIVEROBJ structure ) and fails because the other DRIVEROBJ structure is in use by another thread.

## Remarks

After the handle is freed, the associated driver resource is no longer tracked by GDI and the function pointed to by the *pFreeObjProc* parameter of [EngCreateDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedriverobj) *will not* be called upon process termination. It is the responsibility of the driver to ensure that the resource is freed.

Most drivers should be consistent in how objects are cleaned up at termination time. Consequently, they will pass **TRUE** for *bCallback*, indicating to GDI that it should call the driver's cleanup function to free this driver resource.

The *bCallBack* parameter indicates to GDI whether the callback function needs to be called. Passing **TRUE** for *bCallBack* tells GDI to call the driver's cleanup function back to free this driver resource. Passing **FALSE** prevents GDI from calling the cleanup function. If *pFreeObjProc* returns **FALSE**, **EngDeleteDriverObj** fails and the handle won't be freed. For example, this could happen if the *pFreeObjProc* needed to lock down another DRIVEROBJ structure to free the current DRIVEROBJ structure and failed because the structure was being used by another thread. The *pFreeObjProc* should never fail at cleanup time, because no threads, other than the cleanup thread, are running, so locks of other objects won't fail.

The *bLocked* parameter indicates to GDI that the object has already been locked once by the driver. Often, before an object is deleted, the driver might have locked it down to use first. This allows the driver to call GDI without first having to unlock the object, thus eliminating the possibility that another thread could enter the driver and lock it down before the handle is freed.

## See also

[DRIVEROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-driverobj)

[EngCreateDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedriverobj)