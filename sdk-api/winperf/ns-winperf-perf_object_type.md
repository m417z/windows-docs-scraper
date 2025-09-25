# PERF_OBJECT_TYPE structure

## Description

Describes object-specific performance information, for example, the number of instances of the object and the number of counters that the object defines.

## Members

### `TotalByteLength`

Size of the object-specific data, in bytes. This member is the offset from the beginning of this structure to the next
**PERF_OBJECT_TYPE** structure, if one exists.

### `DefinitionLength`

Size of this structure plus the size of all the
[PERF_COUNTER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_definition) structures.

If the object is a multiple instance object (the **NumInstances** member is not zero), this member is the offset from the beginning of this structure to the first
[PERF_INSTANCE_DEFINITION](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_instance_definition) structure. Otherwise, this value is the offset to the [PERF_COUNTER_BLOCK](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_block).

### `HeaderLength`

Size of this structure, in bytes. This member is the offset from the beginning of this structure to the first
[PERF_COUNTER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_definition) structure.

### `ObjectNameTitleIndex`

Index to the object's name in the title database. For details on using the index to retrieve the object's name, see [Retrieving Counter Names and Help Text](https://learn.microsoft.com/windows/win32/perfctrs/retrieving-counter-names-and-help-text).

Providers specify the index value in their initialization file. For details, see [Adding Counter Names and Descriptions to the Registry](https://learn.microsoft.com/windows/desktop/PerfCtrs/adding-counter-names-and-descriptions-to-the-registry).

### `ObjectNameTitle`

Reserved.

### `ObjectHelpTitleIndex`

Index to the object's help text in the title database. For details on using the index to retrieve the object's help text, see [Retrieving Counter Names and Help Text](https://learn.microsoft.com/windows/win32/perfctrs/retrieving-counter-names-and-help-text).

Providers specify the index value in their initialization file. For details, see [Adding Counter Names and Descriptions to the Registry](https://learn.microsoft.com/windows/desktop/PerfCtrs/adding-counter-names-and-descriptions-to-the-registry).

### `ObjectHelpTitle`

Reserved.

### `DetailLevel`

Level of detail. Consumers use this value to control display complexity. This value is the minimum detail level of all the counters for a given object. This member can be one of the following values.

| Detail level | Meaning |
| --- | --- |
| **PERF_DETAIL_NOVICE** | The counter data is provided for all users. |
| **PERF_DETAIL_ADVANCED** | The counter data is provided for advanced users. |
| **PERF_DETAIL_EXPERT** | The counter data is provided for expert users. |
| **PERF_DETAIL_WIZARD** | The counter data is provided for system designers. |

### `NumCounters`

Number of [PERF_COUNTER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_definition) blocks returned by the object.

### `DefaultCounter`

Index to the counter's name in the title database of the default counter whose information is to be displayed when this object is selected in the Performance tool. This member may be –1 to indicate that there is no default.

### `NumInstances`

Number of object instances for which counters are being provided. If the object can have zero or more instances, but has none at present, this value should be zero. If the object cannot have multiple instances, this value should be PERF_NO_INSTANCES.

### `CodePage`

This member is zero if the instance strings are Unicode strings. Otherwise, this member is the code-page identifier of the instance names. You can use the code-page value when calling [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) to convert the string to Unicode.

### `PerfTime`

Provider generated timestamp that consumers use when calculating counter values. For example, this could be the current value, in counts, of the high-resolution performance counter.

Providers need to provide this value if the counter types of their counters include the **PERF_OBJECT_TIMER** flag. Otherwise, consumers use the **PerfTime** value from [PERF_DATA_BLOCK](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_data_block).

### `PerfFreq`

Provider generated frequency value that consumers use when calculating counter values. For example, this could be the current frequency, in counts per second, of the high-resolution performance counter.

Providers need to provide this value if the counter types of their counters include the **PERF_OBJECT_TIMER** flag. Otherwise, consumers use the **PerfFreq** value from [PERF_DATA_BLOCK](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_data_block).

## Remarks

Providers use this structure to provide performance data for objects that they support. Consumers use this structure to consume performance data for objects that they queried.

 This structure is followed by a list of
[PERF_COUNTER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_definition) structures, one for each counter defined for the performance object.
For details on the layout of the performance data block, see [Performance Data Format](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-data-format).

## See also

[PERF_COUNTER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_definition)

[PERF_DATA_BLOCK](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_data_block)

[Performance Data Format](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-data-format)