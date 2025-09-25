# TAPE_VERIFY_INQUIRY_ROUTINE callback function

## Description

*TAPE_VERIFY_INQUIRY_ROUTINE* determines whether the tape miniclass driver recognizes and supports a given device. This routine is required.

## Parameters

### `InquiryData` [in]

Pointer to SCSI inquiry data for the device.

### `ModeCapabilitiesPage` [in]

Pointer to a MODE_CAPABILITIES_PAGE structure that contains low-level information about the device. The format of this structure is defined by the QIC 157 standard and is subject to change. The pointer is **NULL** if the tape device does not support a mode capabilities page.

## Return value

*TAPE_VERIFY_INQUIRY_ROUTINE* returns **TRUE** if the miniclass driver supports the device.

## Remarks

*TAPE_VERIFY_INQUIRY_ROUTINE* examines the *InquiryData*, particularly the **VendorId** and **ProductId** members, to determine whether the tape miniclass driver supports the tape device. *TAPE_VERIFY_INQUIRY_ROUTINE* uses [TapeClassCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclasscomparememory) to compare ID strings against values the tape miniclass driver supports.

## See also

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeClassCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclasscomparememory)