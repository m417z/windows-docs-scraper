# PERF_COUNTER_REG_INFO structure

## Description

Provides registration information about a performance counter.

## Members

### `CounterId`

A unique identifier for the performance counter within the counter set. A counter set can contain a maximum of 64,000 performance counters.

### `Type`

The type of the performance counter. For information about the predefined counter types, see the Counter Types section of the [Windows Server 2003 Deployment Kit](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc776490(v=ws.10)). Consumers use the counter type to determine how to calculate and display the counter value. Providers should limit their choice of counter types to the predefined list.

The possible values are:

#### PERF_100NSEC_MULTI_TIMER

#### PERF_100NSEC_MULTI_TIMER_II

#### PERF_100NSEC_TIMER

#### PERF_100NSEC_TIMER_INV

#### PERF_AVERAGE_BASE

#### PERF_AVERAGE_BULK

#### PERF_AVERAGE_TIMER

#### PERF_COUNTER_100NS_QUEUELEN_TYPE

#### PERF_COUNTER_BULK_COUNT

#### PERF_COUNTER_COUNTER

#### PERF_COUNTER_DELTA

#### PERF_COUNTER_LARGE_DELTA

#### PERF_COUNTER_LARGE_QUEUELEN_TYPE

#### PERF_COUNTER_LARGE_RAWCOUNT

#### PERF_COUNTER_LARGE_RAWCOUNT_HEX

#### PERF_COUNTER_MULTI_TIMER

#### PERF_COUNTER_MULTI_TIMER_INV

#### PERF_COUNTER_OBJ_QUEUELEN_TYPE

#### PERF_COUNTER_RAWCOUNT

#### PERF_COUNTER_RAWCOUNT_HEX

#### PERF_COUNTER_TEXT

#### PERF_COUNTER_TIMER

#### PERF_COUNTER_TIMER_INV

#### PERF_ELAPSED_TIME

#### PERF_LARGE_RAW_BASE

#### PERF_OBJ_TIME_TIMER

#### PERF_PRECISION_100NS_TIMER

#### PERF_PRECISION_TIMER

#### PERF_PRECISION_OBJECT_TIMER

#### PERF_RAW_BASE

#### PERF_RAW_FRACTION

#### PERF_SAMPLE_COUNTER

#### PERF_SAMPLE_FRACTION

### `Attrib`

One or more attributes that indicate how to display this counter.

The possible values are:

| Value | Meaning |
| --- | --- |
| **PERF_ATTRIB_BY_REFERENCE** | Retrieve the value of the counter by reference as opposed to by value. |
| **PERF_ATTRIB_NO_DISPLAYABLE** | Do not display the counter value. |
| **PERF_ATTRIB_NO_GROUP_SEPARATOR** | Do not use digit separators when displaying counter value. |
| **PERF_ATTRIB_DISPLAY_AS_REAL** | Display the counter value as a real value. |
| **PERF_ATTRIB_DISPLAY_AS_HEX** | Display the counter value as a hexadecimal number. |

The attributes **PERF_ATTRIB_NO_GROUP_SEPARATOR**, **PERF_ATTRIB_DISPLAY_AS_REAL**, and **PERF_ATTRIB_DISPLAY_AS_HEX** are not mutually exclusive. If you specify all three attributes, precedence is given to the attributes in the order given.

### `DetailLevel`

The target audience for the counter.

The possible values are:

| Value | Meaning |
| --- | --- |
| **PERF_DETAIL_NOVICE** | You can display the counter to any level of user. |
| **PERF_DETAIL_ADVANCED** | The counter is complicated and should be displayed only to advanced users. |

### `DefaultScale`

The scaling factor to apply to the raw performance counter value. Valid values range from –10 through 10. Zero if no scale is applied. If this value is zero, the scale value is 1; if this value is 1, the scale value is 10; if this value is –1, the scale value is .10; and so on. The scaled value of the performance counter is equal to the raw value of the performance counter multiplied by 10 raised to the power that the **DefaultScale** member specifies.

### `BaseCounterId`

The counter identifier of the base counter. 0xFFFFFFFF indicates that there is no base counter.

### `PerfTimeId`

The counter identifier of the performance counter. 0xFFFFFFFF indicates that there is no performance counter.

### `PerfFreqId`

The counter identifier of the frequency counter. 0xFFFFFFFF indicates that there is no frequency counter.

### `MultiId`

 The counter identifier of the multi-counter. 0xFFFFFFFF indicates that there is no multi-counter.

### `AggregateFunc`

The aggregation function the client should apply to the counter if the

counter set to which the counter belongs is of type Global Aggregate, Multiple

Instance Aggregate, or Global Aggregate History. The client specifies the counter instances across which the aggregation is performed if the counter set type

is Multiple Instance Aggregate; otherwise, the client must aggregate values

across all instances of the counter set. One of the following values must be

specified.

| Value | Meaning |
| --- | --- |
| **PERF_AGGREGATE_UNDEFINED** | Undefined. |
| **PERF_AGGREGATE_TOTAL** | The sum of the values of the returned counter instances. |
| **PERF_AGGREGATE_AVG** | The average of the values of the returned counter instances. |
| **PERF_AGGREGATE_MIN** | The minimum value of the returned counter instance values. |
| **PERF_AGGREGATE_MAX** | The maximum value of the returned counter instance values. |

### `Reserved`

Reserved.

## Remarks

The [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function called with the *requestCode* parameter set to **PERF_REG_COUNTERSET_STRUCT** gets a [PERF_COUNTERSET_REG_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_reg_info) block that
contains one or more **PERF_COUNTER_REG_INFO** structures.

The [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function called with the *requestCode* parameter set to
**PERF_REG_COUNTER_STRUCT** gets a **PERF_COUNTER_REG_INFO** structure.

## See also

[PERF_COUNTERSET_REG_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_reg_info)

[PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo)