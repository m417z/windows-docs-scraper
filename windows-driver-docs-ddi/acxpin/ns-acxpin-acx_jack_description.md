## Description

The **ACX_JACK_DESCRIPTION** structure describes attributes of an audio jack, such as connection type, physical location, and so on.

## Members

### `ChannelMapping`

Specifies the mapping of the audio channels to the corresponding speaker positions. *ChannelMapping* is a bitmask of the KSAUDIO_SPEAKER_XXX flags (for example, SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT), which are defined in the header file Ksmedia.h. *ChannelMapping* should be nonzero only for analog rendering pins. For capture pins or for digital rendering pins, set this member to 0.

### `Color`

Specifies the jack color. The color is expressed as a 32-bit RGB value that is formed by concatenating the 8-bit blue, green, and red color components. The blue component occupies the 8 least-significant bits (bits 0-7), the green component occupies bits 8-15, and the red component occupies bits 16-23. The 8 most-significant bits are zeros. If the jack color is unknown or the physical connector has no identifiable color, the value of this member is 0x00000000, which represents black.

### `ConnectionType`

Specifies the physical connection type for this jack. The value of this member is one of the **EPcxConnectionType** enumeration values shown in the following table.

| Value | Connector type |
|--|--|
| eConnTypeUnknown | Unknown |
| eConnType3Point5mm | 3.5 mm minijack |
| eConnTypeQuarter | 1/4-inch jack |
| eConnTypeAtapiInternal | ATAPI internal connector |
| eConnTypeRCA | RCA jack |
| eConnTypeOptical | Optical connector |
| eConnTypeOtherDigital | Generic digital connector |
| eConnTypeOtherAnalog | Generic analog connector |
| eConnTypeMultichannelAnalogDIN | Multichannel analog DIN connector |
| eConnTypeXlrProfessional | XLR connector |
| eConnTypeRJ11Modem | RJ11 modem connector |
| eConnTypeCombination | Connector combination |

### `GeoLocation`

The geometric location of the jack. The value of this member is one of the **EPcxGeoLocation** enumeration values shown in the following table.

| Value | Geometric location |
|--|--|
| eGeoLocRear | Rear |
| eGeoLocFront | Front |
| eGeoLocLeft | Left |
| eGeoLocRight | Right |
| eGeoLocTop | Top |
| eGeoLocBottom | Bottom |
| eGeoLocRearPanel | Rear slide-open or pull-open panel |
| eGeoLocRiser | Riser card |
| eGeoLocInsideMobileLid | Inside lid of mobile computer |
| eGeoLocDrivebay | Drive bay |
| eGeoLocHDMI | HDMI connector |
| eGeoLocOutsideMobileLid | Outside lid of mobile computer |
| eGeoLocATAPI | ATAPI connector |
| eGeoLocNotApplicable | Not applicable. See the [Remarks](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_description#remarks) section. |

### `GenLocation`

Specifies the general location of the jack. The value of this member is one of the **EPcxGenLocation** enumeration values shown in the following table.

| Value | General location |
|--|--|
| eGenLocPrimaryBox | On primary chassis |
| eGenLocInternal | Inside primary chassis |
| eGenLocSeparate | On separate chassis |
| eGenLocOther | Other location |

### `PortConnection`

Specifies the type of port represented by the jack. The value of this member is one of the **EPxcPortConnection** enumeration values shown in the following table.

| Value | Port connection type |
|--|--|
| ePortConnJack | Jack |
| ePortConnIntegratedDevice | Slot for an integrated device |
| ePortConnBothIntegratedAndJack | Both a jack and a slot for an integrated device |
| ePortConnUnknown | Unknown |

## Remarks

This structure describes an audio jack that is part of a connection between an endpoint device and a hardware device in an audio adapter. When a user needs to plug an endpoint device into a jack or unplug it from a jack, an audio application can use the descriptive information in the structure to help the user to find the jack.

When an audio device does not expose a physically accessible jack, the audio device uses the **eGeoLocNotApplicable** value to indicate to Windows and Windows-based apps that there is no physical jack. As such, there is no geometric location either. For example, the audio device can be integrated into the motherboard, without any accessible jacks.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)