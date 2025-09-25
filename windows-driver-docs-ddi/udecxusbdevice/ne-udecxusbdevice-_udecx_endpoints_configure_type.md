# _UDECX_ENDPOINTS_CONFIGURE_TYPE enumeration

## Description

Defines values for endpoint configuration options.

## Constants

### `UdecxEndpointsConfigureTypeDeviceInitialize`

Reserved for internal use.

### `UdecxEndpointsConfigureTypeDeviceConfigurationChange`

The requested change applies to the USB device configuration.

### `UdecxEndpointsConfigureTypeInterfaceSettingChange`

The requested change applies to an alternate setting of a USB interface.

### `UdecxEndpointsConfigureTypeEndpointsReleasedOnly`

The requested change applies to an endpoint of an interface setting.

## See also

[EVT_UDECX_USB_DEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_endpoints_configure)

[UDECX_ENDPOINTS_CONFIGURE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ns-udecxusbdevice-_udecx_endpoints_configure_params)