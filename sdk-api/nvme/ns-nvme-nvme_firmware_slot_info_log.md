# NVME_FIRMWARE_SLOT_INFO_LOG structure

## Description

Contains fields that specify the information in the Firmware Slot Information log page.

The Firmware Slot Information log page reports the firmware revision number (as an ASCII string) for each of the supported firmware slots, and indicates the active slot number. This log page is global to the controller.

This structure is returned by the Get Log Page command. For more information, see [NVME_CDW10_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page).

## Members

### `AFI`

An Active Firmware Information (**AFI**) structure containing fields that specify information about the active firmware revision.

### `AFI.ActiveSlot`

Indicates the firmware slot that contains the actively running firmware revision.

This value is contained in Bits 0:2 of the **AFI** structure.

### `AFI.Reserved0`

Bit 3 of the **AFI** structure is reserved.

### `AFI.PendingActivateSlot`

Indicates the firmware slot that is going to be activated at the next controller reset.

When this field is set to `0h`, the controller does not indicate the firmware slot that is going to be activated at the next controller reset.

This value is contained in bits 4:6 of the **AFI** structure

### `AFI.Reserved1`

Bit 7 of the **AFI** structure is reserved.

### `Reserved0`

### `FRS`

An array of 7 Firmware Revisions that contain the revision of the firmware downloaded to each of the 7 firmware slots.

The members of the array are named based on the firmware slot number (1-7), such that Firmware Revision for Slot 1 (FRS1) is in position 1, Firmware Revision for Slot 2 (FRS2) is in position 2, and so on, up to Firmware Revision for Slot 7 (FRS7) in position 7.

If no valid firmware revision is present, or if a slot is unsupported, all zeros will be returned for that slot.

### `Reserved1`

## Remarks

## See also