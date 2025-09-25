# TAPE_PROCESS_COMMAND_ROUTINE callback function

## Description

*TAPE_PROCESS_COMMAND_ROUTINE* handles the device-specific aspects of an IOCTL request.

## Parameters

### `MinitapeExtension` [in, out]

Pointer to the driver-specific minitape extension. This is **NULL** if the miniclass driver did not request a minitape extension when it initialized.

### `CommandExtension` [in, out]

Pointer to the command extension. This is **NULL** if the miniclass driver did not request a command extension when it initialized.

### `CommandParameters` [in, out]

Pointer to a buffer allocated by the caller that contains a [TAPE_CREATE_PARTITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_create_partition) structure.

### `Srb` [in, out]

Pointer to an SRB allocated and partially filled in by the tape class driver. *TAPE_PROCESS_COMMAND_ROUTINE* must fill in the CDB in the SRB.

* **Cdb** - Pointer to the SCSI CDB for the command. Clear the CDB with **TapeClassZeroMemory** before filling it in.
* **CdbLength** - Specifies the number of bytes in the CDB.

*TAPE_PROCESS_COMMAND_ROUTINE* might also fill in the following members in the SRB:

* **DataBuffer** - Pointer to the data buffer to be transferred. Use [TapeClassAllocateSrbBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclassallocatesrbbuffer) to allocate a **DataBuffer** of length greater than or equal to **DataTransferLength**.
* **DataTransferLength** - Specifies the number of bytes to be transferred in the SRB. This member is set by **TapeClassAllocateSrbBuffer**.
* **TimeOutValue** - Specifies a time-out value for this command, overriding the default time-out value from the tape class driver's device extension.
* **SrbFlags** - Specifies a flag for this command. The tape miniclass driver must set SRB_FLAGS_DATA_OUT if the SRB is sending data to the tape drive. This member can be zero if the SRB is requesting data from the tape drive or if no data is being transferred by the command.

### `CallNumber` [in]

Specifies the number of times *TAPE_PROCESS_COMMAND_ROUTINE* has been called to process a given tape command. *CallNumber* is zero the first time this routine is called and is incremented for each subsequent call until the miniclass driver returns a [TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status) value that indicates the command is complete.

### `StatusOfLastCommand` [in, optional]

Specifies the status of the last command. In the first call to *TAPE_PROCESS_COMMAND_ROUTINE* to process a given request, *StatusOfLastCommand* is TAPE_STATUS_SUCCESS. In subsequent calls, *StatusOfLastCommand* is either TAPE_STATUS_SUCCESS or an error status if an error occurred and the tape miniclass driver set RETURN_ERRORS in *RetryFlags* in the previous call.

### `RetryFlags` [in, out]

Pointer to a variable that specifies what action the tape class driver should take when a tape device reports an error.

The low-order word specifies the number of retries to perform in the event of a SCSI command failure. The default is zero (no retries).

The high-order word contains flags that specify how the tape class driver should return control if an error occurs:

* If RETURN_ERRORS and IGNORE_ERRORS are clear (the default) the tape class driver returns a failure status to the original requester.
* If the miniclass driver sets RETURN_ERRORS, the tape class driver calls *TAPE_PROCESS_COMMAND_ROUTINE* with *StatusOfLastCommand* set to a failure status.
* If the miniclass driver sets IGNORE_ERRORS, the tape class driver converts a failure status to success and calls *TAPE_PROCESS_COMMAND_ROUTINE* with *StatusOfLastCommand* set to success.

## Return value

| Return code | Description |
| --- | --- |
| **TAPE_STATUS_SEND_SRB_AND_CALLBACK** | Indicates to the tape class driver that the SRB has been filled in and is ready to be sent to the target device. By default, the tape class driver calls *TAPE_PROCESS_COMMAND_ROUTINE* again only if the SRB succeeds. A miniclass driver can modify the default behavior by setting *RetryFlags* before returning from *TAPE_PROCESS_COMMAND_ROUTINE*. |
| **TAPE_STATUS_CALLBACK** | Directs the tape class driver to increment *CallNumber* and call *TAPE_PROCESS_COMMAND_ROUTINE* again without sending an SRB to the tape device. |
| **TAPE_STATUS_CHECK_TEST_UNIT_READY** | Directs the tape class driver to fill in an SRB for the TEST UNIT READY command and send the SRB to the device. |
| **TAPE_STATUS_*XXX*** | Any other return code indicates to the tape class driver that the command is complete and indicates success, failure, or warning. Possible completion return values for this routine include, but are not limited to:<br><br>TAPE_STATUS_SUCCESS<br><br>TAPE_STATUS_INSUFFICIENT_RESOURCES<br><br>TAPE_STATUS_INVALID_DEVICE_REQUEST<br><br>TAPE_STATUS_INVALID_PARAMETER<br><br>TAPE_STATUS_IO_DEVICE_ERROR<br><br>TAPE_STATUS_MEDIA_WRITE_PROTECTED<br><br>TAPE_STATUS_NOT_IMPLEMENTED |

