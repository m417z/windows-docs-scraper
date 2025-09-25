# IoIsErrorUserInduced macro

## Description

The **IoIsErrorUserInduced** routine determines whether an I/O error encountered while processing a request to a removable-media device was caused by the user.

## Parameters

### `Status` [in]

Specifies the current NTSTATUS value, usually within the driver's [DpcForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_dpc_routine) routine.

## Syntax

```cpp
BOOLEAN IoIsErrorUserInduced(
   Status
);
```

## Remarks

**IoIsErrorUserInduced** returns TRUE if an I/O request failed because of a user-induced error.

This routine indicates whether an I/O request failed for one of the following user-correctable conditions:

STATUS_DEVICE_NOT_READY

STATUS_IO_TIMEOUT

STATUS_MEDIA_WRITE_PROTECTED

STATUS_NO_MEDIA_IN_DEVICE

STATUS_UNRECOGNIZED_MEDIA

STATUS_VERIFY_REQUIRED

STATUS_WRONG_VOLUME

If **IoIsErrorUserInduced** returns **TRUE**, the removable-media driver must call [IoSetHardErrorOrVerifyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetharderrororverifydevice) before completing the IRP.

## See also

[IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry)

[IoSetHardErrorOrVerifyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetharderrororverifydevice)

[IoWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iowriteerrorlogentry)