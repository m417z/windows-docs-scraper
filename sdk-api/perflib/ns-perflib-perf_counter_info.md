# PERF_COUNTER_INFO structure

## Description

Defines information about a counter that a provider uses. The [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool automatically generates this structure based on the schema you specify.

## Members

### `CounterId`

Identifier that uniquely identifies the counter within the counter set.

### `Type`

Specifies the type of counter. For possible counter types, see [Counter Types](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc776490(v=ws.10)) in the Windows 2003 Deployment Guide.

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

The attributes PERF_ATTRIB_NO_GROUP_SEPARATOR, PERF_ATTRIB_DISPLAY_AS_REAL, and PERF_ATTRIB_DISPLAY_AS_HEX are not mutually exclusive. If you specify all three attributes, precedence is given to the attributes in the order given.

### `Size`

Size, in bytes, of this structure.

### `DetailLevel`

Specify the target audience for the counter.

Possible values are:

| Value | Meaning |
| --- | --- |
| **PERF_DETAIL_NOVICE** | You can display the counter to any level of user. |
| **PERF_DETAIL_ADVANCED** | The counter is complicated and should be displayed only to advanced users. |

### `Scale`

Scale factor to apply to the counter value. Valid values range from –10 through 10. Zero if no scale is applied. If this value is zero, the scale value is 1; if this value is 1, the scale value is 10; if this value is –1, the scale value is .10; and so on.

### `Offset`

Byte offset from the beginning of the [PERF_COUNTERSET_INSTANCE](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_instance) block to the counter value.

## Remarks

This structure is contained within a [PERF_COUNTERSET_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_info) or [PERF_COUNTERSET_INSTANCE](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_instance) block.

## See also

[PERF_COUNTERSET_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_info)

[PERF_COUNTERSET_INSTANCE](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_instance)