# PAYLOAD_FILTER_PREDICATE structure

## Description

Defines an event payload filter predicate that describes how to filter on a single field in a trace session.

## Members

### `FieldName`

The name of the field to filter in package manifest.

### `CompareOp`

The payload operator to use for the comparison.

This member can be one of the values for the [**PAYLOAD_OPERATOR**](https://learn.microsoft.com/windows/win32/api/tdh/ne-tdh-payload_operator) enumeration defined in the *Tdh.h* header file.

| Value | Meaning |
| --- | --- |
| **PAYLOADFIELD_EQ**<br><br>0 | The value of the **FieldName** parameter is equal to the numeric value of the string in the **Value** member. <br><br>This operator is for comparing integers and requires one value in the **Value** member. |
| **PAYLOADFIELD_NE**<br><br>1 | The value of the **FieldName** parameter is not equal to the numeric value of the string in the **Value** member. <br><br>This operator is for comparing integers and requires one value in the **Value** member. |
| **PAYLOADFIELD_LE**<br><br>2 | The value of the **FieldName** parameter is less than or equal to the numeric value of the string in the **Value** member. <br><br>This operator is for comparing integers and requires one value in the **Value** member. |
| **PAYLOADFIELD_GT**<br><br>3 | The value of the **FieldName** parameter is greater than the numeric value of the string in the **Value** member. <br><br>This operator is for comparing integers and requires one value in the **Value** member. |
| **PAYLOADFIELD_LT**<br><br>4 | The value of the **FieldName** parameter is less than the numeric value of the string in the **Value** member. <br><br>This operator is for comparing integers and requires one value in the **Value** member. |
| **PAYLOADFIELD_GE**<br><br>5 | The value of the **FieldName** parameter is greater than or equal to the numeric value of the string in the **Value** member. <br><br>This operator is for comparing integers and requires one value in the **Value** member. |
| **PAYLOADFIELD_BETWEEN**<br><br>6 | The value of the **FieldName** parameter is between the two numeric values in the string in the **Value** member. The **PAYLOADFIELD_BETWEEN** operator uses a closed interval (LowerBound <= FieldValue <= UpperBound).<br><br>This operator is for comparing integers and requires two values in the **Value** member. The two values should be separated by a comma character (','). |
| **PAYLOADFIELD_NOTBETWEEN**<br><br>7 | The value of the **FieldName** parameter is not between the two numeric values in the string in the **Value** member. <br><br>This operator is for comparing integers and requires two values in the **Value** member. The two values should be separated by a comma character (','). |
| **PAYLOADFIELD_MODULO**<br><br>8 | The value of the **FieldName** parameter is the modulo of the numeric value in the string in the **Value** member. The operator can be used for periodic sampling. <br><br>This operator is for comparing integers and requires one value in the **Value** member. |
| **PAYLOADFIELD_CONTAINS**<br><br>20 | The value of the **FieldName** parameter contains the substring value in the **Value** member. String comparisons are case insensitive.<br><br>This operator is for comparing strings and requires one value in the **Value** member. |
| **PAYLOADFIELD_DOESNTCONTAIN**<br><br>21 | The value of the **FieldName** parameter does not contain the substring in the **Value** member. String comparisons are case insensitive.<br><br>This operator is for comparing strings and requires one value in the **Value** member. |
| **PAYLOADFIELD_IS**<br><br>30 | The value of the **FieldName** parameter is identical to the value of the string in the **Value** member. String comparisons are case insensitive.<br><br>This operator is for comparing strings or other non-integer values and requires one value in the **Value** member. |
| **PAYLOADFIELD_ISNOT**<br><br>31 | The value of the **FieldName** parameter is not identical to the value of the string in the **Value** member. String comparisons are case insensitive.<br><br>This operator is for comparing strings or other non-integer values and requires one value in the **Value** member. |
| **PAYLOADFIELD_INVALID**<br><br>32 | A value of the payload operator that is not valid. |

### `Value`

The string that contains one or values to compare depending on the **CompareOp** member.

## Remarks

On Windows 8.1,Windows Server 2012 R2, and later, event payload filters can be used by the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function and the [ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/desktop/ETW/enable-trace-parameters) and [EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor) structures to filter on the specific content of the event in a logger session.

The **PAYLOAD_FILTER_PREDICATE** structure is used with the [TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter) function to create a single payload filter for a single payload to be used with the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function. A single payload filter can also be aggregated with other single payload filters using the [TdhAggregatePayloadFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhaggregatepayloadfilters) function.

Each field has a type specified in the provider manifest that can be used in the **Fieldname** member of the **PAYLOAD_FILTER_PREDICATE** structure to filter on that field.

The **CompareOp** member specifies that operator to use for payload filtering. Payload filtering supports filtering on a string (including a **GUID**) and integers (including **TDH_INTYPE_FILETIME**). Filtering on floating-point numbers, a binary blob (including **TDH_INTYPE_POINTER**), and structured data (**SID** and **SYSTEMTIME**) are not supported.

The **Value** member contains a string of the value or values to compare with the value of the **Fieldname** member. The **Value** member is converted from a string to the type of the **Fieldname** member as specified in the manifest.

All string comparisons are case-insensitive. The string in the **Value** member is UNICODE, but it will be converted to ANSI if the type specified in the manifest is ANSI.

A **Fieldname** member that contains a **GUID** can only be compared when the **CompareOp** member contains either the **PAYLOADFIELD_IS** or **PAYLOADFIELD_ISNOT** for the payload operator. The string that represents a **GUID** in the **Value** member must contain the curly brackets ({00000000-0000-0000-0000-000000000000}, for example).

#### Examples

For an example that uses
the **PAYLOAD_FILTER_PREDICATE** structure and the [TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter) function to create payload filters to use in filtering on specific conditions in a logger session, see
the example for the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function.

## See also
[ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/desktop/ETW/enable-trace-parameters)

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)

[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)

[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2)

[TdhAggregatePayloadFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhaggregatepayloadfilters)

[TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter)