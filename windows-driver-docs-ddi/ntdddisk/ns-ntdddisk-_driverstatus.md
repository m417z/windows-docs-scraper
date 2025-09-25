# _DRIVERSTATUS structure

## Description

The DRIVERSTATUS structure is used in conjunction with the [SENDCMDOUTPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_sendcmdoutparams) structure and the [SMART_SEND_DRIVE_COMMAND](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566206(v=vs.85)) request to retrieve data returned by a Self-Monitoring Analysis and Reporting Technology (SMART) command.

## Members

### `bDriverError`

Error code from driver, or 0 if no error.

### `bIDEError`

Contents of IDE Error register.

### `bReserved`

Reserved.

### `dwReserved`

Reserved.

## See also

[SENDCMDOUTPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_sendcmdoutparams)

[SMART_SEND_DRIVE_COMMAND](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566206(v=vs.85))