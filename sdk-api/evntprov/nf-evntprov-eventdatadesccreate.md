# EventDataDescCreate function

## Description

Sets the values of an
[EVENT_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_data_descriptor).

## Parameters

### `EventDataDescriptor` [out]

The data descriptor whose member values are set to those of the remaining
parameters. For details, see
[EVENT_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_data_descriptor).

### `DataPtr` [in]

A pointer to the event data. This value is used to set the _Ptr_ member of the
descriptor.

_DataPtr_ parameter may be **NULL** if and only if _DataSize_ is 0.

### `DataSize` [in]

The size (in bytes) of the event data. The value is used to set the _Size_
member of the descriptor.

## Return value

This function does not return a value.

## Remarks

This is a convenience macro for setting the members of the
[EVENT_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_data_descriptor)
structure. Note that if you initialize the members yourself without calling
**EventDataDescCreate**, you should set `Ptr = (UINT_PTR)DataPtr`, and you
**must** initialize the _Reserved_ field (e.g. set it to 0),