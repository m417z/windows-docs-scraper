## Description

The **CONFIGURATION_INFORMATION** structure contains the overall system device configuration record.

## Members

### `DiskCount`

Number of hard disks in the system thus far. A driver can use this number to determine the names of new disks. The driver should update this value as it finds new disks.

### `FloppyCount`

Number of floppy disks in the system thus far. A driver can use this number to determine the names of new disks. The driver should update this value as it finds new disks.

### `CdRomCount`

Number of CD-ROM drives in the system thus far. A driver can use this number to determine the names of new drives. The driver should update this value as it finds new drives.

### `TapeCount`

Number of tape drives in the system thus far. A driver can use this number to determine the names of new drives. The driver should update this value as it finds new drives.

### `ScsiPortCount`

Number of SCSI port adapters in the system thus far. A driver can use this number to determine the names of new SCSI port adapters. The driver should update this value as it finds new adapters.

### `SerialCount`

Number of serial devices in the system thus far. A driver can use this number to determine the names of new serial devices. The driver should update this value as it finds new devices.

### `ParallelCount`

Number of parallel devices in the system thus far. A driver can use this number to determine the names of new parallel devices. The driver should update this value as it finds new devices.

### `AtDiskPrimaryAddressClaimed`

Boolean that indicates ownership of the 0x1F0-0x1FF space of the two I/O address spaces used by WD1003-compatible disk controllers.

### `AtDiskSecondaryAddressClaimed`

Boolean that indicates ownership of the 0x170-0x17F space of the two I/O address spaces used by WD1003-compatible disk controllers.

### `Version`

The version of this structure. Set to ```sizeof(CONFIGURATION_INFORMATION)```.

### `MediumChangerCount`

Number of medium changer devices in the system. A driver can use this number to determine the names of new medium changer devices. The driver should update this value as it finds new devices.

## Remarks

**CONFIGURATION_INFORMATION** can be used as follows:

* By drivers that are initializing to determine the number of devices of a particular type that have already been initialized.
* To track whether or not the AtDisk address range has already been claimed.
* By the [**IoGetConfigurationInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetconfigurationinformation) system service to return device type counts.

## See also

[**IoGetConfigurationInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetconfigurationinformation) (*ntddk.h*)

[**IoGetConfigurationInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetconfigurationinformation) (*ntifs.h*)