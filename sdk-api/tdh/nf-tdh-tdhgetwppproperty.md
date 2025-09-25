# TdhGetWppProperty function

## Description

Retrieves a specific property associated with a WPP message.

## Parameters

### `Handle` [in]

Type: **TDH_HANDLE**

A valid decoding handle.

### `EventRecord` [in]

Type: **[PEVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record)**

The event record passed to your [EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback) callback.

### `PropertyName` [in]

Type: **PWSTR**

The name of the property to retrieve.

For a list of possible values, see [PROPERTY_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-property_data_descriptor).

### `BufferSize` [in, out]

Type: **PULONG**

Size of the *Buffer* parameter, in bytes.

### `Buffer` [out]

Type: **PBYTE**

User-allocated buffer that receives the property data.

## Return value

Type: **ULONG**

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_FOUND** | The specified property was not found. |
| **ERROR_INSUFFICIENT_BUFFER** | *BufferSize* is too small. To get the required buffer size, call [TdhGetWppProperty](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetwppproperty) twice, once with a null buffer and a pointer to retrieve the buffer size and then again with the correctly sized buffer. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is incorrect. This error is returned if the *Handle*, *EventRecord*, *PropertyName*, or *Buffer* parameter is **NULL**. |

## Remarks

To retrieve only the decoded event message without specifying a property name, call [TdhGetWppMessage](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetwppmessage).

## See also
[EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record)

[EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback)

[TdhGetPropertySize](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetpropertysize)

[TdhGetWppMessage](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetwppmessage)