# _BOOTDISK_INFORMATION structure

## Description

The **BOOTDISK_INFORMATION** structure contains basic information describing the boot and system disks.

## Members

### `BootPartitionOffset`

Specifies the offset, in bytes, on the boot disk where the boot partition begins.

### `SystemPartitionOffset`

Specifies the offset, in bytes, on the system disk where the system partition begins.

### `BootDeviceSignature`

If the boot disk is formatted with an MBR partition table, this specifies the signature for the disk's MBR partition table. Otherwise, this member is unused.

### `SystemDeviceSignature`

If the system disk is formatted with an MBR partition table, this specifies the signature for the disk's MBR partition table. Otherwise, this member is unused.

## Remarks

[IoGetBootDiskInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetbootdiskinformation) returns this structure to describe the boot and system disks.

## See also

[BOOTDISK_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bootdisk_information_ex)

[IoGetBootDiskInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetbootdiskinformation)