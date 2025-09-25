# EVT_EVENT_PROPERTY_ID enumeration

## Description

Defines the values that determine the query information to retrieve.

## Constants

### `EvtEventQueryIDs:0`

Not supported. The identifier of the query that selected the event. The variant type of this property is EvtVarTypeInt32.

### `EvtEventPath`

The channel or log file from which the event came. The variant type of this property is EvtVarTypeString.

### `EvtEventPropertyIdEND`

This enumeration value marks the end of the enumeration values. It can be used to exit a loop when retrieving all the properties.

## See also

[EvtGetEventInfo](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgeteventinfo)