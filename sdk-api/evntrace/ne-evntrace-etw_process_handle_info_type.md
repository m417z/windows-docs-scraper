# ETW_PROCESS_HANDLE_INFO_TYPE enumeration

## Description

Specifies the operation that will be performed on a trace processing session.
Used with the
[QueryTraceProcessingHandle](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-querytraceprocessinghandle)
function.

Specifies what kind of operation will be done on a handle. currently used with the [QueryTraceProcessingHandle](https://learn.microsoft.com/windows/desktop/ETW/querytraceprocessinghandle) function.

## Constants

### `EtwQueryPartitionInformation:1`

Used to query partition identifying information. _InBuffer_ should be Null.
_OutBuffer_ should be large enough to hold the returned
[ETW_TRACE_PARTITION_INFORMATION](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-etw_trace_partition_information)
structure. Note that this will only return a non-zero structure when the queried
handle is for a trace file generated from a non-host partition on Windows 10,
version 1709 or later.

### `EtwQueryPartitionInformationV2:2`

This is the same as **EtwQueryPartitionInformation**, except that it returns an
`ETW_TRACE_PARTITION_INFORMATION_V2` structure which has string partition IDs.

### `EtwQueryLastDroppedTimes:3`

Returns a ULONG stream count followed by an array of LARGE_INTEGER timestamps,
indexed by CPU number, of the last event dropped on each CPU stream. The zero
timestamp indicates that the CPU stream never dropped any events. The timestamps
use the clock type specified by the trace configuration (e.g. QPC, System Time,
or CPU counter).

### `EtwQueryProcessHandleInfoMax`

Marks the last value in the enumeration for testing purposes. Should not be
used.