## Remarks

The following functions can be assigned to this callback placeholder:

### CreatePartition

*CreatePartition* handles the device-specific aspects of an [IOCTL_TAPE_CREATE_PARTITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_create_partition) request. This routine is required. *CreatePartition* creates a partition on a tape by filling in the CDB in an SRB passed by the tape class driver. Creating a partition typically requires a series of SRBs to complete the operation. After *CreatePartition* fills in a given SRB and returns, the tape class driver sends the SRB to the target device and, depending on the result of the SRB and the value of *RetryFlags*, calls *TapeMiniCreatePartition* again.

*CreatePartition* must fill in the following members in the SRB before returning to the tape class driver:

If the tape miniclass driver stores partition information in the minitape extension, *CreatePartition* updates the extension before returning to the tape class driver with TAPE_STATUS_SUCCESS.

### Erase

*Erase* handles the device-specific aspects of an [IOCTL_TAPE_ERASE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_erase) request. This routine is required. *Erase* erases a tape by filling in the CDB in an SRB passed by the tape class driver. Erasing a tape typically requires one SRB to complete the operation. After *Erase* fills in the SRB and returns, the tape class driver sends the SRB to the device and, depending on the result of the SRB and the value of *RetryFlags*, calls *Erase* again. *Erase* then returns TAPE_STATUS_SUCCESS.

### GetDriveParameters

*GetDriveParameters* handles the device-specific aspects of an [IOCTL_TAPE_GET_DRIVE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_get_drive_params) request. This routine is required. *GetDriveParameters* gets tape drive parameters by filling in the CDB in an SRB passed by the tape class driver. Getting drive parameters typically requires a series of SRBs to complete the operation. After *GetDriveParameters* fills in a given SRB and returns, the tape class driver sends the SRB to the target device and, depending on the result of the SRB and the value of *RetryFlags*, calls *GetDriveParameters* again.

### GetMediaParameters

*GetMediaParameters* handles the device-specific aspects of an [IOCTL_TAPE_GET_MEDIA_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_get_media_params) request. This routine is required. *GetMediaParameters* gets tape media parameters by filling in the CDB in an SRB passed by the tape class driver. Getting media parameters typically requires more than one SRB to complete the operation, starting with a test unit ready which the miniclass driver requests by returning TAPE_STATUS_CHECK_TEST_UNIT_READY the first time the tape class driver calls the routine.

After *GetMediaParameters* fills in a given SRB and returns, the tape class driver sends the SRB to the device and, depending on the result of the SRB and the value of *RetryFlags*, calls GetMediaParameters again.

### GetMediaTypes

*GetMediaTypes* handles the device-specific aspects of an [IOCTL_STORAGE_GET_MEDIA_TYPES_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_media_types_ex) request. This routine is required. *GetMediaTypes* gets information about the media types supported by a tape device by filling in the CDB in an SRB passed by the tape class driver. Getting media types typically requires more than one SRB to complete the operation, starting with a test unit ready which the miniclass driver requests by returning TAPE_STATUS_CHECK_TEST_UNIT_READY the first time the tape class driver calls the routine.

### GetPosition

*GetPosition* handles the device-specific aspects of an [IOCTL_TAPE_GET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_get_position) request. This routine is required. *GetPosition* reads the position of a tape by filling in the CDB in an SRB passed by the tape class driver. Reading tape position typically requires more than one SRB to complete the operation, often starting with a test unit ready which the miniclass driver requests by returning TAPE_STATUS_CHECK_TEST_UNIT_READY the first time the tape class driver calls the routine.

### GetStatus

*GetStatus* handles the device-specific aspects of an [IOCTL_TAPE_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_get_status) request. This routine is required. *GetStatus* reads the status of a tape device, typically by directing the tape class driver to issue a test unit ready command.

If a device indicates whether a drive needs cleaning in sense data (as opposed to reporting the need for cleaning as an error, which a miniclass driver would handle in its [TapeMiniTapeError](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_error_routine) routine), *GetStatus* fills in the CDB in the SRB passed by the tape class driver to obtain the sense data and, if necessary, returns TAPE_STATUS_REQUIRES_CLEANING.

### Prepare

