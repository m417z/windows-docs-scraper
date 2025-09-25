# TAPE_ERROR_ROUTINE callback function

## Description

*TAPE_ERROR_ROUTINE* provides device-specific error handling when an SRB is completed with an error status. This routine is optional.

## Parameters

### `MinitapeExtension` [in]

Pointer to the driver-specific minitape extension. This is **NULL** if the miniclass driver did not request a minitape extension when it initialized.

### `Srb` [in]

Pointer to the SRB for the operation that failed.

### `TapeStatus` [in, out]

Pointer to the [TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status) set by the tape class driver. The tape miniclass driver can change the TAPE_STATUS or leave it unchanged.

## Remarks

Most tape miniclass drivers do not provide a *TAPE_ERROR_ROUTINE* routine because the [TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status) codes set by the tape class driver are appropriate.

For some devices, however, a tape miniclass driver can identify a more appropriate error code than the tape class driver. For example, if the tape class driver returns TAPE_STATUS_BUS_RESET, the tape miniclass driver might be able to determine that the real problem is more accurately represented by TAPE_STATUS_NO_MEDIA for some devices.

A tape miniclass driver optionally specifies an entry point for its *TAPE_ERROR_ROUTINE* routine in the TAPE_INIT_DATA_EX structure it passes to [TapeClassInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclassinitialize) from its **DriverEntry** routine. For such a miniclass driver, when an error occurs during a read, write, or device-control command, the tape class driver sets an appropriate TAPE_STATUS code and calls the miniclass driver's *TAPE_ERROR_ROUTINE* routine with the minitape extension, the failed SRB, and the TAPE_STATUS code that would be returned.

*TAPE_ERROR_ROUTINE* determines whether to alter the status provided by the tape class driver based on the input parameters and its knowledge of the device. If the SRB_STATUS_AUTOSENSE_VALID bit is set in **Srb->SrbStatus**, then the SRB contains SCSI sense information at **SenseInfoBuffer**. The length of the buffer is **SenseInfoBufferLength**. The *TAPE_ERROR_ROUTINE* routine should examine this information along with the **SrbStatus** and **ScsiStatus** in the SRB to determine whether to change the TAPE_STATUS returned.

## See also

[DriverEntry of Tape Miniclass Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-tape-miniclass-driver)

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[TAPE_INIT_DATA_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_tape_init_data_ex)

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeClassInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclassinitialize)