# SENDCMDOUTPARAMS structure

## Description

The **SENDCMDOUTPARAMS** structure is used in conjunction with the **SMART_SEND_DRIVE_COMMAND** request to retrieve data returned by a Self-Monitoring Analysis and Reporting Technology (SMART) command.

## Members

### `cBufferSize`

Contains the size in bytes of the buffer pointed to by **bBuffer**.

### `DriverStatus`

Contains a [**DRIVERSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_driverstatus) structure that indicates the driver status.

### `bBuffer`

Pointer to a buffer in which to store the data read from the drive.

## Remarks

The **SENDCMDOUTPARAMS** structure is used with the **SMART_SEND_DRIVE_COMMAND** and **SMART_RCV_DRIVE_DATA** I/O control code requests. See the Remarks section of [**SENDCMDINPARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_sendcmdinparams) for details about these requests.

## See also

[**SENDCMDINPARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_sendcmdinparams)