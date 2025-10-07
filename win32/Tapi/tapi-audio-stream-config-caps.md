# TAPI\_AUDIO\_STREAM\_CONFIG\_CAPS structure

\[ This structure is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **TAPI\_AUDIO\_STREAM\_CONFIG\_CAPS** structure is contained by the [**TAPI\_STREAM\_CONFIG\_CAPS**](https://learn.microsoft.com/windows/win32/tapi/tapi-stream-config-caps) structure when the **CapsType** member is set to the **AudioCap** member of the [**StreamConfigCapsType**](https://learn.microsoft.com/windows/win32/tapi/streamconfigcapstype) union.

## Members

**Description**

A friendly description of the audio stream configuration type for display to application users.

**MinimumChannels**

The minimum number of channels associated with the stream.

**MaximumChannels**

The maximum number of channels associated with the stream.

**ChannelsGranularity**

The granularity of the channel count.

**MinimumBitsPerSample**

The minimum number of bits per sample.

**MaximumBitsPerSample**

The maximum number of bits per sample.

**BitsPerSampleGranularity**

The granularity of the bits per sample values.

**MinimumSampleFrequency**

The minimum sampling frequency.

**MaximumSampleFrequency**

The maximum sampling frequency.

**SampleFrequencyGranularity**

The granularity of the sampling frequency values.

**MinimumAvgBytesPerSec**

The minimum average bytes per second.

**MaximumAvgBytesPerSec**

The maximum average bytes per second.

**AvgBytesPerSecGranularity**

The granularity of the bytes per second values.

## Requirements

| Requirement | Value |
|-------------------------|------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.1<br> |
| Header<br> | Ipmsp.h |

## See also

[**TAPI\_STREAM\_CONFIG\_CAPS**](https://learn.microsoft.com/windows/win32/tapi/tapi-stream-config-caps)

