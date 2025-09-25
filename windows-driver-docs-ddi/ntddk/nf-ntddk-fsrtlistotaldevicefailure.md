# FsRtlIsTotalDeviceFailure function (ntddk.h)

## Description

The **FsRtlIsTotalDeviceFailure** routine determines whether a media or other hardware failure has occurred.

## Parameters

### `Status` [in]

Specifies the current NTSTATUS value, usually within a file system's or fault-tolerant disk driver's completion routine.

## Return value

The **FsRtlIsTotalDeviceFailure** routine returns **TRUE** if an I/O request failed because the physical device has failed.

## Remarks

If **FsRtlIsTotalDeviceFailure** returns **TRUE**, a higher-level driver, such as a file system or fault-tolerant disk driver, usually logs an error before completing the IRP.

**FsRtlIsTotalDeviceFailure** does not return **TRUE** for either of the status values STATUS_DEVICE_DATA_ERROR and STATUS_CRC_ERROR, which are assumed to indicate a sector failure rather than a total disk failure.

For more information about handling device failure, see [Error Handling](https://learn.microsoft.com/windows/win32/seccrypto/common-hresult-values).

## See also

[FsRtlIsNtstatusExpected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlisntstatusexpected)

[FsRtlNormalizeNtstatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnormalizentstatus)

[IoWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iowriteerrorlogentry)