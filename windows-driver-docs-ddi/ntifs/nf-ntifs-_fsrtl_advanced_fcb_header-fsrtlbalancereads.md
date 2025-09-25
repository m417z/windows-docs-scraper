# FsRtlBalanceReads function

## Description

The **FsRtlBalanceReads** routine signals to a fault-tolerant disk driver that it is now safe to start balancing reads from a mirrored drive.

## Parameters

### `TargetDevice` [in]

A pointer to the device object from which the device starts the balanced read.

## Return value

**FsRtlBalanceReads** returns STATUS_INVALID_DEVICE_REQUEST if the device is not a mirror.

## Remarks

**FsRtlBalanceReads** signals to a fault-tolerant disk driver that it is safe to start balancing reads from a mirrored drive. A file system typically calls **FsRtlBalanceReads** for a newly mounted volume once it has determined that the volume is clean.

## See also

[CcIsThereDirtyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccistheredirtydata)