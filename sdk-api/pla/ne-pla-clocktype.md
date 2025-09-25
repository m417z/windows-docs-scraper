# ClockType enumeration

## Description

Defines the clock resolution to use when tracing events.

## Constants

### `plaTimeStamp:0`

Use the raw (unconverted) time stamp.

### `plaPerformance:1`

Query performance counter. This counter provides a high-resolution (100 nanoseconds) time stamp but is more resource-intensive to retrieve than system time.

### `plaSystem:2`

System time. The system time provides a low-resolution (10 milliseconds) time stamp but is less resource-intensive to retrieve than the query performance counter.

### `plaCycle:3`

CPU cycle counter. The CPU counter provides the highest resolution time stamp and is the least resource-intensive to retrieve. However, the CPU counter is unreliable and should not be used in production.

## Remarks

For details, see the **ClientContext** member of the [WNODE_HEADER](https://learn.microsoft.com/windows/desktop/ETW/wnode-header) structure.

## See also

[ITraceDataCollector::ClockType](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedatacollector-get_clocktype)