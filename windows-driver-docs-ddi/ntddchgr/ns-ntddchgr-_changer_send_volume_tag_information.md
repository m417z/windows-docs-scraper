# _CHANGER_SEND_VOLUME_TAG_INFORMATION structure

## Description

This structure is passed to the [ChangerQueryVolumeTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerqueryvolumetags) routine and is used to specify a search criterion for retrieving changer elements.

## Members

### `StartingElement`

Describes the first element of the range to search for or to set in a structure of type [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element).

### `ActionCode`

Indicates the operation to perform. The **Features0** member of [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) indicates whether the changer supports a particular category of operation:

* Translate operations, also known as "searching operations", request that the target device search its volume tag information for elements that match the template passed to the device. Valid only if **Features0** is set to CHANGER_VOLUME_SEARCH.
* Assert operations define volume tag information for a single element. Valid only if **Features0** is set to CHANGER_VOLUME_ASSERT.
* Replace operations define volume tag information for a single element, overwriting any information previously defined. Valid only if **Features0** is set to CHANGER_VOLUME_REPLACE.
* Undefined operations clear previously defined volume tag information for a single element. Valid only if **Features0** is set to CHANGER_VOLUME_UNDEFINE.

### `VolumeIDTemplate`

Specifies the template to be used by the device to search for volume IDs. For a translate operation, the template can include the wildcard characters, asterisk (*) and question mark (?), to search for volumes that match the template. For other operations, the template specifies a single volume.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[ChangerQueryVolumeTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerqueryvolumetags)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)

[READ_ELEMENT_ADDRESS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_read_element_address_info)