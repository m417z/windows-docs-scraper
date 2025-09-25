# DrtGetEventDataSize function

## Description

The **DrtGetEventDataSize** function returns the size of the [DRT_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_event_data) structure associated with a signaled event.

## Parameters

### `hDrt` [in]

Handle to the Distributed Routing Table instance for which the event occurred.

### `pulEventDataLen` [out]

The size, in bytes, of the event data.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | The DRT infrastructure is unaware of the requested search. |
| **E_INVALIDARG** | *pulEventDataLen* is **NULL**. |
| **E_HANDLE** | *hDrt* is invalid. |
| **DRT_E_NO_MORE** | There is no more event data available. |

## See also

[DRT_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_event_data)