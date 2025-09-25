# WdfRequestSetUserModeDriverInitiatedIo function

## Description

[Applies to UMDF only]

The **WdfRequestSetUserModeDriverInitiatedIo** method indicates to kernel-mode drivers that sit below the UMDF driver in the same device stack that a particular request should be treated as though it came from a UMDF driver.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `IsUserModeDriverInitiated` [in]

A Boolean value that, if **TRUE**, indicates that the request should be treated as though it was initiated by a UMDF driver. If **FALSE**, this parameter indicates that the request should be treated as though it came from an application.

## Remarks

If a UMDF driver calls this method with the *IsUserModeDriverInitiated* parameter set to **TRUE**, the framework sets the **IRP_UM_DRIVER_INITIATED_IO** flag in the **Flags** member of the WDM [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure before forwarding the request to kernel-mode drivers.

A kernel-mode driver that resides below the UMDF driver in the same device stack can check for this flag to determine if the request should be treated as though initiated by a UMDF driver.

This flag is not applicable to kernel-mode drivers that might receive a request from a UMDF driver via a file-handle I/O target or a Win32 I/O target.

A UMDF driver might set the *IsUserModeDriverInitiated* parameter to **TRUE** for a request that came from an application if the driver has validated the request.

Requests that the driver created on its own are already marked as having originated from a UMDF driver.

## See also

[WdfRequestGetUserModeDriverInitiatedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetusermodedriverinitiatedio)