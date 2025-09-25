# TdhGetWppMessage function

## Description

Retrieves the formatted WPP message embedded into an [EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record) structure.

## Parameters

### `Handle` [in]

Type: **TDH_HANDLE**

A valid decoding handle.

### `EventRecord` [in]

Type: **[PEVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record)**

The event record passed to your [EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback) callback.

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
| **ERROR_INSUFFICIENT_BUFFER** | *BufferSize* is too small. To get the required buffer size, call [TdhGetPropertySize](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetpropertysize). |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |

## Remarks

To retrieve a specific property instead of the decoded event message without specifying a property name, call [TdhGetWppProperty](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetwppproperty).

## See also
[EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record)

[EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback)

[TdhGetPropertySize](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetpropertysize)

[TdhGetWppProperty](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetwppproperty)