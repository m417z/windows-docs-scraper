# EvtGetQueryInfo function

## Description

Gets information about a query that you ran that identifies the list of channels or log files that the query attempted to access. The function also gets a list of return codes that indicates the success or failure of each access.

## Parameters

### `QueryOrSubscription` [in]

 A handle to the query that the[EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery) or [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) function returns.

### `PropertyId` [in]

The identifier of the query information to retrieve. For a list of identifiers, see the [EVT_QUERY_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_query_property_id) enumeration.

### `PropertyValueBufferSize` [in]

The size of the *PropertyValueBuffer* buffer, in bytes.

### `PropertyValueBuffer` [in]

A caller-allocated buffer that will receive the query information. The buffer contains an [EVT_VARIANT](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_variant) object. You can set this parameter to **NULL** to determine the required buffer size.

### `PropertyValueBufferUsed` [out]

The size, in bytes, of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

You only need to call this function, if you pass the EvtQueryTolerateQueryErrors flag to [EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery) or the EvtSubscribeTolerateQueryErrors flag to [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe).

#### Examples

For an example that shows how to use this function, see [Querying for Events](https://learn.microsoft.com/windows/desktop/WES/querying-for-events).

## See also

[EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery)

[EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe)