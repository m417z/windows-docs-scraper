# IWSDiscoveryPublisher::RegisterNotificationSink

## Description

Attaches a callback notification sink to the discovery publisher.

## Parameters

### `pSink` [in]

Pointer to an [IWSDiscoveryPublisherNotify](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublishernotify) object that represents the initialized interface to receive callback notifications. This parameter cannot be **NULL**.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *pSink* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The notification sink receives a callback whenever an inbound query is received. It is possible to register multiple notification sinks with a single publisher.

**Note** **RegisterNotificationSink** must be called at least once before any other [IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher) method is used.

## See also

[IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher)