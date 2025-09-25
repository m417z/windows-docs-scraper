# UDECX_USB_DEVICE_PLUG_IN_OPTIONS_INIT function

## Description

Initializes a [UDECX_USB_DEVICE_PLUG_IN_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ns-udecxusbdevice-_udecx_usb_device_plug_in_options) structure.

## Parameters

### `Options` [out]

A pointer to a [UDECX_USB_DEVICE_PLUG_IN_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ns-udecxusbdevice-_udecx_usb_device_plug_in_options) structure to initialize.

## Remarks

The method initializes **Usb20PortNumber** and **Usb30PortNumber** to 0. This indicates a request for automatic port number selection.

## See also

[UdecxUsbDevicePlugIn](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceplugin)