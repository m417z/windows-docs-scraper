# CHANGER_ELEMENT_STATUS_EX structure

## Description

Represents the status of the specified element.

## Members

### `Element`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that represents the element to which this structure refers.

### `SrcElementAddress`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that represents the element from which the media currently in this element was most recently moved.

This member is valid only if the **Flags** member includes ELEMENT_STATUS_SVALID.

### `Flags`

The element status. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **ELEMENT_STATUS_ACCESS**<br><br>0x00000008 | The changer's transport element can access the piece of media in this element. The media is not accessible in the following circumstances: (1) If the element type is ChangerSlot, the slot is not present in the changer (for example, the magazine containing the slot has been physically removed). (2) If the element type is ChangerDrive, the drive is broken or has been removed. (3) If the element type is ChangerIEPort, the changer's insert/eject port is extended. |
| **ELEMENT_STATUS_AVOLTAG**<br><br>0x20000000 | Alternate volume information in the **AlternateVolumeID** member is valid. |
| **ELEMENT_STATUS_EXCEPT**<br><br>0x00000004 | The element is in an abnormal state. Check the **ExceptionCode** member for more information. |
| **ELEMENT_STATUS_EXENAB**<br><br>0x00000010 | The element supports export of media through the changer's insert/eject port. |
| **ELEMENT_STATUS_FULL**<br><br>0x00000001 | The element contains a piece of media.<br><br>Note that this value is valid only if the element type is ChangerDrive, ChangerSlot, or ChangerTransport. If the element type is ChangerIEPort, this value is valid only if the **Features0** member of [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_changer_parameters) includes CHANGER_REPORT_IEPORT_STATE. |
| **ELEMENT_STATUS_ID_VALID**<br><br>0x00002000 | The SCSI target ID in the **TargetID** member is valid. <br><br>This value is valid only if the element type is ChangerDrive. |
| **ELEMENT_STATUS_IMPEXP**<br><br>0x00000002 | The media in this element was placed there by an operator. <br><br>This value is valid only if the element type is ChangerIEPort. |
| **ELEMENT_STATUS_INENAB**<br><br>0x00000020 | The element supports import of media through the changer's insert/eject port. |
| **ELEMENT_STATUS_INVERT**<br><br>0x00400000 | The media in the element was flipped. <br><br>This value is valid only if ELEMENT_STATUS_SVALID is also included. |
| **ELEMENT_STATUS_LUN_VALID**<br><br>0x00001000 | The logical unit number in the **Lun** member is valid. This value is valid only if the element type is ChangerDrive. |
| **ELEMENT_STATUS_NOT_BUS**<br><br>0x00008000 | The drive at the address indicated by **Lun** and **TargetID** is on a different SCSI bus than the changer itself. |
| **ELEMENT_STATUS_PRODUCT_DATA**<br><br>0x00000040 | The serial number in the **SerialNumber** member is valid. |
| **ELEMENT_STATUS_PVOLTAG**<br><br>0x10000000 | Primary volume information in the **PrimaryVolumeID** member is valid. |
| **ELEMENT_STATUS_SVALID**<br><br>0x00800000 | The **SourceElement** member and ELEMENT_STATUS_INVERT are both valid. |

### `ExceptionCode`

An exception code that indicates that the element is in an abnormal state. This member is valid only if the **Flags** member includes ELEMENT_STATUS_EXCEPT. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_DRIVE_NOT_INSTALLED**<br><br>0x00000008 | The drive at this element address is absent. |
| **ERROR_INIT_STATUS_NEEDED**<br><br>0x00000011 | An Initialize Element Status command is needed. |
| **ERROR_LABEL_QUESTIONABLE**<br><br>0x00000002 | The label might be invalid due to a unit attention condition. |
| **ERROR_LABEL_UNREADABLE**<br><br>0x00000001 | The changer's barcode reader could not read the bar code label on the piece of media in this element, because the media is missing, damaged, improperly positioned, or upside down. |
| **ERROR_SLOT_NOT_PRESENT**<br><br>0x00000004 | The slot at this element address is currently not installed in the changer. Each slot in a removable magazine is reported not present to indicate that the magazine has been removed. |
| **ERROR_TRAY_MALFUNCTION**<br><br>0x00000010 | The drive at this element address has a tray that must be extended to load or remove media, and the tray is not extending as required. |
| **ERROR_UNHANDLED_ERROR**<br><br>0xFFFFFFFF | Unknown error condition. |

### `TargetId`

For a SCSI changer, specifies the SCSI target ID of the drive at this element address. This member is valid only if the **ElementType** member of the **Element** structure is ChangerDrive and the **Flags** member includes ELEMENT_STATUS_ID_VALID.

### `Lun`

The SCSI logical unit number of the drive at this element address. This member is valid only if the **ElementType** member of the **Element** structure is ChangerDrive and the **Flags** member includes ELEMENT_STATUS_LUN_VALID.

### `Reserved`

Reserved for future use. The value of this member must be zero.

### `PrimaryVolumeID`

The primary volume identifier for the media. If the changer supports a barcode reader and the reader is installed (as indicated by CHANGER_BAR_CODE_SCANNER_INSTALLED in the **Features0** member of
[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_changer_parameters)), **PrimaryVolumeID** is the bar code of the media. If the changer does not support a barcode reader, **PrimaryVolumeID** is the value previously assigned to the media.

This member is valid only if the **Flags** member includes ELEMENT_STATUS_PVOLTAG.

If the volume identifier is missing or unreadable, this member is cleared.

### `AlternateVolumeID`

An alternate volume identification for the media. This member is valid for two-sided media only, and pertains to the ID of the inverted side. It never represents a bar code.

This member is valid only if the **Flags** member includes ELEMENT_STATUS_AVOLTAG.

### `VendorIdentification`

The vendor identifier.

### `ProductIdentification`

The product identifier.

### `SerialNumber`

The serial number for the drive.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element)

[IOCTL_CHANGER_GET_ELEMENT_STATUS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_get_element_status)