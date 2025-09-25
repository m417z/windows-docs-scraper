# GetSystemTimePreciseAsFileTime function

## Description

The
**GetSystemTimePreciseAsFileTime**
function retrieves the current system date and time with the highest possible level of precision (<1us). The
retrieved information is in Coordinated Universal Time (UTC) format.

## Parameters

### `lpSystemTimeAsFileTime` [out]

Type: **LPFILETIME**

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the
current system date and time in UTC format.

## Remarks

**Note** This function is best suited for high-resolution time-of-day measurements, or time stamps that are synchronized to UTC. For high-resolution interval measurements, use [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter) or [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-kequeryperformancecounter). For more info about acquiring high-resolution time stamps, see [Acquiring high-resolution time stamps](https://learn.microsoft.com/windows/desktop/SysInfo/acquiring-high-resolution-time-stamps).