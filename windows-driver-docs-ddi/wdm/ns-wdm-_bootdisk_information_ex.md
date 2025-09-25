# _BOOTDISK_INFORMATION_EX structure

## Description

The **BOOTDISK_INFORMATION_EX** structure contains extended information describing the boot and system disks.

## Members

### `BootPartitionOffset`

Specifies the offset, in bytes, on the boot disk where the boot partition begins.

### `SystemPartitionOffset`

Specifies the offset, in bytes, on the system disk where the system partition begins.

### `BootDeviceSignature`

If the **BootDeviceIsGpt** member is **FALSE**, this specifies the signature for the disk's MBR partition table. Otherwise, this member is unused.

### `SystemDeviceSignature`

If the **SystemDeviceIsGpt** member is **FALSE**, this specifies the signature for the disk's MBR partition table. Otherwise, this member is unused.

### `BootDeviceGuid`

If the **BootDeviceIsGpt** member is **TRUE**, this specifies the GUID for the boot disk. Otherwise, this member is unused.

### `SystemDeviceGuid`

If the **SystemDeviceIsGpt** member is **TRUE**, this specifies the GUID for the boot disk. Otherwise, this member is unused.

### `BootDeviceIsGpt`

**TRUE** if the boot disk is formatted with the GPT partition table type.

### `SystemDeviceIsGpt`

**TRUE** if the system disk is formatted with the GPT partition table type.

## Remarks

On Windows XP and later, [IoGetBootDiskInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetbootdiskinformation) returns this structure to describe the boot and system disks.

## See also

[BOOTDISK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bootdisk_information)

[IoGetBootDiskInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetbootdiskinformation)