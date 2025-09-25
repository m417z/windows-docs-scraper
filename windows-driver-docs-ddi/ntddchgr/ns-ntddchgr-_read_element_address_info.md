# _READ_ELEMENT_ADDRESS_INFO structure

## Description

This structure is to retrieve changer elements based on a search criterion specified in a call to the [ChangerQueryVolumeTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerqueryvolumetags) routine.

## Members

### `NumberOfElements`

Indicates the number of elements that matched the criteria specified by **ActionCode** and **VolumeTemplateID** in the [CHANGER_SEND_VOLUME_TAG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_send_volume_tag_information) structure passed to the driver. If no element matches the criteria, this member is zero.

### `ElementStatus`

Contains an array holding the first [CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status) structure that matched the criteria in the CHANGER_SEND_VOLUME_TAG_INFORMATION structure passed to the driver.

## See also

[CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status)

[CHANGER_SEND_VOLUME_TAG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_send_volume_tag_information)

[ChangerQueryVolumeTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerqueryvolumetags)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)