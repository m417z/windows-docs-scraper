# EngMapEvent function

## Description

The **EngMapEvent** function maps a user-mode event object to kernel mode.

## Parameters

### `hDev` [in]

Handle to the physical device associated with the event. This is the GDI handle passed as the *hdev* parameter to the driver's [DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev) function.

### `hUserObject` [in]

Handle to the user-mode event to be mapped.

### `Reserved1`

Is reserved for system use, and must be set to **NULL**.

### `Reserved2`

Is reserved for system use, and must be set to **NULL**.

### `Reserved3`

Is reserved for system use, and must be set to **NULL**.

## Return value

**EngMapEvent** returns a pointer to an event object on success. Otherwise, it returns **NULL**.

## Remarks

After successfully mapping the user event, **EngMapEvent** automatically sets the event object to the signaled state, attempts to satisfy as many waits as possible, and then resets the event object to the nonsignaled state.

A mapped event provides a mechanism by which an application can wait for a kernel-mode graphics operation to complete. The display driver or video miniport driver signals the application when it is done using the resource for which the event was mapped, thus freeing the application to use the resource.

Display and miniport drivers cannot wait for mapped events, but can set or clear them.

The driver can also perform its own cleanup by calling [EngUnmapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunmapevent) on the event object returned by **EngMapEvent**.

## See also

[DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev)

[EngUnmapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunmapevent)