# DRIVEROBJ structure

## Description

The DRIVEROBJ structure is used to track a resource, allocated by a driver, that requires use GDI services. A DRIVEROBJ structure allows a display driver to request the GDI service in managing per-process resources. By creating a DRIVEROBJ structure, a display driver can ensure that resources will be released when an application terminates.

## Members

### `pvObj`

Pointer to the driver resource that will be tracked by the DRIVEROBJ structure. The resource is associated with the current client process.

### `pFreeProc`

Pointer to a driver-supplied callback function that frees the resource pointed to by **pvObj**. This callback function has the following prototype:

```
BOOL (CALLBACK * FREEOBJPROC) (DRIVEROBJ * pDriverObj);
```

The callback function returns **TRUE** if it is able to free the resource, and **FALSE** otherwise.

### `hdev`

GDI handle to the physical device associated with the object.

### `dhpdev`

Pointer to the driver's private instance data; that is, this member identifies the driver's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/).

## Remarks

A DRIVEROBJ structure allows a display driver to request the GDI service in managing per-process resources. By creating a DRIVEROBJ structure, a display driver can ensure that resources will be released when an application terminates.

Some drivers, in their Escape support, allocate resources on behalf of applications. In such cases, the DRIVEROBJ structure provides a means for the application to notify the driver when it terminates. GDI will call the driver's cleanup function for each DRIVEROBJ structure allocated in an application's context that is not deleted before the application terminates.

This structure provides a locking mechanism for exclusive access to the associated resource.

## See also

[EngCreateDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedriverobj)

[EngDeleteDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletedriverobj)

[EngLockDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-englockdriverobj)

[EngUnlockDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunlockdriverobj)