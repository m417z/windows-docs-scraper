# EVENT_MAP_ENTRY structure

## Description

Defines a single value map entry.

## Members

### `OutputOffset`

Offset from the beginning of the [EVENT_MAP_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_map_info) structure to a null-terminated Unicode string that contains the string associated with the map value in **Value** or **InputOffset**.

### `Value`

If the **MapEntryValueType** member of [EVENT_MAP_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_map_info) is EVENTMAP_ENTRY_VALUETYPE_ULONG, use this member to access the map value.

### `InputOffset`

Offset from the beginning of the [EVENT_MAP_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_map_info) structure to the null-terminated Unicode string that contains the map value.

The offset is used for pattern maps and WMI value maps that map strings to strings.

## Remarks

For maps defined in a manifest, the string will contain a space at the end of the string. For example, if the value is mapped to "Monday" in the manifest, the string is returned as "Monday ".

## See also
[EVENT_MAP_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_map_info)