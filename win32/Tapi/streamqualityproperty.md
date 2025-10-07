# StreamQualityProperty enumeration

\[ This enumeration is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **StreamQualityProperty** enum used by the [**ITStreamQualityControl::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itstreamqualitycontrol-getrange), [**ITStreamQualityControl::Get**](https://learn.microsoft.com/windows/win32/tapi/itstreamqualitycontrol-get), and [**ITStreamQualityControl::Set**](https://learn.microsoft.com/windows/win32/tapi/itstreamqualitycontrol-set) methods to indicate the stream quality property being addressed.

## Constants

**StreamQuality\_MaxBitrate**

Maximum bit rate.

**StreamQuality\_CurrBitrate**

Minimum bit rate.

**StreamQuality\_MinFrameInterval**

Maximum frame interval.

**StreamQuality\_AvgFrameInterval**

Minimum frame interval.

## Requirements

| Requirement | Value |
|-------------------------|------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.1<br> |
| Header<br> | Ipmsp.h |

## See also

[**ITStreamQualityControl::GetRange**](https://learn.microsoft.com/windows/win32/tapi/itstreamqualitycontrol-getrange)

[**ITStreamQualityControl::Get**](https://learn.microsoft.com/windows/win32/tapi/itstreamqualitycontrol-get)

[**ITStreamQualityControl::Set**](https://learn.microsoft.com/windows/win32/tapi/itstreamqualitycontrol-set)

