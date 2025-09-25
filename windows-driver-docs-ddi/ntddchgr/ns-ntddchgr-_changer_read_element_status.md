# _CHANGER_READ_ELEMENT_STATUS structure

## Description

The CHANGER_READ_ELEMENT_STATUS structure is used in conjunction with the [IOCTL_CHANGER_GET_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_element_status) request to retrieve the status of all elements or the status of a specified number of elements of a particular type.

## Members

### `ElementList`

Specifies the element type and the number of elements of that type for which to report status in a structure of type [CHANGER_ELEMENT_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_list). This member contains a list of structures of type [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element). The **ElementType** member of each CHANGER_ELEMENT structure in this list can be assigned a value of **ChangerDrive**, **ChangerSlot**, **ChangerTransport**, **ChangerIEPort**, or **AllElements**.

### `VolumeTagInfo`

Indicates, when **TRUE**, that volume tag information should be reported in addition to element status. When **FALSE**, it indicates that only element status should be reported. A volume tag can be a bar code or an application-defined value assigned using [ChangerQueryVolumeTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerqueryvolumetags). This member is applicable only if either CHANGER_BAR_CODE_SCANNER_INSTALLED or CHANGER_VOLUME_IDENTIFICATION is set in the **Features0** member of the [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) structure.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[CHANGER_ELEMENT_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_list)

[ChangerGetElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetelementstatus)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)

[IOCTL_CHANGER_GET_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_element_status)