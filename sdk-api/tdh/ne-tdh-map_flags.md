# MAP_FLAGS enumeration

## Description

Defines constant values that indicate if the map is a value map, bitmap, or pattern map.

## Constants

### `EVENTMAP_INFO_FLAG_MANIFEST_VALUEMAP:0x1`

The manifest value map maps integer values to strings. For details, see the [MapType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-maptype-complextype) complex type.

### `EVENTMAP_INFO_FLAG_MANIFEST_BITMAP:0x2`

The manifest value map maps bit values to strings. For details, see the [MapType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-maptype-complextype) complex type.

### `EVENTMAP_INFO_FLAG_MANIFEST_PATTERNMAP:0x4`

The manifest value map uses regular expressions to map one name to another name. For details, see the [PatternMapType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-patternmaptype-complextype) complex type.

### `EVENTMAP_INFO_FLAG_WBEM_VALUEMAP:0x8`

The WMI value map maps integer values to strings. For details, see [ValueMap and Value Qualifiers](https://learn.microsoft.com/windows/desktop/WmiSdk/value-map).

### `EVENTMAP_INFO_FLAG_WBEM_BITMAP:0x10`

The WMI value map maps bit values to strings. For details, see [BitMap and BitValue Qualifiers](https://learn.microsoft.com/windows/desktop/WmiSdk/bitmap-and-bitvalues).

### `EVENTMAP_INFO_FLAG_WBEM_FLAG:0x20`

This flag can be combined with the EVENTMAP_INFO_FLAG_WBEM_VALUEMAP flag to indicate that the ValueMap qualifier contains bit (flag) values instead of index values.

### `EVENTMAP_INFO_FLAG_WBEM_NO_MAP:0x40`

This flag can be combined with the EVENTMAP_INFO_FLAG_WBEM_VALUEMAP or EVENTMAP_INFO_FLAG_WBEM_BITMAP flag to indicate that the MOF class property contains a BitValues or Values qualifier but does not contain the BitMap or ValueMap qualifier.

## Remarks

The following MOF example shows the flags that are set based on the WMI property attributes used.

``` syntax
Sets the EVENTMAP_INFO_FLAG_WBEM_VALUEMAP and EVENTMAP_INFO_FLAG_WBEM_NO_MAP flags.
[WmiDataId(1),
Values {"ValueIndex1", "ValueIndex2", "ValueIndex3"}]
uint32  Data1;

Sets the EVENTMAP_INFO_FLAG_WBEM_VALUEMAP flag.
[WmiDataId(2),
ValueMap {"1", "3", "5", "0", "-1"},
Values {"ValueMap1", "ValueMap3", "ValueMap5", "ValueMap0", "ValueMap-1", "Other"}]
sint32  Data2;

Sets the EVENTMAP_INFO_FLAG_WBEM_VALUEMAP and EVENTMAP_INFO_FLAG_WBEM_FLAG flags.
[WmiDataId(3),
ValueType("flag"),
ValueMap {"0x01", "0x02", "0x04", "0x08"},
Values {"ValueMapFlag1", "ValueMapFlag2", "ValueMapFlag4", "ValueMapFlag8"}]
uint32  Data3;

Sets the EVENTMAP_INFO_FLAG_WBEM_VALUEMAP flag.
[WmiDataId(4),
ValueType("index"),
ValueMap {"1", "3", "5", "0", "-1"},
Values {"ValueMapIndex1", "ValueMapIndex3", "ValueMapIndex5", "ValueMapIndex0", "ValueMapIndex-1"}]
sint32  Data4;

Sets the EVENTMAP_INFO_FLAG_WBEM_BITMAP and EVENTMAP_INFO_FLAG_WBEM_NO_MAP flags.
[WmiDataId(5),
BitValues {"BitValueIndex1", "BitValueIndex2", "BitValueIndex3"}]
uint32  Data5;

Sets the EVENTMAP_INFO_FLAG_WBEM_BITMAP flag
[WmiDataId(6),
BitMap {"1", "3", "5", "0"},
BitValues {"BitMap1", "BitMap3", "BitMap5", "BitMap0", "Other"}]
uint32  Data6;
```

## See also
[EVENT_MAP_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_map_info)