# URS_CONFIG_INIT function

## Description

Initializes a [URS_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/ns-ursdevice-_urs_config) structure.

## Parameters

### `Config` [out]

 A pointer to a [URS_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/ns-ursdevice-_urs_config) structure to initialize.

### `HostInterfaceType` [in]

 A [URS_HOST_INTERFACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/urstypes/ne-urstypes-_urs_host_interface_type) type value that indicates the type of host controller that the dual-role controller implements.

### `EvtUrsFilterRemoveResourceRequirements` [in]

 A pointer to a [EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nc-ursdevice-evt_urs_device_filter_resource_requirements) callback function that is implemented by the client driver.

## See also

[URS_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/ns-ursdevice-_urs_config)

[UrsDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursdeviceinitialize)