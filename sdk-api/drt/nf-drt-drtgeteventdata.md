# DrtGetEventData function

## Description

The **DrtGetEventData** function retrieves event data associated with a signaled event.

## Parameters

### `hDrt` [in]

Handle to the Distributed Routing Table instance for which the event occurred.

### `ulEventDataLen` [out]

The size, in bytes, of the *pEventData* buffer.

### `pEventData` [out]

Pointer to a [DRT_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_event_data) structure that contains the event data.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | The DRT infrastructure is unaware of the requested search. |
| **E_HANDLE** | The *hDrt* handle is invalid. |
| **DRT_E_INSUFFICIENT_BUFFER** | The provided buffer is insufficient in size. |
| **DRT_E_NO_MORE** | No more event data available. |

## See also

[DRT_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_event_data)