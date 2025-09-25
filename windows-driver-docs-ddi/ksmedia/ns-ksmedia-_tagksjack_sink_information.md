# _tagKSJACK_SINK_INFORMATION structure

## Description

The **KSJACK_SINK_INFORMATION** structure specifies information about a display-related digital audio device, such as an HDMI device or a display port.

## Members

### `ConnType`

Specifies the connection type of the sink. This parameter is an enumeration of type [KSJACK_SINK_CONNECTIONTYPE](https://learn.microsoft.com/windows/win32/api/devicetopology/ne-devicetopology-ksjack_sink_connectiontype).

### `ManufacturerId`

Specifies the sink manufacturer ID.

### `ProductId`

Specifies the sink product ID.

### `AudioLatency`

Specifies the sink audio latency.

### `HDCPCapable`

Specifies that this jack sink provides support for High-bandwidth Digital Content Protection (HDCP).

### `AICapable`

Specifies that this jack sink provides support for the following data packet types: audio content protection (ACP), international standard recording code-1 (ISRC1), and ISRC2.

### `SinkDescriptionLength`

Specifies the length of the **SinkDescription**[] member.

### `SinkDescription`

Specifies a string that contains the sink name, which must be NULL-terminated. The maximum length is defined by the MAX_SINK_DESCRIPTION_NAME_LENGTH constant (31 characters, plus a terminating **NULL**).

### `PortId`

Reserved.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)