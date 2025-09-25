# PERF_COUNTER_DEFINITION structure

## Description

Describes a performance counter.

## Members

### `ByteLength`

Size of this structure, in bytes.

### `CounterNameTitleIndex`

Index of the counter's name in the title database. For details on using the index to retrieve the counter's name, see [Retrieving Counter Names and Help Text](https://learn.microsoft.com/windows/win32/perfctrs/retrieving-counter-names-and-help-text).

To set this value, providers add the counter's offset value defined in their symbol file to the **First Counter** registry value. For details, see [Adding Counter Names and Descriptions to the Registry](https://learn.microsoft.com/windows/desktop/PerfCtrs/adding-counter-names-and-descriptions-to-the-registry) and [Implementing the OpenPerformanceData function](https://learn.microsoft.com/windows/desktop/PerfCtrs/implementing-openperformancedata).

This value should be zero if the counter is a base counter (**CounterType** includes the PERF_COUNTER_BASE flag).

### `CounterNameTitle`

Reserved.

### `CounterHelpTitleIndex`

Index to the counter's help text in the title database. For details on using the index to retrieve the counter's help text, see [Retrieving Counter Names and Help Text](https://learn.microsoft.com/windows/win32/perfctrs/retrieving-counter-names-and-help-text).

To set this value, providers add the counter's offset value defined in their symbol file to the **First Help** registry value. For details, see [Adding Counter Names and Descriptions to the Registry](https://learn.microsoft.com/windows/desktop/PerfCtrs/adding-counter-names-and-descriptions-to-the-registry) and [Implementing the OpenPerformanceData function](https://learn.microsoft.com/windows/desktop/PerfCtrs/implementing-openperformancedata).

This value should be zero if the counter is a base counter (**CounterType** includes the PERF_COUNTER_BASE flag).

### `CounterHelpTitle`

Reserved.

### `DefaultScale`

Scale factor to use when graphing the counter value. Valid values range from -7 to 7 (the values correspond to 0.0000001 - 10000000). If this value is zero, the scale value is 1; if this value is 1, the scale value is 10; if this value is –1, the scale value is .10; and so on.

### `DetailLevel`

Level of detail for the counter. Consumers use this value to control display complexity. This member can be one of the following values.

| Detail level | Meaning |
| --- | --- |
| **PERF_DETAIL_NOVICE** | The counter data is provided for all users. |
| **PERF_DETAIL_ADVANCED** | The counter data is provided for advanced users. |
| **PERF_DETAIL_EXPERT** | The counter data is provided for expert users. |
| **PERF_DETAIL_WIZARD** | The counter data is provided for system designers. |

### `CounterType`

Type of counter. For a list of predefined counter types, see the Counter Types section of the [Windows Server 2003 Deployment Kit](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc776490(v=ws.10)). Consumers use the counter type to determine how to calculate and display the counter value. Providers should limit their choice of counter types to the predefined list.

### `CounterSize`

Counter size, in bytes.

Currently, only DWORDs (4 bytes) and ULONGLONGs (8 bytes) are used to provide counter values.

### `CounterOffset`

Offset from the start of the
[PERF_COUNTER_BLOCK](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_block) structure to the first byte of this counter. The location of the **PERF_COUNTER_BLOCK** structure within the [PERF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_object_type) block depends on if the object contains instances. For details, see [Performance Data Format](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-data-format).

Note that multiple counters can use the same raw data and point to the same offset in the [PERF_COUNTER_BLOCK](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_block) block.

## Remarks

A [PERF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_object_type) structure contains one or more counters. This structure defines each counter and gives the offset to its value. These structures follow the **PERF_OBJECT_TYPE** structure in memory. For details, see [Performance Data Format](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-data-format).

Providers should provide their counters in the same order each time their counters are queried. If the counter uses a base counter in its calculation (the counter type includes the **PERF_COUNTER_FRACTION** flag), the base counter must follow this counter in the list of counters. If the counter type includes the **PERF_MULTI_COUNTER** flag, the second counter value must follow this counter's value in the [PERF_COUNTER_BLOCK](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_block) block.

## See also

[PERF_COUNTER_BLOCK](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_block)

[PERF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_object_type)