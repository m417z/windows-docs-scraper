# EndpointFormFactor enumeration

## Description

The **EndpointFormFactor** enumeration defines constants that indicate the general physical attributes of an audio endpoint device.

## Constants

### `RemoteNetworkDevice:0`

An audio endpoint device that the user accesses remotely through a network.

### `Speakers`

A set of speakers.

### `LineLevel`

An audio endpoint device that sends a line-level analog signal to a line-input jack on an audio adapter or that receives a line-level analog signal from a line-output jack on the adapter.

### `Headphones`

A set of headphones.

### `Microphone`

A microphone.

### `Headset`

An earphone or a pair of earphones with an attached mouthpiece for two-way communication.

### `Handset`

The part of a telephone that is held in the hand and that contains a speaker and a microphone for two-way communication.

### `UnknownDigitalPassthrough`

An audio endpoint device that connects to an audio adapter through a connector for a digital interface of unknown type that transmits non-PCM data in digital pass-through mode. For more information, see Remarks.

### `SPDIF`

An audio endpoint device that connects to an audio adapter through a Sony/Philips Digital Interface (S/PDIF) connector.

### `DigitalAudioDisplayDevice`

An audio endpoint device that connects to an audio adapter through a High-Definition Multimedia Interface (HDMI) connector or a display port.

In **Windows Vista**, this value was named HDMI.

### `UnknownFormFactor`

An audio endpoint device with unknown physical attributes.

### `EndpointFormFactor_enum_count`

Windows 7: Maximum number of endpoint form factors.

## Remarks

The constants in this enumeration are the values that can be assigned to the [PKEY_AudioEndpoint_FormFactor](https://learn.microsoft.com/windows/desktop/CoreAudio/pkey-audioendpoint-formfactor) property.

In digital pass-through mode, a digital interface transports blocks of non-PCM data through a connection without modifying them and without attempting to interpret their contents. For more information about digital pass-through mode, see [S/PDIF Pass-Through Transmission of Non-PCM Streams](https://learn.microsoft.com/windows-hardware/drivers/audio/s-pdif-pass-through-transmission-of-non-pcm-streams).

For information about obtaining a description of the audio jack or connector through which an audio endpoint device connects to an audio adapter, see [IKsJackDescription::GetJackDescription](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjackdescription-getjackdescription) and [IKsJackDescription2::GetJackDescription2](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjackdescription2-getjackdescription2).

## See also

[Core Audio Enumerations](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-enumerations)

[IKsJackDescription::GetJackDescription](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjackdescription-getjackdescription)

[PKEY_AudioEndpoint_FormFactor Property](https://learn.microsoft.com/windows/desktop/CoreAudio/pkey-audioendpoint-formfactor)