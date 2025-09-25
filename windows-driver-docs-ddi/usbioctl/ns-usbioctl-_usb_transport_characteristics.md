# _USB_TRANSPORT_CHARACTERISTICS structure

## Description

Stores the transport characteristics at relevant points in time. This structure is used in the [IOCTL_USB_GET_TRANSPORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_transport_characteristics) request.

## Members

### `Version`

The version is set to USB_TRANSPORT_CHARACTERISTICS_VERSION_1.

### `TransportCharacteristicsFlags`

A bitmask that indicates to the client driver the transport characteristics that are available and are returned in this structure.

If USB_TRANSPORT_CHARACTERISTICS_LATENCY_AVAILABLE

is set, **CurrentRoundtripLatencyInMilliSeconds** contains valid information. Otherwise , it must not be used by the client driver.

If USB_TRANSPORT_CHARACTERISTICS_BANDWIDTH_AVAILABLE

is set, **MaxPotentialBandwidth** contains valid information. Otherwise, it must not be used by the client driver.

### `CurrentRoundtripLatencyInMilliSeconds`

Contains the current round-trip delay in milliseconds from the time a non-isochronous transfer is received by the USB driver stack to the time that the transfer is completed.

For MA-USB, the underlying network could be WiFi, WiGig, Ethernet etc. The delay can vary depending on the underlying network conditions. A client driver should query the latency periodically or whenever it is notified of a change.

### `MaxPotentialBandwidth`

Contains the total bandwidth of the host controller’s shared transport.

For MA-USB, the underlying network transport could be WiFi, WiGig, Ethernet etc. The total available bandwidth can vary depending on several factors such as the negotiation WiFi channel. A client driver should query the total bandwidth periodically or whenever it is notified of a change.

## See also

[IOCTL_USB_GET_TRANSPORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_transport_characteristics)