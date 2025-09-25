# CHANGER_READ_ELEMENT_STATUS structure

## Description

Contains information that the
[IOCTL_CHANGER_GET_ELEMENT_STATUS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_get_element_status) control code needs to determine the elements whose status is to be retrieved.

## Members

### `ElementList`

A
[CHANGER_ELEMENT_LIST](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element_list) structure that contains an array of structures that represents the range of elements for which information is to be retrieved. The **ElementType** member of each structure can be one of the following values: ChangerDrive, ChangerSlot, ChangerTransport, ChangerIEPort, or AllElements.

### `VolumeTagInfo`

If this member is **TRUE**, volume tag information is to be retrieved. Otherwise, no volume information is retrieved. A volume tag can be a bar code or an application-defined value. This member is valid only if the **Features0** member of the
[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_changer_parameters) structure is CHANGER_BAR_CODE_SCANNER_INSTALLED or CHANGER_VOLUME_IDENTIFICATION.

## See also

[CHANGER_ELEMENT_LIST](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element_list)

[IOCTL_CHANGER_GET_ELEMENT_STATUS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_get_element_status)