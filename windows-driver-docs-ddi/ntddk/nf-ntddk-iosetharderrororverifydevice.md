# IoSetHardErrorOrVerifyDevice function

## Description

Lower-level drivers call the **IoSetHardErrorOrVerifyDevice** routine to identify a removable media device that has encountered an error, so that a file system driver can prompt the user to verify that the medium is valid.

## Parameters

### `Irp` [in]

Pointer to the IRP for which the driver encountered a user-induced error.

### `DeviceObject` [in]

Pointer to the target device to be verified for the I/O operation.

## Remarks

Lower-level drivers for removal media devices must call **IoSetHardErrorOrVerifyDevice** before completing an IRP, if a call to [IoIsErrorUserInduced](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioiserroruserinduced) returns **TRUE**. For more information, see [Supporting Removable Media](https://learn.microsoft.com/windows-hardware/drivers/kernel/supporting-removable-media).

Subsequently, a file system driver will use information supplied in the specified device object to send a dialog box to the user, who can correct the error and retry the operation or cancel it.

The IRP passed to **IoSetHardErrorOrVerifyDevice** must be associated with a thread. Therefore, before a driver calls **IoSetHardErrorOrVerifyDevice**, it must verify that *irp***->Tail.Overlay**.Thread is not **NULL**. If the value is **NULL**, **IoSetHardErrorOrVerifyDevice** must not be called using the current IRP. Instead, the driver should check all IRPs subsequently received and processed, until one is received for which *irp***->Tail.Overlay**.Thread is not **NULL**. At that point, **IoSetHardErrorOrVerifyDevice** can be called.

## See also

[IoIsErrorUserInduced](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioiserroruserinduced)

[IoRaiseHardError](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioraiseharderror)

[IoRaiseInformationalHardError](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioraiseinformationalharderror)