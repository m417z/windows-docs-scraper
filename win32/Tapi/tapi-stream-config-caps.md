# TAPI\_STREAM\_CONFIG\_CAPS structure

\[ This structure is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **TAPI\_STREAM\_CONFIG\_CAPS** structure contains either video or audio stream configuration information.

## Members

**CapsType**

Defines whether the union member contains video or audio information.

**VideoCap**

A [**TAPI\_VIDEO\_STREAM\_CONFIG\_CAPS**](https://learn.microsoft.com/windows/win32/tapi/tapi-video-stream-config-caps) structure containing the video stream capabilities.

**AudioCap**

A [**TAPI\_AUDIO\_STREAM\_CONFIG\_CAPS**](https://learn.microsoft.com/windows/win32/tapi/tapi-audio-stream-config-caps) structure containing the audio stream capabilities.

## Requirements

| Requirement | Value |
|-------------------------|------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.1<br> |
| Header<br> | Ipmsp.h |

## See also

[**ITFormatControl::GetStreamCaps**](https://learn.microsoft.com/windows/win32/tapi/itformatcontrol-getstreamcaps)

[**StreamConfigCapsType**](https://learn.microsoft.com/windows/win32/tapi/streamconfigcapstype)

[**TAPI\_VIDEO\_STREAM\_CONFIG\_CAPS**](https://learn.microsoft.com/windows/win32/tapi/tapi-video-stream-config-caps)

[**TAPI\_AUDIO\_STREAM\_CONFIG\_CAPS**](https://learn.microsoft.com/windows/win32/tapi/tapi-audio-stream-config-caps)

