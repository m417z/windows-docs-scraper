# KSJACK_SINK_INFORMATION structure

## Description

The **KSJACK_SINK_INFORMATION** structure stores information about an audio jack sink.

## Members

### `ConnType`

Specifies the type of connection. The connection type values are defined in the [KSJACK_SINK_CONNECTIONTYPE](https://learn.microsoft.com/windows/win32/api/devicetopology/ne-devicetopology-ksjack_sink_connectiontype) enumeration.

### `ManufacturerId`

Specifies the sink manufacturer identifier.

### `ProductId`

Specifies the sink product identifier.

### `AudioLatency`

Specifies the latency of the audio sink.

### `HDCPCapable`

Specifies whether the sink supports High-bandwidth Digital Content Protection (HDCP).

### `AICapable`

 Specifies whether the sink supports ACP Packet, ISRC1, or ISRC2.

### `SinkDescriptionLength`

Specifies the length of the string in the **SinkDescription** member.

### `SinkDescription`

String containing the monitor sink name. The maximum length is defined by the constant **MAX_SINK_DESCRIPTION_NAME_LENGTH** (32 wide characters).

### `PortId`

Specifies the video port identifier in a [LUID](https://learn.microsoft.com/windows/desktop/api/devicetopology/ns-devicetopology-luid) structure.

## See also

[Core Audio Structures](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-structures)

[IKsJackSinkInformation::GetJackSinkInformation](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjacksinkinformation-getjacksinkinformation)