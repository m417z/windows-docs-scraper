# WdfRequestGetUserModeDriverInitiatedIo function

## Description

[Applies to UMDF only]

The **WdfRequestGetUserModeDriverInitiatedIo** method determines whether an I/O request is marked as initiated by a UMDF driver.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

The method returns **TRUE** if the request is marked as UMDF driver-initiated and **FALSE** if the request is not marked as UMDF driver-initiated.

## Remarks

 This method retrieves the value of the **IRP_UM_DRIVER_INITIATED_IO** flag in the **Flags** member of the WDM [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure corresponding to the I/O request.

For more information about using this flag, see [WdfRequestSetUserModeDriverInitiatedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetusermodedriverinitiatedio).

## See also

[WdfRequestSetUserModeDriverInitiatedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetusermodedriverinitiatedio)