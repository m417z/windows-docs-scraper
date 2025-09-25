# CHANGER_INITIALIZE_ELEMENT_STATUS structure

## Description

Represents the status of all media changer elements or the specified elements of a particular type.

## Members

### `ElementList`

A
[CHANGER_ELEMENT_LIST](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element_list) structure that lists the elements and range on which to initialize.

If CHANGER_INIT_ELEM_STAT_WITH_RANGE is set in the **Features0** member of
[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_changer_parameters), the changer supports initializing a range of elements. In this case, the **ElementType** member can be one of the following: ChangerTransport, ChangerSlot, ChangerDrive, or ChangerIEPort. Otherwise, the element type must be AllElements and the **NumberOfElements** member is ignored.

### `BarCodeScan`

If this member is **TRUE**, a bar-code scan should be used. Otherwise, it should not. If the changer has nonvolatile RAM, using a bar-code scan is an optimization.

This member is applicable only if CHANGER_BAR_CODE_SCANNER_INSTALLED is set in the **Features0** member of
[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_changer_parameters).

## See also

[CHANGER_ELEMENT_LIST](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element_list)

[IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_initialize_element_status)