# IDDCX_TRANSMISSION_TYPE enumeration

## Description

A **IDDCX_TRANSMISSION_TYPE** value is used to indicate the link type for transmission of the video data.

## Constants

### `IDDCX_TRANSMISSION_TYPE_UNINITIALIZED:0`

Indicates that an **IDDCX_TRANSMISSION_TYPE** variable has not yet been assigned a meaningful value.

### `IDDCX_TRANSMISSION_TYPE_WIRED_USB:0x1`

Video data is being transmitted over wired USB.

### `IDDCX_TRANSMISSION_TYPE_WIRED_MIRACAST:0x2`

Video data is being transmitted over a wired Miracast link.

### `IDDCX_TRANSMISSION_TYPE_WIRED_OTHER:0x3`

Video data is being transmitted over a wired connect not already described.

### `IDDCX_TRANSMISSION_TYPE_WIRELESS_MAUSB:0x4`

Video data is being transmitted over wireless MA-USB.

### `IDDCX_TRANSMISSION_TYPE_WIRELESS_USB_OTHER:0x5`

Video data is being transmitted over wireless network not using MA-USB but the device is enumerated on the USB bus.

### `IDDCX_TRANSMISSION_TYPE_WIRELESS_WIFI_OTHER:0x6`

Video data is being transmitted over a WiFi wireless network.

### `IDDCX_TRANSMISSION_TYPE_WIRELESS_MIRACAST:0x7`

Video data is being transmitted over a wireless Miracast link.

### `IDDCX_TRANSMISSION_TYPE_WIRELESS_OTHER:0x8`

Video data is being transmitted over a non-WiFi wireless network not already described.

### `IDDCX_TRANSMISSION_TYPE_NETWORK_OTHER:0x9`

Video data is being transmitted over a TCP/UDP/IP network not already described.

### `IDDCX_TRANSMISSION_TYPE_OTHER:0xFFFFFFFF`

Video data is being transmitted over a link type that is not covered by the above definitions.

## See also

[**IDDCX_ENDPOINT_DIAGNOSTIC_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_endpoint_diagnostic_info)