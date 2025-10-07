# TAPIControlFlags enumeration

\[ This enumeration is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **TAPIControlFlags** enum is used by a number of methods to indicate whether a given property is controlled automatically or manually.

## Constants

**TAPIControl\_Flags\_None**

TAPI has no control flags for the property.

**TAPIControl\_Flags\_Auto**

The property is controlled automatically.

**TAPIControl\_Flags\_Manual**

The property is controlled manually.

## Requirements

| Requirement | Value |
|-------------------------|------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.1<br> |
| Header<br> | Ipmsp.h |

## See also

[**ITAudioDeviceControl::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itaudiodevicecontrol-getrange)

[**ITAudioDeviceControl::Get**](https://learn.microsoft.com/windows/win32/tapi/itaudiodevicecontrol-get)

[**ITAudioDeviceControl::Set**](https://learn.microsoft.com/windows/win32/tapi/itaudiodevicecontrol-set)

[**ITAudioSettings::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itaudiosettings-getrange)

[**ITAudioSettings::Get**](https://learn.microsoft.com/windows/win32/tapi/itaudiosettings-get)

[**ITAudioSettings::Set**](https://learn.microsoft.com/windows/win32/tapi/itaudiosettings-set)

[**ITCallQualityControl::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itcallqualitycontrol-getrange)

[**ITCallQualityControl::Get**](https://learn.microsoft.com/windows/win32/tapi/itcallqualitycontrol-get)

[**ITCallQualityControl::Set**](https://learn.microsoft.com/windows/win32/tapi/itcallqualitycontrol-set)

[**ITStreamQualityControl::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itstreamqualitycontrol-getrange)

[**ITStreamQualityControl::Get**](https://learn.microsoft.com/windows/win32/tapi/itstreamqualitycontrol-get)

[**ITStreamQualityControl::Set**](https://learn.microsoft.com/windows/win32/tapi/itstreamqualitycontrol-set)

