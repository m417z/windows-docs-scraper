# HalExamineMBR function

## Description

The **HalExamineMBR** routine reads the master boot record (MBR) of a disk and returns data from the MBR if the MBR is of the type specified by the caller.

## Parameters

### `DeviceObject` [in]

A pointer to the device object for the device being examined.

### `SectorSize` [in]

The minimum number of bytes that an I/O operation can fetch from the device being examined. If this value is less than 512, **HalExamineMBR** reads 512 bytes to ensure that it reads an entire partition table.

### `MBRTypeIdentifier` [in]

MBR partition type identifier. This parameter specifies the type of MBR that may be on the disk. For more information, see Remarks.

### `Buffer` [out]

A pointer to a location to which **HalExamineMBR** writes a pointer to a buffer that contains data from the MBR. The layout of the buffer depends on the MBR partition type. **HalExamineMBR** allocates the storage for this buffer. The caller must deallocate this buffer as soon as possible by calling the [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) routine.

**HalExamineMBR** sets **Buffer* = **NULL** if the MBR partition type of the disk does not match that specified by *MBRTypeIdentifier* or if there is an error.

## Remarks

For a list of system-defined MBR partition type identifiers, see the table in [PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information). These identifiers are defined in the Ntdddisk.h header file.

## See also

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information)