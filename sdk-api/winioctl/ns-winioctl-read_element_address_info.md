# READ_ELEMENT_ADDRESS_INFO structure

## Description

Represents the volume tag information. It is used by the
[IOCTL_CHANGER_QUERY_VOLUME_TAGS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_query_volume_tags) control code.

## Members

### `NumberOfElements`

The number of elements matching criteria set forth by the **ActionCode** member of
[CHANGER_SEND_VOLUME_TAG_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-changer_send_volume_tag_information).

For information on compatibility with the current device, see the **Features0** member of
[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_changer_parameters).

### `ElementStatus`

An array of
[CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element_status) structures, one for each element that corresponded with the information passed in with the
[CHANGER_SEND_VOLUME_TAG_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-changer_send_volume_tag_information) structure.

## See also

[CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element_status)

[CHANGER_SEND_VOLUME_TAG_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-changer_send_volume_tag_information)

[IOCTL_CHANGER_QUERY_VOLUME_TAGS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_query_volume_tags)