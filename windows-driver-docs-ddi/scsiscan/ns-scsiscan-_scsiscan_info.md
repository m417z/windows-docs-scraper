# _SCSISCAN_INFO structure

## Description

The SCSISCAN_INFO structure is used as a parameter to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), when the specified I/O control code is [IOCTL_SCSISCAN_GET_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiscan/ni-scsiscan-ioctl_scsiscan_get_info).

## Members

### `Size`

Size, in bytes, of the SCSISCAN_INFO structure.

### `Flags`

Not used, must be zero.

### `PortNumber`

SCSI adapter number.

### `PathId`

Host SCSI ID.

### `TargetId`

Target SCSI ID.

### `Lun`

Target logical unit number (LUN).

### `AdapterName`

*For internal use only.*

### `Reserved`

*For internal use only.*