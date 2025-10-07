# CallQualityProperty enumeration

\[ This enumeration is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **CallQualityProperty** enum is used by the [**ITCallQualityControl::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itcallqualitycontrol-getrange), [**ITCallQualityControl::Get**](https://learn.microsoft.com/windows/win32/tapi/itcallqualitycontrol-get), and [**ITCallQualityControl::Set**](https://learn.microsoft.com/windows/win32/tapi/itcallqualitycontrol-set) methods to indicate the call quality property being addressed.

## Constants

**CallQuality\_ControlInterval**

Control interval.

**CallQuality\_ConfBitrate**

Bit rate for conference.

**CallQuality\_MaxInputBitrate**

Maximum input bit rate.

**CallQuality\_CurrInputBitrate**

Current input bit rate.

**CallQuality\_MaxOutputBitrate**

Maximum output bit rate.

**CallQuality\_CurrOutputBitrate**

Current output bit rate.

**CallQuality\_MaxCPULoad**

Maximum CPU load.

**CallQuality\_CurrCPULoad**

Current CPU load.

## Requirements

| Requirement | Value |
|-------------------------|------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.1<br> |
| Header<br> | Ipmsp.h |

## See also

[**ITCallQualityControl::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itcallqualitycontrol-getrange)

[**ITCallQualityControl::Get**](https://learn.microsoft.com/windows/win32/tapi/itcallqualitycontrol-get)

[**ITCallQualityControl::Set**](https://learn.microsoft.com/windows/win32/tapi/itcallqualitycontrol-set)

