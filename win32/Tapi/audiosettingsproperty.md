# AudioSettingsProperty enumeration

\[ This enumeration is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **AudioSettingsProperty** enum is used by the [**ITAudioSettings::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itaudiosettings-getrange), [**ITAudioSettings::Get**](https://learn.microsoft.com/windows/win32/tapi/itaudiosettings-get), and [**ITAudioSettings::Set**](https://learn.microsoft.com/windows/win32/tapi/itaudiosettings-set) methods to indicate the audio setting property being addressed.

## Constants

**AudioSettings\_SignalLevel**

Signal settings property.

**AudioSettings\_SilenceThreshold**

Silence threshold property.

**AudioSettings\_Volume**

Volume property.

**AudioSettings\_Balance**

Balance property.

**AudioSettings\_Loudness**

Loudness property.

**AudioSettings\_Treble**

Treble property.

**AudioSettings\_Bass**

Bass property.

**AudioSettings\_Mono**

Monaural property.

## Requirements

| Requirement | Value |
|-------------------------|------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.1<br> |
| Header<br> | Ipmsp.h |

## See also

[**ITAudioSettings::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itaudiosettings-getrange)

[**ITAudioSettings::Get**](https://learn.microsoft.com/windows/win32/tapi/itaudiosettings-get)

[**ITAudioSettings::Set**](https://learn.microsoft.com/windows/win32/tapi/itaudiosettings-set)

