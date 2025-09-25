# EngCreateDriverObj function

## Description

The **EngCreateDriverObj** function creates a [DRIVEROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-driverobj) structure.

## Parameters

### `pvObj`

Pointer to the driver resource that will be tracked by the DRIVEROBJ structure. The resource is associated with the current client process.

### `pFreeObjProc`

Pointer to a driver-supplied callback function that frees the resource pointed to by *pvObj*. The callback function should be defined as follows, where *pDriverObj* points to the DRIVEROBJ structure:

```
BOOL CALLBACK DrvobjFreeObjProc(DRIVEROBJ *pDriverObj);
```

### `hdev`

Handle to the physical device associated with the object. This parameter is the GDI handle received by the driver's [DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev) function.

## Return value

The return value is a handle that identifies the newly-created DRIVEROBJ structure if the function is successful. Otherwise, it is zero.

## Remarks

This structure is used to track a device-managed resource that must be released if the resource-allocating process terminates without first cleaning it up.

The driver can explicitly delete the DRIVEROBJ structure by calling [EngDeleteDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletedriverobj). Otherwise, the engine frees the resource by calling the function pointed to by *pFreeObjProc* when the process that created the DRIVEROBJ terminates.

## See also

[DRIVEROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-driverobj)

[EngDeleteDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletedriverobj)