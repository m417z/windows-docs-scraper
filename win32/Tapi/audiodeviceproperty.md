# AudioDeviceProperty enumeration

\[ This enumeration is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **AudioDeviceProperty** enum is used by the [**ITAudioDeviceControl::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itaudiodevicecontrol-getrange), [**ITAudioDeviceControl::Get**](https://learn.microsoft.com/windows/win32/tapi/itaudiodevicecontrol-get), and [**ITAudioDeviceControl::Set**](https://learn.microsoft.com/windows/win32/tapi/itaudiodevicecontrol-set) methods to indicate the property being addressed.

## Constants

**AudioDevice\_DuplexMode**

Indicates that the duplex mode of the device is being set or retrieved.

**AudioDevice\_AutomaticGainControl**

Indicates that the automatic gain control of the device is being set or retrieved.

**AudioDevice\_AcousticEchoCancellation**

Indicates that the acoustic echo cancellation properties of the device are being set or retrieved.

## Requirements

| Requirement | Value |
|-------------------------|------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.1<br> |
| Header<br> | Ipmsp.h |

## See also

[**ITAudioDeviceControl::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itaudiodevicecontrol-getrange)

[**ITAudioDeviceControl::Get**](https://learn.microsoft.com/windows/win32/tapi/itaudiodevicecontrol-get)

[**ITAudioDeviceControl::Set**](https://learn.microsoft.com/windows/win32/tapi/itaudiodevicecontrol-set)

