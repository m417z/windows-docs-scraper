# IWDFIoRequest3::SetUserModeDriverInitiatedIo

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetUserModeDriverInitiatedIo** method
indicates to kernel-mode drivers that sit below the UMDF driver in the same device stack that a particular request should be treated as though it came from a UMDF driver.

## Parameters

### `IsUserModeDriverInitiated` [in]

A Boolean value that, if **TRUE**, indicates that the request should be treated as though it was initiated by a UMDF driver. If **FALSE**, this parameter indicates that the request should be treated as though it came from an application.

## Remarks

If a UMDF driver calls this method with the *IsUserModeDriverInitiated* parameter set to **TRUE**, the framework sets the IRP_UM_DRIVER_INITIATED_IO flag in the **Flags** member of the WDM [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure before forwarding the request to kernel-mode drivers.

A kernel-mode driver that resides below the UMDF driver in the same device stack can check for this flag to determine if the request should be treated as though initiated by a UMDF driver.

This flag is not applicable to kernel-mode drivers that might receive a request from a UMDF driver via a file-handle I/O target or a Win32 I/O target.

A UMDF driver might set the *IsUserModeDriverInitiated* parameter to **TRUE** for a request that came from an application if the driver has validated the request.

Requests that the driver created on its own are already marked as having originated from a UMDF driver.

The UMDF 2 equivalent of this method is [WdfRequestSetUserModeDriverInitiatedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetusermodedriverinitiatedio).

## See also

[GetUserModeDriverInitiatedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest3-getusermodedriverinitiatedio)

[IWDFIoRequest3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest3)

[WdfRequestSetUserModeDriverInitiatedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetusermodedriverinitiatedio)