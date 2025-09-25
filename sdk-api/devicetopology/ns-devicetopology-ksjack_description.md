# KSJACK_DESCRIPTION structure

## Description

The **KSJACK_DESCRIPTION** structure describes an audio jack.

## Members

### `ChannelMapping`

Specifies the mapping of the two audio channels in a stereo jack to speaker positions.

In Windows Vista, the value of this member is one of the **EChannelMapping** enumeration values shown in the following table.

| Value | First channel | Second channel |
| --- | --- | --- |
| ePcxChanMap_FL_FR | Front-left speaker | Front-right speaker |
| ePcxChanMap_FC_LFE | Front-center speaker | Low-frequency-effects speaker (subwoofer) |
| ePcxChanMap_BL_BR | Back-left speaker | Back-right speakers |
| ePcxChanMap_FLC_FRC | Front-left-center speaker | Front-right-center speaker |
| ePcxChanMap_SL_SR | Side-left speaker | Side-right speaker |
| ePcxChanMap_Unknown | Unknown | Unknown |

For a physical connector with one, three, or more channels, the value of this member is ePcxChanMap_Unknown.

In Windows 7, the **EChannelMapping** enumeration has been deprecated. The datatype of this member is a **DWORD**. This member stores either 0 or the bitwise-OR combination of one or more of the following values that are defined in Ksmedia.h.

``` syntax
#define SPEAKER_FRONT_LEFT              0x1
#define SPEAKER_FRONT_RIGHT             0x2
#define SPEAKER_FRONT_CENTER            0x4
#define SPEAKER_LOW_FREQUENCY           0x8
#define SPEAKER_BACK_LEFT               0x10
#define SPEAKER_BACK_RIGHT              0x20
#define SPEAKER_FRONT_LEFT_OF_CENTER    0x40
#define SPEAKER_FRONT_RIGHT_OF_CENTER   0x80
#define SPEAKER_BACK_CENTER             0x100
#define SPEAKER_SIDE_LEFT               0x200
#define SPEAKER_SIDE_RIGHT              0x400
#define SPEAKER_TOP_CENTER              0x800
#define SPEAKER_TOP_FRONT_LEFT          0x1000
#define SPEAKER_TOP_FRONT_CENTER        0x2000
#define SPEAKER_TOP_FRONT_RIGHT         0x4000
#define SPEAKER_TOP_BACK_LEFT           0x8000
#define SPEAKER_TOP_BACK_CENTER         0x10000
#define SPEAKER_TOP_BACK_RIGHT          0x20000

```

### `Color`

The jack color. The color is expressed as a 32-bit RGB value that is formed by concatenating the 8-bit blue, green, and red color components. The blue component occupies the 8 least-significant bits (bits 0-7), the green component occupies bits 8-15, and the red component occupies bits 16-23. The 8 most-significant bits are zeros. If the jack color is unknown or the physical connector has no identifiable color, the value of this member is 0x00000000, which is black.

### `ConnectionType`

The connection type. The value of this member is one of the **EPcxConnectionType** enumeration values shown in the following table.

| Value | Connector type |
| --- | --- |
| eConnTypeUnknown | Unknown |
| eConnTypeEighth (Windows Vista)<br><br> eConnType3Point5mm (Windows 7) | 1/8-inch jack |
| eConnTypeQuarter | 1/4-inch jack |
| eConnTypeAtapiInternal | ATAPI internal connector |
| eConnTypeRCA | RCA jack |
| eConnTypeOptical | Optical connector |
| eConnTypeOtherDigital | Generic digital connector |
| eConnTypeOtherAnalog | Generic analog connector |
| eConnTypeMultichannelAnalogDIN | Multichannel analog DIN connector |
| eConnTypeXlrProfessional | XLR connector |
| eConnTypeRJ11Modem | RJ11 modem connector |
| eConnTypeCombination | Combination of connector types |

### `GeoLocation`

The geometric location of the jack. The value of this member is one of the **EPcxGeoLocation** enumeration values shown in the following table.

| Value | Geometric location |
| --- | --- |
| eGeoLocRear | Rear-mounted panel |
| eGeoLocFront | Front-mounted panel |
| eGeoLocLeft | Left-mounted panel |
| eGeoLocRight | Right-mounted panel |
| eGeoLocTop | Top-mounted panel |
| eGeoLocBottom | Bottom-mounted panel |
| eGeoLocRearOPanel(Windows Vista)<br><br>eGeoLocRearPanel(Windows 7) | Rear slide-open or pull-open panel |
| eGeoLocRiser | Riser card |
| eGeoLocInsideMobileLid | Inside lid of mobile computer |
| eGeoLocDrivebay | Drive bay |
| eGeoLocHDMI | HDMI connector |
| eGeoLocOutsideMobileLid | Outside lid of mobile computer |
| eGeoLocATAPI | ATAPI connector |

### `GenLocation`

The general location of the jack. The value of this member is one of the **EPcxGenLocation** enumeration values shown in the following table.

| Value | General location |
| --- | --- |
| eGenLocPrimaryBox | On primary chassis |
| eGenLocInternal | Inside primary chassis |
| eGenLocSeperate(Windows Vista)<br><br>eGenLocSeparate(Windows 7) | On separate chassis |
| eGenLocOther | Other location |

### `PortConnection`

The type of port represented by the jack. The value of this member is one of the **EPxcPortConnection** enumeration values shown in the following table.

| Value | Port connection type |
| --- | --- |
| ePortConnJack | Jack |
| ePortConnIntegratedDevice | Slot for an integrated device |
| ePortConnBothIntegratedAndJack | Both a jack and a slot for an integrated device |
| ePortConnUnknown | Unknown |

### `IsConnected`

If the audio adapter supports jack-presence detection on the jack, the value of **IsConnected** indicates whether an endpoint device is plugged into the jack. If **IsConnected** is **TRUE**, a device is plugged in. If it is **FALSE**, the jack is empty. For devices that do not support jack-presence detection, this member is always **TRUE**. For more information about jack-presence detection, see [Audio Endpoint Devices](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-endpoint-devices).

## Remarks

This structure is used by the [IKsJackDescription::GetJackDescription](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjackdescription-getjackdescription) method in the [DeviceTopology API](https://learn.microsoft.com/windows/desktop/CoreAudio/devicetopology-api). It describes an audio jack that is part of a connection between an endpoint device and a hardware device in an audio adapter. When a user needs to plug an endpoint device into a jack or unplug it from a jack, an audio application can use the descriptive information in the structure to help the user to find the jack.

## See also

[Core Audio Structures](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-structures)

[IKsJackDescription::GetJackDescription](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjackdescription-getjackdescription)