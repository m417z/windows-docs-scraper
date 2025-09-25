# PERF_DATA_BLOCK structure

## Description

Describes the performance data block that you queried, for example, the number of performance objects returned by the provider and the time-based values that you use when calculating performance values.

## Members

### `Signature`

Array of four wide-characters that contains "PERF".

### `LittleEndian`

Indicates if the counter values are in big endian format or little endian format. If one, the counter values are in little endian format. If zero, the counter values are in big endian format. This value may be zero (big endian format) if you retrieve performance data from a foreign computer, such as a UNIX computer.

### `Version`

Version of the performance structures.

### `Revision`

Revision of the performance structures.

### `TotalByteLength`

Total size of the performance data block, in bytes.

### `HeaderLength`

Size of this structure, in bytes. You use the header length to find the first [PERF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_object_type) structure in the performance data block.

### `NumObjectTypes`

Number of performance objects in the performance data block.

### `DefaultObject`

Reserved.

### `SystemTime`

Time when the system was monitored. This member is in Coordinated Universal Time (UTC) format.

### `PerfTime`

Performance-counter value, in counts, for the system being monitored. For more information, see [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter).

### `PerfFreq`

Performance-counter frequency, in counts per second, for the system being monitored. For more information, see [QueryPerformanceFrequency](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancefrequency).

### `PerfTime100nSec`

Performance-counter value, in 100 nanosecond units, for the system being monitored. For more information, see [GetSystemTimeAsFileTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeasfiletime).

### `SystemNameLength`

Size of the computer name located at **SystemNameOffset**, in bytes.

### `SystemNameOffset`

Offset from the beginning of this structure to the Unicode name of the computer being monitored.

## Remarks

The performance data block is returned when a consumer calls [RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) to retrieve one or more performance objects. This structure is the first structure in the returned block. The next structure in the block is the [PERF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_object_type) structure, which defines a performance object. For details on the layout of the performance data block, see [Performance Data Format](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-data-format).

Consumers use **PerfTime**, **PerfFreq**, and **PerfTime100nSec** when calculating counter values unless the counter type contains the **PERF_OBJECT_TIMER** flag in which case the consumer uses the **PerfTime** and **PerfFreq** members of [PERF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_object_type).

## See also

[PERF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_object_type)

[Performance Data Format](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-data-format)