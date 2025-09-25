# IWSDiscoveryPublisher::UnRegisterNotificationSink

## Description

Detaches a callback notification sink from the discovery publisher.

## Parameters

### `pSink` [in]

Pointer to the [IWSDiscoveryPublisherNotify](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublishernotify) interface that will stop receiving callback notifications.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *pSink* is **NULL**. |
| **E_FAIL** | The method failed. |

## Remarks

**Note** **UnRegisterNotificationSink** must be called at least once for each notification sink previously attached to the discovery publisher.

## See also

[IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher)