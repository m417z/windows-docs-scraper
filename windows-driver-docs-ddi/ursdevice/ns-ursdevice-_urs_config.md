# _URS_CONFIG structure

## Description

Contains pointers to event callback functions implemented by the URS client driver for a USB dual-role controller. Initialize this structure by calling [URS_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-urs_config_init).

## Members

### `Size`

The size of this structure.

### `HostInterfaceType`

A [URS_HOST_INTERFACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/urstypes/ne-urstypes-_urs_host_interface_type) type value that indicates the type of USB host controller: EHCI, xHCI, or other.

### `EvtUrsFilterRemoveResourceRequirements`

A pointer to an [EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nc-ursdevice-evt_urs_device_filter_resource_requirements) callback function.

### `EvtUrsSetRole`

A pointer to an [EVT_URS_SET_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nc-ursdevice-evt_urs_set_role) callback function.

## See also

[URS_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-urs_config_init)

[UrsDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursdeviceinitialize)