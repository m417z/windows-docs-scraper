# TAPI\_VIDEO\_STREAM\_CONFIG\_CAPS structure

\[ This structure is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **TAPI\_VIDEO\_STREAM\_CONFIG\_CAPS** structure is contained by the [**TAPI\_STREAM\_CONFIG\_CAPS**](https://learn.microsoft.com/windows/win32/tapi/tapi-stream-config-caps) structure when the **CapsType** member is set to the **VideoCap** member of the [**StreamConfigCapsType**](https://learn.microsoft.com/windows/win32/tapi/streamconfigcapstype) union.

## Members

**Description**

A friendly description of the audio stream configuration type for display to application users.

**VideoStandard**

Video standard being used.

**InputSize**

Input size of frame.

**MinCroppingSize**

Minimum cropping size.

**MaxCroppingSize**

Maximum cropping size.

**CropGranularityX**

Granularity of cropping allowed along the x-axis.

**CropGranularityY**

Granularity of cropping allowed along the y-axis.

**CropAlignX**

Alignment of x-axis cropping.

**CropAlignY**

Alignment of y-axis cropping.

**MinOutputSize**

Minimum resultant size of video window.

**MaxOutputSize**

Maximum resultant size of video window.

**OutputGranularityX**

Granularity of output size along the x-axis.

**OutputGranularityY**

Granularity of output size along the y-axis.

**StretchTapsX**

Stretch along the x-axis.

**StretchTapsY**

Stretch along the y-axis.

**ShrinkTapsX**

Shrink along the x-axis.

**ShrinkTapsY**

Shrink along the y-axis.

**MinFrameInterval**

Minimum video frame interval.

**MaxFrameInterval**

Maximum video frame interval.

**MinBitsPerSecond**

Minimum bits per second.

**MaxBitsPerSecond**

Maximum bits per second.

## Requirements

| Requirement | Value |
|-------------------------|------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.1<br> |
| Header<br> | Ipmsp.h |

## See also

[**TAPI\_STREAM\_CONFIG\_CAPS**](https://learn.microsoft.com/windows/win32/tapi/tapi-stream-config-caps)

