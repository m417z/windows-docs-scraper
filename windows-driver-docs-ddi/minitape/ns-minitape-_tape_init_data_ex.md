# TAPE_INIT_DATA_EX structure

## Description

TAPE_INIT_DATA_EX defines values and routines that are specific to a Windows 2000 tape miniclass driver. The tape miniclass **DriverEntry** routine passes this information to the tape class driver to complete miniclass driver initialization.

## Members

### `InitDataSize`

Size of this structure, in bytes.

### `VerifyInquiry`

Specifies the entry point of the tape miniclass driver's [**TapeMiniVerifyInquiry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_verify_inquiry_routine) routine, which determines whether the driver supports a given device. This routine is required.

### `QueryModeCapabilitiesPage`

Directs the tape class driver when **TRUE** to pass a mode capabilities page to the tape miniclass driver's [**TapeMiniVerifyInquiry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_verify_inquiry_routine) and [**TapeMiniExtensionInit**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_extension_init_routine) routines.

### `MinitapeExtensionSize`

Specifies the size, in bytes, of a driver-specific context area. If this member is nonzero, **ExtensionInit** must not be **NULL**. This value is optional and must be set to zero if not used.

### `ExtensionInit`

Pointer to the tape miniclass driver's [**TapeMiniExtensionInit**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_extension_init_routine) routine, which initializes an optional minitape extension, if any. If **MiniTapeExtensionSize** is zero, **ExtensionInit** must be **NULL**.

### `DefaultTimeOutValue`

Specifies the number of seconds that the tape class driver waits for an SRB request before canceling it. If this value is zero, the tape class driver sets an appropriate default value. The tape class driver always uses the default time-out value for read and write requests. The routines contained in the TAPE_INIT_DATA_EX structure can override the default time-out value for device control requests by setting **TimeOutValue** in an SRB.

### `TapeError`

Pointer to the tape miniclass driver's [**TapeMiniTapeError**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_error_routine) routine, which augments the error-handling activities of the tape class driver. This routine is optional. If one is not used, **TapeError** must be set to **NULL**.

### `CommandExtensionSize`

Specifies the size, in bytes, of a command extension to be allocated before the start of each tape command. A tape miniclass driver uses the command extension to store context during the processing of tape commands. Its size and internal structure are defined by the tape miniclass driver. A command extension is optional. If one is not used, **CommandExtensionSize** must be set to zero.

### `CreatePartition`

Pointer to the tape miniclass driver's [**TapeMiniCreatePartition**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which creates a partition on a tape. This routine is required.

### `Erase`

Pointer to the tape miniclass driver's [**TapeMiniErase**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which erases a tape. This routine is required.

### `GetDriveParameters`

Pointer to the tape miniclass driver's [**TapeMiniGetDriveParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which handles requests to get drive parameters. This routine is required.

### `GetMediaParameters`

Pointer to the tape miniclass driver's [**TapeMiniGetMediaParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which handles requests to get media parameters. This routine is required.

### `GetPosition`

Pointer to the tape miniclass driver's [**TapeMiniGetPosition**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which handles requests to get the position of a tape. This routine is required.

### `GetStatus`

Pointer to the tape miniclass driver's [**TapeMiniGetStatus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which handles requests for status. This routine is required.

### `Prepare`

Pointer to the tape miniclass driver's [**TapeMiniPrepare**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which prepares a tape device. This routine is required.

### `SetDriveParameters`

Pointer to the tape miniclass driver's [**TapeMiniSetDriveParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which sets drive parameters. This routine is required.

### `SetMediaParameters`

Pointer to the tape miniclass driver's [**TapeMiniSetMediaParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which sets media parameters. This routine is required.

### `SetPosition`

Pointer to the tape miniclass driver's [**TapeMiniSetPosition**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which positions a tape. This routine is required.

### `WriteMarks`

Pointer to the tape miniclass driver's [**TapeMiniWriteMarks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which writes marks to tape. This routine is required.

### `PreProcessReadWrite`

Pointer to the tape miniclass driver's [**TapeMiniPreProcessReadWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which executes device-specific operations before all reads and writes. This routine is optional and is not needed by most drivers. If one is not used, **PreProcessReadWrite** must be **NULL**.

### `TapeGetMediaTypes`

Pointer to the tape miniclass driver's [**TapeMiniGetMediaTypes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine, which gets a description of each media type supported by a tape device. This routine is required.

### `MediaTypesSupported`

Indicates the number of media types supported by the device.

### `TapeWMIOperations`

Pointer to the [**TapeMiniWMIControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine.

### `Reserved`

Reserved.

## Remarks

A tape miniclass driver's **DriverEntry** routine calls [**TapeClassZeroMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclasszeromemory) to clear TAPE_INIT_DATA_EX, fills in the required members and any appropriate optional members, and [**TapeClassInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclassinitialize) with a pointer to this structure.

The names of the tape miniclass driver routines indicated in the member descriptions of this structure are just placeholder names. The prototype for these routines is declared in *newtape.h* as [**TAPE_PROCESS_COMMAND_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine).

The meaning of this prototype's parameters are different for each miniclass driver routine. For detailed information about how these parameters are used see the descriptions for each individual miniclass driver routine.

## See also