# ENUMERATION_BUFFER structure

## Description

The
**ENUMERATION_BUFFER** structure contains information specific to a given flow, including flow name, the number of filters associated with the flow, and an array of filters associated with the flow.

## Members

### `Length`

Number of bytes from the beginning of the
**ENUMERATION_BUFFER** to the next
**ENUMERATION_BUFFER**.

### `OwnerProcessId`

Identifies the owner of the process.

### `FlowNameLength`

Specifies the length of the **FlowName** member.

### `FlowName`

Array of WCHAR characters, of length **MAX_STRING_LENGTH**, that specifies the flow name.

### `pFlow`

Pointer to the corresponding
[TC_GEN_FLOW](https://learn.microsoft.com/windows/desktop/api/traffic/ns-traffic-tc_gen_flow) structure. This structure is placed immediately after the array of TC_GEN_FILTERS and is included in **Length**.

### `NumberOfFilters`

Specifies the number of filters associated with the flow.

### `GenericFilter`

Array of
[TC_GEN_FILTER](https://learn.microsoft.com/windows/desktop/api/traffic/ns-traffic-tc_gen_filter) structures. The number of elements in the array corresponds to the number of filters attached to the specified flow. Note that in order to enumerate through the array of
**TC_GEN_FILTER** structures, you need to increment the pointer to the current
**TC_GEN_FILTER** by using the following:

sizeof(TC_GEN_FILTER) + 2 * [the pattern size of the current
[TC_GEN_FILTER](https://learn.microsoft.com/windows/desktop/api/traffic/ns-traffic-tc_gen_filter) structure].

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[TC_GEN_FILTER](https://learn.microsoft.com/windows/desktop/api/traffic/ns-traffic-tc_gen_filter)

[TC_GEN_FLOW](https://learn.microsoft.com/windows/desktop/api/traffic/ns-traffic-tc_gen_flow)