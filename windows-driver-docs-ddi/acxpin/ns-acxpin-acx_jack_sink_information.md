## Description

The **ACX_JACK_SINK_INFORMATION** structure specifies information about a display-related digital audio device, such as an HDMI device or a display port.

## Members

### `ConnType`

A value from the [ACX_JACK_SINK_INFO_CONNECTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_jack_sink_info_connection_type) enum indicating the video connection type, such as HDMI or DisplayPort.

### `ManufacturerId`

Specifies the sink manufacturer ID.

### `ProductId`

Specifies the sink product ID.

### `AudioLatency`

Specifies the sink audio latency.

### `HDCPCapable`

Specifies that this jack sink provides support for high-bandwidth digital content protection (HDCP).

### `AICapable`

Specifies that this jack sink provides support for the following data packet types: audio content protection (ACP), international standard recording code-1 (ISRC1), and ISRC2.

### `SinkDescriptionLength`

Specifies the length of the *SinkDescription* field.

### `SinkDescription`

Specifies a string that contains the sink name, which must be NULL-terminated. The maximum length is defined by the MAX_SINK_DESCRIPTION_NAME_LENGTH constant (31 characters, plus a terminating NULL).

### `PortId`

Reserved.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_JACK_SINK_INFO_CONNECTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_jack_sink_info_connection_type)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)