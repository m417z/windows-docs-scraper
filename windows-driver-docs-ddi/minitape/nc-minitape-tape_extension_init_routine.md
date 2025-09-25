# TAPE_EXTENSION_INIT_ROUTINE callback function

## Description

*ExtensionInit* initializes an optional, driver-specific context area. This routine is called by [TapeClassInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclassinitialize) when the tape miniclass driver is loaded. This routine is optional.

## Parameters

### `MinitapeExtension` [in]

Pointer to a buffer of the size requested by the tape miniclass driver when it initialized.

### `InquiryData` [in]

Pointer to the SCSI inquiry data for the tape device.

### `ModeCapabilitiesPage` [in]

Pointer to a buffer that contains low-level information for the tape device. The format of this page is defined by the QIC 157 standard and is subject to change. This is **NULL** if the device does not support a mode capabilities page.

## Remarks

A tape miniclass driver requests a minitape extension by specifying a nonzero value for **MinitapeExtensionSize** in the [TAPE_INIT_DATA_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_tape_init_data_ex) structure it passes to [TapeClassInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclassinitialize) from its **DriverEntry** routine. A miniclass driver defines the structure and contents of the minitape extension and typically uses it to store inquiry data for the devices it supports.

The tape class driver allocates the minitape extension and supplies it subsequently in calls to the tape miniclass driver's routines that handle the device-specific aspects of device-control requests and to the miniclass driver's optional [TapeMiniTapeError](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_error_routine) routine.

*ExtensionInit* initializes the minitape extension, and the miniclass driver uses this area to maintain run-time state for its device. The tape class driver passes *InquiryData* and a *ModeCapabilitiesPage* to this routine because those structures contain information that a tape miniclass driver might want to store in the minitape extension.

## See also

[DriverEntry of Tape Miniclass Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-tape-miniclass-driver)

[TAPE_INIT_DATA_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-_tape_init_data_ex)

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeClassInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclassinitialize)

[TapeMiniTapeError](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_error_routine)