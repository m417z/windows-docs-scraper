# EvtGetEventInfo function

## Description

Gets information that identifies the structured XML query that selected the event and the channel or log file that contained the event.

## Parameters

### `Event` [in]

A handle to an event for which you want to retrieve information.

### `PropertyId` [in]

A flag that identifies the information to retrieve. For example, the query identifier or the path. For possible values, see the [EVT_EVENT_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_event_property_id) enumeration.

### `PropertyValueBufferSize` [in]

The size of the *PropertyValueBuffer* buffer, in bytes.

### `PropertyValueBuffer` [in]

A caller-allocated buffer that will receive the information. The buffer contains an [EVT_VARIANT](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_variant) object. You can set this parameter to **NULL** to determine the required buffer size.

### `PropertyValueBufferUsed` [out]

The size, in bytes, of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. Use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code. |

## Remarks

If the query that you passed to [EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery) or [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) was an XPath instead of a structured XML query, the query identifier will be zero and the path will be the path that you passed to the function.