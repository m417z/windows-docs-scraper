# EVT_QUERY_PROPERTY_ID enumeration

## Description

Defines the identifiers that identify the query information that you can retrieve.

## Constants

### `EvtQueryNames`

Identifies the property that contains the list of channel or log file names that are specified in the query. The variant type for this property is **EvtVarTypeString \| EVT_VARIANT_TYPE_ARRAY**.

### `EvtQueryStatuses`

Identifies the property that contains the list of Win32 error codes that correspond directly to the list of channel or log file names that the EvtQueryNames property returns. The error codes indicate the success or failure of the query for the specific channel or log file. The variant type for this property is **EvtVarTypeUInt32 \| EVT_VARIANT_TYPE_ARRAY**.

### `EvtQueryPropertyIdEND`

This enumeration value marks the end of the enumeration values.

## See also

[EvtGetQueryInfo](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetqueryinfo)