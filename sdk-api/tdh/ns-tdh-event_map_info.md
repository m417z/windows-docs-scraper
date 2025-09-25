# EVENT_MAP_INFO structure

## Description

Defines the metadata about the event map.

## Members

### `NameOffset`

Offset from the beginning of this structure to a null-terminated Unicode string that contains the name of the event map.

### `Flag`

Indicates if the map is a value map, bitmap, or pattern map. This member can contain one or more flag values. For possible values, see the [MAP_FLAGS](https://learn.microsoft.com/windows/desktop/api/tdh/ne-tdh-map_flags) enumeration.

### `EntryCount`

Number of map entries in **MapEntryArray**.

### `MapEntryValueType`

Determines if you use the **Value** member or **InputOffset** member of [EVENT_MAP_ENTRY](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_map_entry) to access the map value. For possible values, see the [MAP_VALUETYPE](https://learn.microsoft.com/windows/desktop/api/tdh/ne-tdh-map_valuetype) enumeration.

### `FormatStringOffset`

If the value of **Flag** is EVENTMAP_INFO_FLAG_MANIFEST_PATTERNMAP, use this offset to access the null-terminated Unicode string that contains the value of the **format** attribute of the [patternMap](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-patternmaptype-complextype) element. The offset is from the beginning of this structure.

The EVENTMAP_INFO_FLAG_MANIFEST_PATTERNMAP also indicates that you use the **InputOffset** member of [EVENT_MAP_ENTRY](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_map_entry) to access the map value.

### `MapEntryArray`

 Array of map entries. For details, see the [EVENT_MAP_ENTRY](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_map_entry) structure.

## See also
[TdhGetEventMapInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgeteventmapinformation)