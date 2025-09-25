# IRequestFilteredSync::SpecifyFilter

## Description

When implemented by a derived class, negotiates which filter is used by the source provider during change enumeration.

## Parameters

### `pCallback` [in]

The callback interface that is used by the destination provider to request that a filter be used by the source provider during change enumeration.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes.** |  |

## Remarks

Filter negotiation is achieved by using the following steps:

1. Before the source provider begins enumerating changes, a synchronization session typically starts filter negotiation by calling **IRequestFilteredSync::SpecifyFilter** on the destination provider.
2. During processing of **IRequestFilteredSync::SpecifyFilter**, the destination provider passes filters to [IFilterRequestCallback::RequestFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-ifilterrequestcallback-requestfilter).
3. During processing of **IFilterRequestCallback::RequestFilter**, a synchronization session typically calls [ISupportFilteredSync::AddFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isupportfilteredsync-addfilter) on the source provider. If the source provider does not support the requested filter, the destination provider can continue to request filters until it finds one that is supported.

When a filter has been successfully negotiated, the source provider uses it to determine which items to include during change enumeration.

**Note** An implementation of this method can repeatedly call [IFilterRequestCallback::RequestFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-ifilterrequestcallback-requestfilter) until a filter is found that is supported by both the destination provider and the source provider. The source provider indicates that it does not support a filter by returning [SYNC_E_FILTER_NOT_SUPPORTED](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-error-codes) in response to the [ISupportFilteredSync::AddFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isupportfilteredsync-addfilter) call.

When [ISupportFilteredSync::AddFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isupportfilteredsync-addfilter) returns an error other than [SYNC_E_FILTER_NOT_SUPPORTED](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-error-codes), **IRequestFilteredSync::SpecifyFilter** should return the error to the Sync Application. This ends the synchronization session.

## See also

[IFilterRequestCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ifilterrequestcallback)

[IRequestFilteredSync Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-irequestfilteredsync)

[ISupportFilteredSync Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isupportfilteredsync)