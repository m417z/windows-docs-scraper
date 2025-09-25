# GetTimeSysInfoFunc callback function

## Description

Retrieves the system time state information.

## Parameters

### `eInfo` [in]

Requested state information. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TSI_ClockPrecision** | The *pvInfo* parameter is a signed **__int32** value that specifies the clock precision, in log2 seconds. |
| **TSI_ClockTickSize** | The *pvInfo* parameter is an unsigned **__int64** value that specifies the clock tick size, in (10^-7) seconds. |
| **TSI_CurrentTime** | The *pvInfo* parameter is an unsigned **__int64** value that specifies the current time, in (10^-7) second intervals that have elapsed since 12:00 A.M. January 1, 1601 Coordinated Universal Time (UTC). |
| **TSI_LastSyncTime** | The *pvInfo* parameter is an unsigned **__int64** value that specifies the last synch time, in (10^-7) second intervals that have elapsed since 12:00 A.M. January 1, 1601 Coordinated Universal Time (UTC). |
| **TSI_LeapFlags** | The *pvInfo* parameter is a **BYTE** value that indicates an impending leap second or loss of synchronization. The following values are defined: <br><br>0 - No change<br><br>1 - Add leap second<br><br>2 - Subtract leap second<br><br>3 - Not synchronized |
| **TSI_PhaseOffset** | The *pvInfo* parameter is a signed **__int64** value that specifies the phase offset used to adjust the clock, in seconds. |
| **TSI_PollInterval** | The *pvInfo* parameter is a signed **__int32** value that specifies the poll interval, in log2 seconds. |
| **TSI_ReferenceIdentifier** | The *pvInfo* parameter is a **DWORD** value that specifies the reference identifier for the time source, in NTP format (either an IP address or a four character ASCII string that describes the hardware source, such as Global Positioning System (GPS) or WWVB). |
| **TSI_RootDelay** | The *pvInfo* parameter is a signed **__int64** value that specifies the root delay, in (10^-7) seconds. |
| **TSI_RootDispersion** | The *pvInfo* parameter is an unsigned **__int64** value that specifies, the root dispersion, in (10^-7) seconds. |
| **TSI_Stratum** | The *pvInfo* parameter is a **BYTE** value that specifies the number of network hops that separate this computer from the root source. Hardware providers should return zero. NTP providers should return the stratum of the peer that provided the sample. |
| **TSI_TickCount** | The *pvInfo* parameter is an unsigned **__int64** value that specifies the tick count (number of milliseconds since the system was started). This value will eventually wrap, so it should be used only to compare short intervals. |
| **TSI_TSFlags** | The *pvInfo* parameter is a **DWORD** value that specifies one of the following time source flags: <br><br>TSF_Authenticated<br><br>TSF_Hardware<br><br>TSF_IPv6 |

### `pvInfo` [out]

A pointer to a buffer that receives that state information. The format of this data depends on the value of *eInfo*.

## Return value

If the function succeeds, the return value is S_OK. Otherwise, the return value is one of the error codes defined in WinError.h.

## Remarks

To ensure accuracy, the time provider should retrieve all time-related information using
**GetTimeSysInfoFunc**. Note that the time values should not be used directly in an NTP packet. They are expressed relative to 12:00 A.M. January 1, 1601, whereas NTP specifies that time values be expressed relative to 12:00 A.M. January 1, 1900.

The
[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen) function returns a pointer to this function.

#### Examples

For an example, see [Sample Time Provider](https://learn.microsoft.com/windows/desktop/SysInfo/sample-time-provider).