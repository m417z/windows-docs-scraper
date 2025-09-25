# SENDCMDINPARAMS structure

## Description

The **SENDCMDINPARAMS** structure contains the input parameters for the **SMART_SEND_DRIVE_COMMAND** and **SMART_RCV_DRIVE_DATA** requests (see Remarks).

## Members

### `cBufferSize`

Contains the buffer size, in bytes.

### `irDriveRegs`

Contains a [**IDEREGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_ideregs) structure used to report the contents of the IDE controller registers.

### `bDriveNumber`

This member is opaque. Do not use it. The operating system ignores this member, because the physical drive that receives the request depends on the handle that the caller uses when making the request.

### `bReserved`

Reserved.

### `dwReserved`

Reserved.

### `bBuffer`

Pointer to the input buffer.

## Remarks

The **SENDCMDINPARAMS** structure is used with the **SMART_SEND_DRIVE_COMMAND** and **SMART_RCV_DRIVE_DATA** I/O control code requests. These IOCTLs must be handled by drivers that support Self-Monitoring Analysis and Reporting Technology (SMART).

### SMART_SEND_DRIVE_COMMAND

The **SMART_SEND_DRIVE_COMMAND** control code sends one of the following SMART commands to the device:

* Enable or disable reporting on the device
* Enable or disable autosaving of attributes
* Save current attributes now
* Execute offline diagnostics
* Get current SMART status
* Write to SMART log

#### Input Parameters

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a **SENDCMDINPARAMS** structure that describes the command being sent to the device. The **irDriveRegs.bCommandReg** member must specify SMART_CMD. The **irDriveRegs.bFeaturesReg** member must specify a SMART subcommand. For a list of subcommands, see [**IDEREGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_ideregs).

If the caller specifies a SMART subcommand of SMART_WRITE_LOG in **irDriveRegs.bFeaturesReg**, caller must also indicate the number of sectors to write in **irDriveRegs.bSectorCountReg**. The input buffer size must be >= ```sizeof(SENDCMDINPARAMS) - 1) + (irDriveRegs.bSectorCountReg * SMART_LOG_SECTOR_SIZE)```. Caller must put the data to write in the buffer indicated by the bBuffer member of **SENDCMDINPARAMS**.

**Parameters.DeviceIoControl.InputBufferLength** specifies the size in, bytes, of the input buffer, which must be >= ```(sizeof(SENDCMDINPARAMS) - 1)```.

**Parameters.DeviceIoControl.OutputBufferLength** specifies the size, in bytes, of the output buffer, which must be >= ```(sizeof(SENDCMDOUTPARAMS) - 1)```. If SMART status is being requested, the output buffer must be >= ```(sizeof(SENDCMDOUTPARAMS) - 1 + sizeof(IDEREGS))```.

#### Output Parameters

The driver returns the [**SENDCMDOUTPARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_sendcmdoutparams) structure to the buffer at **Irp->AssociatedIrp.SystemBuffer**. If SMART status was requested and successfully received from the device, the driver includes the **IDEREGS** structure in the output buffer.

#### I/O Status Block

When the driver sets the Status field to STATUS_SUCCESS, it sets the **Information** field is set to ```((sizeof(SENDCMDOUTPARAMS) - 1) + sizeof(IDEREGS))``` for returning SMART status and to ```(sizeof(SENDCMDOUTPARAMS) - 1)``` for all other commands. The driver should set the **Status** field to STATUS_INVALID_PARAMETER if an input parameter is incorrect or to STATUS_IO_DEVICE_ERROR if the device aborts a command it does not support. If **Status** is not STATUS_SUCCESS, the driver sets the **Information** field to zero.

### SMART_RCV_DRIVE_DATA

The **SMART_RCV_DRIVE_DATA** control code returns the ATA-2 identify data, the SMART thresholds, or the SMART attributes for the device.

#### SMART_RCV_DRIVE_DATA Input Parameters

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a **SENDCMDINPARAMS** structure that describes the request being sent to the device. The **irDriveRegs.bCommandReg** member specifies ID_CMD when identify data is requested and SMART_CMD when SMART data is requested. For a list of values that can be assigned to the features register (irDriveRegs.bFeaturesReg), see [**IDEREGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_ideregs).

**Parameters.DeviceIoControl.InputBufferLength** specifies the size, in bytes, of the input buffer, which must be >= ```(sizeof(SENDCMDINPARAMS) - 1)```.

**Parameters.DeviceIoControl.OutputBufferLength** specifies the size, in bytes, of the output buffer, which must be >= ```(sizeof(SENDCMDOUTPARAMS) - 1 + 512)```.

#### SMART_RCV_DRIVE_DATA Output Parameters

The driver returns the [**SENDCMDOUTPARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_sendcmdoutparams) structure and a 512-byte buffer of drive data to the buffer at **Irp->AssociatedIrp.SystemBuffer**.

If the caller specifies a SMART subcommand of SMART_READ_LOG in **irDriveRegs.bFeaturesReg**, the caller must also indicate the number of sectors to read in **irDriveRegs.bSectorCountReg**. The output buffer size must be >= the maximum of the following values: ```sizeof(SENDCMDOUTPARAMS)``` or ```sizeof(SENDCMDINPARAMS)) -1 + (irDriveRegs.bSectorCountReg** * SMART_LOG_SECTOR_SIZE)```

The data read from the log will be placed in the buffer specified by the **bBuffer** member of [**SENDCMDOUTPARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_sendcmdoutparams).

#### SMART_RCV_DRIVE_DATA I/O Status Block

The driver sets the **Information** field to ```(sizeof(SENDCMDOUTPARAMS) - 1 + 512)``` when it sets the **Status** field to STATUS_SUCCESS. Otherwise, the driver sets the **Information** field to zero and the **Status** field to possibly STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## See also

[**IDEREGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_ideregs)

[**SENDCMDOUTPARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_sendcmdoutparams)