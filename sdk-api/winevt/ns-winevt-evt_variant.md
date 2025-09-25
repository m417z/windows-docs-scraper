# EVT_VARIANT structure

## Description

Contains event data or property values.

## Members

### `BooleanVal`

A Boolean value.

### `SByteVal`

A signed 8-bit integer value.

### `Int16Val`

A signed 16-bit integer value.

### `Int32Val`

A signed 32-bit integer value.

### `Int64Val`

A signed 64-bit integer value.

### `ByteVal`

An unsigned 8-bit integer value.

### `UInt16Val`

An unsigned 16-bit integer value.

### `UInt32Val`

An unsigned 32-bit integer value.

### `UInt64Val`

An unsigned 64-bit integer value.

### `SingleVal`

A single precision real value.

### `DoubleVal`

A double precision real value.

### `FileTimeVal`

An 8-byte FILETIME value.

### `SysTimeVal`

A SYSTEMTIME value.

### `GuidVal`

A 16-byte GUID value.

### `StringVal`

A null-terminated Unicode string.

### `AnsiStringVal`

A null-terminated ANSI string value.

### `BinaryVal`

A pointer to a hexadecimal binary value.

### `SidVal`

A 4-byte ASCII value. A security identifier ([SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)) structure that uniquely identifies a user or group.

### `SizeTVal`

A pointer address. The size of the address (4 bytes or 8 bytes) depends on whether the provider ran on a 32-bit or 64-bit operating system.

### `BooleanArr`

A pointer to an array of Boolean values.

### `SByteArr`

A pointer to an array of signed 8-bit values.

### `Int16Arr`

A pointer to an array of signed 16-bit values.

### `Int32Arr`

A pointer to an array of signed 32-bit values.

### `Int64Arr`

A pointer to an array of signed 64-bit values.

### `ByteArr`

A pointer to an array of unsigned 8-bit values.

### `UInt16Arr`

A pointer to an array of unsigned 16-bit values.

### `UInt32Arr`

A pointer to an array of unsigned 32-bit values.

### `UInt64Arr`

A pointer to an array of unsigned 64-bit values.

### `SingleArr`

A pointer to an array of single precision real values.

### `DoubleArr`

A pointer to an array of double precision real values.

### `FileTimeArr`

A pointer to an array of FILETIME values.

### `SysTimeArr`

A pointer to an array of SYSTEMTIME values.

### `GuidArr`

A pointer to an array of GUID values.

### `StringArr`

A pointer to an array of null-terminated Unicode strings.

### `AnsiStringArr`

A pointer to an array of null-terminated ANSI strings.

### `SidArr`

A pointer to an array of 4-byte ASCII values.

### `SizeTArr`

A pointer to an array of size_t values.

### `EvtHandleVal`

An EVT_HANDLE value.

### `XmlVal`

An XML string value.

### `XmlValArr`

A pointer to an array of XML string values.

### `Count`

The number of elements in the array of values. Use **Count** if the **Type** member has the **EVT_VARIANT_TYPE_ARRAY** flag set.

### `Type`

A flag that specifies the data type of the variant. For possible values, see the [EVT_VARIANT_TYPE](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_variant_type) enumeration.

The variant contains an array of values, if the **EVT_VARIANT_TYPE_ARRAY** flag is set. The members that end in "Arr" contain arrays of values. For example, you would use the **StringArr** member to access the variant data if the type is EvtVarTypeString and the **EVT_VARIANT_TYPE_ARRAY** flag is set.

You can use the [EVT_VARIANT_TYPE_MASK](https://learn.microsoft.com/windows/desktop/WES/windows-event-log-constants) constant to mask out the array bit to determine the variant's type.

## See also

[EVT_SYSTEM_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_system_property_id)

[EVT_VARIANT_TYPE](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_variant_type)

[EVT_VARIANT_TYPE_MASK](https://learn.microsoft.com/windows/desktop/WES/windows-event-log-constants)