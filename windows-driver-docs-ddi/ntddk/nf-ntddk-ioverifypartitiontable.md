# IoVerifyPartitionTable function

## Description

The **IoVerifyPartitionTable** routine checks the validity of the partition table
for a disk.

## Parameters

### `DeviceObject` [in]

Specifies the device object of the disk to verify.

### `FixErrors` [in]

Specifies if the routine should correct any correctable errors in the partition table.

## Return value

The routine returns STATUS_SUCCESS if the partition table is error-free.

If the caller specifies **FALSE** for the *FixErrors* parameter
and the partition table has errors, the routine returns STATUS_DISK_CORRUPT_ERROR. If the caller specifies
**TRUE** for *FixErrors*, and the routine is able to correct all
errors in the partition table, it returns STATUS_SUCCESS. Otherwise it returns STATUS_DISK_CORRUPT_ERROR.

The routine might also return other NT status error codes.

## Remarks

**IoVerifyPartitionTable** must be used only by disk drivers.