# PropertyType enumeration

## Description

Identifies the type that is stored in a Windows Runtime object that implements the [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) interface.

## Constants

### `PropertyType_Empty:0`

The object does not contain a value.

### `PropertyType_UInt8:1`

The object contains an unsigned 8-bit integer.

### `PropertyType_Int16:2`

The object contains a signed 16-bit integer.

### `PropertyType_UInt16:3`

The object contains an unsigned 16-bit integer.

### `PropertyType_Int32:4`

The object contains a signed 32-bit integer.

### `PropertyType_UInt32:5`

The object contains an unsigned 32-bit integer.

### `PropertyType_Int64:6`

The object contains a signed 64-bit integer.

### `PropertyType_UInt64:7`

The object contains an unsigned 64-bit integer.

### `PropertyType_Single:8`

The object contains a 32-bit floating point value. This value conforms to the IEEE 754 standard.

### `PropertyType_Double:9`

The object contains a 64-bit floating point value. This value conforms to the IEEE 754 standard.

### `PropertyType_Char16:10`

The object contains a 16-bit character. This character represents a UTF-16 (Unicode) code unit.

### `PropertyType_Boolean:11`

The object contains an 8-bit Boolean value.

### `PropertyType_String:12`

The object contains an [HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring).

### `PropertyType_Inspectable:13`

The object contains an object that implements the [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) interface.

### `PropertyType_DateTime:14`

The object contains a [DateTime](https://learn.microsoft.com/windows/desktop/api/windows.foundation/ns-windows-foundation-datetime).

### `PropertyType_TimeSpan:15`

The object contains a [TimeSpan](https://learn.microsoft.com/windows/desktop/api/windows.foundation/ns-windows-foundation-timespan).

### `PropertyType_Guid:16`

The object contains a GUID.

### `PropertyType_Point:17`

The object contains a [Point](https://learn.microsoft.com/windows/desktop/api/windows.foundation/ns-windows-foundation-point).

### `PropertyType_Size:18`

The object contains a [Size](https://learn.microsoft.com/windows/desktop/api/windows.foundation/ns-windows-foundation-size).

### `PropertyType_Rect:19`

The object contains a [Rect](https://learn.microsoft.com/windows/desktop/api/windows.foundation/ns-windows-foundation-rect).

### `PropertyType_OtherType:20`

The object contains an unspecified type.

### `PropertyType_UInt8Array:1025`

The object contains an array of unsigned 8-bit integers.

### `PropertyType_Int16Array:1026`

The object contains an array of signed 16-bit integers.

### `PropertyType_UInt16Array:1027`

The object contains an array of unsigned 16-bit integers.

### `PropertyType_Int32Array:1028`

The object contains an array of signed 32-bit integers.

### `PropertyType_UInt32Array:1029`

The object contains an array of unsigned 32-bit integers.

### `PropertyType_Int64Array:1030`

The object contains an array of signed 64-bit integers.

### `PropertyType_UInt64Array:1031`

The object contains an array of unsigned 64-bit integers.

### `PropertyType_SingleArray:1032`

The object contains an array of 32-bit floating point values.

### `PropertyType_DoubleArray:1033`

The object contains an array of 64-bit floating point values.

### `PropertyType_Char16Array:1034`

The object contains an array of 16-bit characters.

### `PropertyType_BooleanArray:1035`

The object contains an array of 8-bit Boolean values.

### `PropertyType_StringArray:1036`

The object contains an array of [HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring).

### `PropertyType_InspectableArray:1037`

The object contains an array of objects that implement the [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) interface.

### `PropertyType_DateTimeArray:1038`

The object contains an array of [DateTime](https://learn.microsoft.com/windows/desktop/api/windows.foundation/ns-windows-foundation-datetime).

### `PropertyType_TimeSpanArray:1039`

The object contains an array of [TimeSpan](https://learn.microsoft.com/windows/desktop/api/windows.foundation/ns-windows-foundation-timespan).

### `PropertyType_GuidArray:1040`

The object contains an array of GUIDs.

### `PropertyType_PointArray:1041`

The object contains an array of [Point](https://learn.microsoft.com/windows/desktop/api/windows.foundation/ns-windows-foundation-point).

### `PropertyType_SizeArray:1042`

The object contains an array of [Size](https://learn.microsoft.com/windows/desktop/api/windows.foundation/ns-windows-foundation-size).

### `PropertyType_RectArray:1043`

The object contains an array of [Rect](https://learn.microsoft.com/windows/desktop/api/windows.foundation/ns-windows-foundation-rect).

### `PropertyType_OtherTypeArray:1044`

The object contains an array of an unspecified type.

## See also

[IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue)

[IPropertyValueStatics](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvaluestatics)