# _CHANGER_ELEMENT_STATUS structure

## Description

The [ChangerGetElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetelementstatus) routine returns status information in this structure.

## Members

### `Element`

Specifies the element of type [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element) to which this structure refers.

### `SrcElementAddress`

Specifies the element of type [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element) from which the media currently in this element was most recently moved. This member is valid only if ELEMENT_STATUS_SVALID is also set in **Flags**. This value must be a zero-based offset from the device-unique value.

### `Flags`

Indicates the status of the element, which can be one or more of the following values.

#### ELEMENT_STATUS_FULL

The element contains a piece of media. This flag is valid if **ElementType** in the **Element** member is **ChangerDrive**, **ChangerSlot**, or **ChangerTransport**. If **ElementType** is **ChangerIEPort**, this flag is valid only if CHANGER_REPORT_IEPORT_STATE is also set in **Features0** of GET_CHANGER_PARAMETERS.

#### ELEMENT_STATUS_IMPEXP

The media in this element was placed there by an operator. This flag is valid only if **ElementType** in the **Element** member is **ChangerIEPort**.

#### ELEMENT_STATUS_EXCEPT

The element is in an abnormal state. Check the **ExceptionCode** member for more information.

#### ELEMENT_STATUS_ACCESS

The changer's transport element can access the piece of media in this element. The miniclass driver clears this flag to indicate that the media is not accessible for one of the following reasons: If **ElementType** in the **Element** member is **ChangerSlot**, the slot is not present in the changer (for example, the magazine containing the slot has been physically removed). If **ElementType** is **ChangerDrive**, the drive is broken or has been removed. If **ElementType** is **ChangerIEPort**, the IEport is extended.

#### ELEMENT_STATUS_EXENAB

The element supports export of media through the changer's IEport.

#### ELEMENT_STATUS_INENAB

The element supports import of media through the changer's IEport.

#### ELEMENT_STATUS_LUN_VALID

The device number in the **Lun** member is valid. This flag is valid only if **ElementType** in the **Element** member is **ChangerDrive**.

#### ELEMENT_STATUS_ID_VALID

The SCSI target ID in the **TargetID** member is valid. This flag is valid only if **ElementType** in the **Element** member is **ChangerDrive**.

#### ELEMENT_STATUS_NOT_BUS

The drive at the address indicated by **Lun** and **TargetID** is on a different SCSI bus than the changer itself.

#### ELEMENT_STATUS_INVERT

The media in the element was flipped. This flag is valid only if the ELEMENT_STATUS_SVALID flag is also set.

#### ELEMENT_STATUS_SVALID

The **SourceElement** member and ELEMENT_STATUS_INVERT flag are both valid.

#### ELEMENT_STATUS_PVOLTAG

Primary volume information in the **PrimaryVolumeID** member is valid.

#### ELEMENT_STATUS_AVOLTAG

Alternate volume information in the **AlternateVolumeID** member is valid.

### `ExceptionCode`

Indicates that the element is in an abnormal state. This member is valid only if ELEMENT_STATUS_EXCEPT is set in **Flags**. **ExceptionCode** can be set to one of the following values.

#### ERROR_LABEL_UNREADABLE

The changer's bar code reader could not read the bar code label on the piece of media in this element, because the media is missing, damaged, improperly positioned, or upside down.

#### ERROR_LABEL_QUESTIONABLE

The label might be invalid due to a unit attention condition.

#### ERROR_SLOT_NOT_PRESENT

The slot at this element address is currently not installed in the changer. A miniclass driver sets this code for each slot in a removable magazine to indicate that the magazine has been removed.

#### ERROR_DRIVE_NOT_INSTALLED

The drive at this element address is absent. If a changer can continue to operate without the drive, its miniclass driver sets ERROR_DRIVE_NOT_INSTALLED for the drive.

#### ERROR_TRAY_MALFUNCTION

The drive at this element address has a tray that must be extended to load or remove media, and the tray is not extending as required.

#### ERROR_UNHANDLED_ERROR

Unknown error condition.

### `TargetId`

Specifies the SCSI target ID of the drive at this element address for a SCSI changer. This member is valid only if **ElementType** in the **Element** member is **ChangerDrive** and ELEMENT_STATUS_ID_VALID is set in **Flags**.

### `Lun`

Specifies the SCSI device number of the drive at this element address. This member is valid only if **ElementType** in the **Element** member is **ChangerDrive** and ELEMENT_STATUS_LUN_VALID is set in **Flags**.

### `Reserved`

Reserved for future use. The value of this member must be zero.

### `PrimaryVolumeID`

Specifies the primary volume identifier for the media. If the changer supports a bar code reader and the reader is installed (as indicated by CHANGER_BAR_CODE_SCANNER_INSTALLED in **Features0** of GET_CHANGER_PARAMETERS), the miniclass driver must set **PrimaryVolumeID** to the bar code of the media. If the changer does not support a bar code reader, the miniclass driver should set **PrimaryVolumeID** to the value previously assigned to the media using the **ChangerQueryVolumeTags** routine with an ASSERT_PRIMARY or REPLACE_PRIMARY action. This member is valid only if ELEMENT_STATUS_PVOLTAG is also set in **Flags**. If the volume identifier is missing or unreadable, the miniclass driver should clear this flag and set the appropriate error status. This identifier must be no larger than MAX_VOLUME_ID_SIZE bytes.

### `AlternateVolumeID`

Specifies alternate volume identification for the media. This member is valid for two-sided media only, and pertains to the ID of the inverted side. It never represents a bar code. The miniclass driver must set **AlternateVolumeID** to the value previously assigned to the media using the **ChangerQueryVolumeTags** routine with an ASSERT_ALTERNATE or REPLACE_ALTERNATE action. The identifier must be no larger than MAX_VOLUME_ID_SIZE bytes and is valid only if ELEMENT_STATUS_AVOLTAG is also set in **Flags**.

## Remarks

For most element types, changer miniclass drivers use CHANGER_ELEMENT_STATUS to report the status of specified elements to the changer class driver. Some elements of type **ChangerDrive**, however, return product information data. If the device provides product information, the miniclass driver will report the element status data in a structure of type [CHANGER_ELEMENT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status_ex) instead of using CHANGER_ELEMENT_STATUS. The miniclass driver indicates that product information is present by setting ELEMENT_STATUS_PRODUCT_DATA in the **Flags** member of the structure.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[CHANGER_ELEMENT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status_ex)

[ChangerGetElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetelementstatus)

[ChangerQueryVolumeTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerqueryvolumetags)

[IOCTL_CHANGER_GET_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_element_status)