*Prepare* handles the device-specific aspects of an [IOCTL_TAPE_PREPARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_prepare) request. This routine is required. *Prepare* prepares a tape by filling in the CDB in an SRB passed by the tape class driver. If the device supports the requested operation, preparing a tape typically requires one SRB. After *Prepare* fills in the SRB and returns, the tape class driver sends the SRB to the device and, depending on the result of the SRB and the value of *RetryFlags*, calls *Prepare* again.

### SetDriveParameters

*SetDriveParameters* handles the device-specific aspects of an [IOCTL_TAPE_SET_DRIVE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_set_drive_params) request. This routine is required. *SetDriveParameters* sets parameters for a tape device by filling in the CDB in an SRB passed by the tape class driver. Setting parameters typically involves a series of SRBs to complete the operation. After *SetDriveParameters* fills in a given SRB and returns, the tape class driver sends the SRB to the device and, depending on the result of the SRB and the value of *RetryFlags*, calls *SetDriveParameters* again.

### SetMediaParameters

*SetMediaParameters* handles the device-specific aspects of an [IOCTL_TAPE_SET_MEDIA_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_set_media_params) request. This routine is required. *SetMediaParameters* sets the block size of a tape by filling in the CDB in an SRB passed by the tape class driver. Setting the block size typically requires more than one SRB to complete the operation, starting with a test unit ready which the miniclass driver requests by returning TAPE_STATUS_CHECK_TEST_UNIT_READY the first time the tape class driver calls the routine.

After *SetMediaParameters* fills in a given SRB and returns, the tape class driver sends the SRB to the device and, depending on the result of the SRB and the value of *RetryFlags*, calls *SetMediaParameters* again.

### SetPosition

*SetPosition* handles the device-specific aspects of an [IOCTL_TAPE_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_set_position) request. This routine is required. *SetPosition* sets the position of a tape by filling in the CDB in an SRB passed by the tape class driver. Setting the position typically requires one SRB. After *SetPosition* fills in the SRB and returns, the tape class driver sends the SRB to the device and, depending on the result of the SRB and the value of *RetryFlags*, calls *SetPosition* again. *SetPosition* then returns TAPE_STATUS_SUCCESS.

### WriteMarks

*WriteMarks* handles the device-specific aspects of an [IOCTL_TAPE_WRITE_MARKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_write_marks) request. This routine is required. *WriteMarks* writes marks to a tape by filling in the CDB in an SRB passed by the tape class driver. Writing marks typically takes one SRB to complete the operation. After *WriteMarks* fills in the SRB and returns, the tape class driver sends the SRB to the device and, depending on the result of the SRB and the value of *RetryFlags*, calls *WriteMarks* again. *WriteMarks* then returns TAPE_STATUS_SUCCESS.

### PreProcessReadWrite

*PreProcessReadWrite* is an optional, special-purpose routine that performs any device-specific operations required before read and write operations. Most tape miniclass drivers do not need this routine. The activities of the *PreProcessReadWrite* routine are device specific. The routine can use the information passed to it by the class driver to implement special preprocessing for reads and writes. If a drive has limited capabilities, the driver may need this routine to maintain coherent state, for example.

If a tape miniclass driver sets a non-**NULL** entry point for this routine in the TAPE_INIT_DATA_EX structure it passes to [TapeClassInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclassinitialize) from its **DriverEntry** routine, the tape class driver calls it before each read and write operation on the tape device. The class driver does not expect any information back from this routine.

### WMIOperations

*WMIOperations* is the common entry point for all WMI calls from the tape class driver. A minidriver that supports WMI should set the function pointer member, **WMIOperations**, in the structure TAPE_INIT_DATA_EX to point to the minidriver's *TAPE_PROCESS_COMMAND_ROUTINE* routine. The minidriver should do this in its DriverEntry routine before calling [TapeClassInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclassinitialize). If a minidriver does not support WMI operations, it should set TapeWMIOperations field to **NULL**.

The tape class driver assigns values to the members of TAPE_WMI_OPERATIONS structure, and passes this structure to minidriver's *WMIOperations* routine in the *CommandParameters* parameter. As with other minidriver routines, *WMIOperations* fills, creates, and initializes the SCSI request blocks (SRB) and the command descriptor blocks (CDB) required to implement the indicated WMI method, and returns control to tape class driver. The tape class driver then calls the port driver to execute the request.

The minidriver returns the WMI data in the buffer pointed to by the **DataBuffer** member of the TAPE_WMI_OPERATIONS structure.

## See also

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeClassAllocateSrbBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclassallocatesrbbuffer)

[TapeClassZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclasszeromemory)