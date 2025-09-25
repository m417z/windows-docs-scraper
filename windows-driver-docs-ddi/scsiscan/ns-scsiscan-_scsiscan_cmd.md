# _SCSISCAN_CMD structure

## Description

The SCSISCAN_CMD structure is used as a parameter to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), when the specified I/O control code is [IOCTL_SCSISCAN_CMD](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiscan/ni-scsiscan-ioctl_scsiscan_cmd).

## Members

### `Reserved1`

Reserved. Do not use.

### `Size`

Caller-supplied size, in bytes, of the SCSISCAN_CMD structure.

### `SrbFlags`

Caller-supplied SRB_FLAGS-prefixed bit flag specifying the requested operation. Flags are defined in *srb.h*.

### `CdbLength`

Length, in bytes, of the [CDB](https://learn.microsoft.com/windows-hardware/drivers/) contained in the **Cdb** member.

### `SenseLength`

Length, in bytes, of the sense buffer the **pSenseBuffer** member points to.

### `Reserved2`

Reserved. Do not use.

### `Reserved3`

Reserved. Do not use.

### `TransferLength`

Length, in bytes, of the buffer to be transferred. This should match the value specified for the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function's *nOutBufferSize* parameter.

### `Cdb`

Caller-supplied [CDB](https://learn.microsoft.com/windows-hardware/drivers/) data. (The CDB structure is declared in *scsi.h*.)

### `pSrbStatus`

Caller-supplied pointer that will receive one of the SRB_STATUS-prefixed status values defined in *srb.h*.

### `pSenseBuffer`

Caller-supplied pointer to a request-sense buffer, to be filled in by the kernel-mode driver.