# PROPERTY_FLAGS enumeration

## Description

Defines if the property is contained in a structure or array.

## Constants

### `PropertyStruct:0x1`

The property information is contained in the **structType** member of the [EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_property_info) structure.

### `PropertyParamLength:0x2`

Use the **lengthPropertyIndex** member of the [EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_property_info) structure to locate the property that contains the length value of the property.

### `PropertyParamCount:0x4`

Use the **countPropertyIndex** member of the [EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_property_info) structure to locate the property that contains the size of the array.

### `PropertyWBEMXmlFragment:0x8`

Indicates that the MOF data is in XML format (the event data contains within itself a fully-rendered XML description). This flag is set if the MOF property contains the XMLFragment qualifier.

### `PropertyParamFixedLength:0x10`

Indicates that the length member of the [EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_property_info) structure contains a fixed length, e.g. as specified in the provider manifest with \<data length="12" … />. This flag will not be set for a variable-length field, e.g. \<data length="LengthField" … />, nor will this flag be set for fields where the length is not specified in the manifest, e.g. int32 or null-terminated string. As an example, if *PropertyParamLength* is unset, length is 0, and InType is **TDH_INTYPE_UNICODESTRING**, we must check the *PropertyParamFixedLength* flag to determine the length of the string. If *PropertyParamFixedLength* is set, the string length is fixed at 0. If *PropertyParamFixedLength* is unset, the string is null-terminated.

### `PropertyParamFixedCount:0x20`

Indicates that the count member of the [EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_property_info) structure contains a fixed array count, e.g. as specified in the provider manifest with \<data count="12" … />. This flag will not be set for a variable-length array, e.g. \<data count="ArrayCount" … />, nor will this flag be set for non-array fields. As an example, if *PropertyParamCount* is unset and count is 1, PropertyParamFixedCount flag must be checked to determine whether the field is a scalar value or a single-element array. If *PropertyParamFixedCount* is set, the field is a single-element array. If PropertyParamFixedCount is unset, the field is a scalar value, not an array.

**Caution** This flag is new in the Windows 10 SDK. Earlier versions of the manifest compiler did not set this flag. For compatibility with manifests compiled with earlier versions of the compiler, event processing tools should only use this flag when determining whether to present a field with a fixed count of 1 as an array or a scalar.

### `PropertyHasTags:0x40`

Indicates that the **Tags** field contains valid field tag data.

### `PropertyHasCustomSchema:0x80`

Indicates that the **Type** is described with a custom schema.

**Note** This flag is new in the Windows 10 SDK.

## See also
[EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_property_info)