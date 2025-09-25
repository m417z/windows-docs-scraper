# _UDECX_ENDPOINTS_CONFIGURE_PARAMS structure

## Description

Contains the configuration options specified by USB device emulation class extension (UdeCx) to the client driver when the class extension invokes [EVT_UDECX_USB_DEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_endpoints_configure).

## Members

### `Size`

Size of this structure.

### `ConfigureType`

A [UDECX_ENDPOINTS_CONFIGURE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ne-udecxusbdevice-_udecx_endpoints_configure_type)-typed value that indicates whether the configuration, interface setting, or endpoint must be configured.

### `NewConfigurationValue`

If **ConfigureType** is **UdecxEndpointsConfigureTypeDeviceConfigurationChange**, this value is **bConfigurationValue** of the new configuration descriptor ([USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor)).

### `InterfaceNumber`

If **ConfigureType** is **UdecxEndpointsConfigureTypeInterfaceSettingChange**, this value is **bInterfaceNumber** of the current interface descriptor ([USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)).

### `NewInterfaceSetting`

If **ConfigureType** is **UdecxEndpointsConfigureTypeInterfaceSettingChange**, this value is **bAlternateSetting** of the interface descriptor ([USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)) to set.

### `EndpointsToConfigureCount`

The number entries in the array pointed to by *EndpointsToConfigure*. This value indicates number of endpoints that must be configured.

### `EndpointsToConfigure`

A pointer to an array of UDECXUSBENDPOINT handles that indicates the endpoint objects to be configured.

A pointer to an array of UDECXUSBENDPOINT handles that indicates the endpoint objects that must be released.

### `ReleasedEndpointsCount`

The number entries in the array pointed to by *EndpointsToConfigure*. This value indicates number of endpoints to release.

### `ReleasedEndpoints`

## See also

[EVT_UDECX_USB_DEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_endpoints_configure)