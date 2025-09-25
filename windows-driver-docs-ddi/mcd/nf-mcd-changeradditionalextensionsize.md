# ChangerAdditionalExtensionSize function

## Description

**ChangerAdditionalExtensionSize** indicates the number of bytes the changer miniclass driver requires to store device-specific information in the device extension.

## Return value

**ChangerAdditionalExtensionSize** returns the size, in bytes, of the additional device extension space required by the changer miniclass driver.

## Remarks

The changer class driver calls **ChangerAdditionalExtensionSize** to determine the number of bytes the miniclass driver requires in the device extension for a particular changer before creating the device object to represent that changer.

The device-specific information stored by a changer miniclass driver is determined by the driver. It typically includes zero-based offsets that other miniclass driver routines can use to translate between device-specific element addresses and the zero-based element addresses used by the system. It can also include SCSI inquiry data or the non-SCSI equivalent.

## See also

[ChangerInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerinitialize)