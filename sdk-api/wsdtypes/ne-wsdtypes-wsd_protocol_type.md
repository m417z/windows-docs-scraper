# WSD_PROTOCOL_TYPE enumeration

## Description

Identifies the type of protocol supported by a port.

## Constants

### `WSD_PT_NONE:0x00`

No protocols supported.

### `WSD_PT_UDP:0x01`

The UDP protocol is supported.

### `WSD_PT_HTTP:0x02`

The HTTP protocol is supported.

### `WSD_PT_HTTPS:0x04`

The HTTPS protocol is supported.

### `WSD_PT_ALL:0xff`

The UDP, HTTP, and HTTPS protocols are supported.

## See also

[WSD_PORT_TYPE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_port_type)