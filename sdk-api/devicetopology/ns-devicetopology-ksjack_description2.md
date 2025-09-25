# KSJACK_DESCRIPTION2 structure

## Description

The **KSJACK_DESCRIPTION2** structure describes an audio jack.

To get the description of an audio jack of a connector, call [IKsJackDescription2::GetJackDescription2](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjackdescription2-getjackdescription2).

## Members

### `DeviceStateInfo`

Reserved for future use.

### `JackCapabilities`

Stores the audio jack's capabilities: jack presence detection capability
or dynamic format changing capability. The constants that can be stored in this member of the structure are defined in Ksmedia.h as follows:

* JACKDESC2_PRESENCE_DETECT_CAPABILITY (0x00000001)
* JACKDESC2_DYNAMIC_FORMAT_CHANGE_CAPABILITY (0x00000002)

## See also

[Core Audio Structures](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-structures)

[IKsJackDescription2](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksjackdescription2)