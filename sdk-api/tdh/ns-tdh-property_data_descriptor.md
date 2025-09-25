# PROPERTY_DATA_DESCRIPTOR structure

## Description

Defines the property to retrieve.

## Members

### `PropertyName`

Pointer to a null-terminated Unicode string that contains the case-sensitive property name. You can use the **NameOffset** member of the [EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_property_info) structure to get the property name.

The following table lists the possible values of *PropertyName* for WPP events. Use the suggested TDH data type when formatting the returned buffer from [TdhGetProperty](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetproperty).

| Name | TDH Data Type | Description |
| --- | --- | --- |
| FormattedString | TDH_INTYPE_UNICODESTRING | The formatted WPP trace message. |
| SequenceNum | TDH_INTYPE_UINT32 | The local or global sequence number of the trace message. Local sequence numbers, which are unique only to this trace session, are the default. |
| FunctionName | TDH_INTYPE_UNICODESTRING | The name of the function that generated the trace message. |
| ComponentName | TDH_INTYPE_UNICODESTRING | The name of the component of the provider that generated the trace message. The component name appears only if it is specified in the tracing code. |
| SubComponentName | TDH_INTYPE_UNICODESTRING | The name of the subcomponent of the provider that generated the trace message. The subcomponent name appears only if it is specified in the tracing code. |
| TraceGuid | TDH_INTYPE_GUID | The GUID associated with the WPP trace message. |
| GuidTypeName | TDH_INTYPE_UNICODESTRING | The file name concatenated with the line number from the source code from which the WPP trace message was traced. |
| SystemTime | TDH_INTYPE_SYSTEMTIME | The time when the WPP trace message was generated. |
| FlagsName | TDH_INTYPE_UNICODESTRING | The names of the trace flags enabling the trace message. |
| LevelName | TDH_INTYPE_UNICODESTRING | The value of the trace level enabling the trace message. |

### `ArrayIndex`

Zero-based index for accessing elements of a property array. If the property data is not an array or if you want to address the entire array, specify ULONG_MAX (0xFFFFFFFF).

### `Reserved`

Reserved.

## Remarks

To describe a structure, set PropertyName to the name of the structure and ArrayIndex to ULONG_MAX.

To describe a member of a structure, define an array of two **PROPERTY_DATA_DESCRIPTOR** structures. In the first descriptor, set PropertyName to the name of the structure and ArrayIndex to 0. In the second descriptor, set PropertyName to the name of the member and ArrayIndex to ULONG_MAX.

If the structure is an element of an array of structures, set ArrayIndex in the first descriptor to the zero-based index of the structure in the array.

## See also
[TdhGetProperty](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetproperty)

[TdhGetPropertySize](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetpropertysize)