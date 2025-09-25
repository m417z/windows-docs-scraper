# ISupportFilteredSync::AddFilter

## Description

Sets the filter that is used for change enumeration by the source provider, when implemented by a derived class.

## Parameters

### `pFilter` [in]

The filter that is used for change enumeration by the source provider.

### `filteringType` [in]

A [FILTERING_TYPE](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-filtering_type) enumeration value that indicates the type of information that is included in a change batch during filtered synchronization.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **SYNC_E_FILTER_NOT_SUPPORTED** | When the type of filter that is specified by *pFilter* is not supported. |
| **Provider-determined error codes.** |  |

## Remarks

Filter negotiation is achieved by using the following steps:

1. Before the source provider begins enumerating changes, a synchronization session typically starts filter negotiation by calling [IRequestFilteredSync::SpecifyFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-ifilterrequestcallback-requestfilter) on the destination provider.
2. During processing of [IRequestFilteredSync::SpecifyFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-ifilterrequestcallback-requestfilter), the destination provider passes filters to [IFilterRequestCallback::RequestFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-ifilterrequestcallback-requestfilter).
3. During processing of [IFilterRequestCallback::RequestFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-ifilterrequestcallback-requestfilter), a synchronization session typically calls **ISupportFilteredSync::AddFilter** on the source provider. If the source provider does not support the requested filter, the destination provider can continue to request filters until it finds one that is supported.

When a filter has been successfully negotiated, the source provider uses it to determine which items to include during change enumeration.

**Note** An implementation of this method can examine the filter specified by *pFilter* and *filteringType*, and return [SYNC_E_FILTER_NOT_SUPPORTED](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-error-codes) to indicate that the filter is not supported. The destination provider can then request different filters until one is found that is supported.

Typically the destination provider will end the synchronization session when an error other than [SYNC_E_FILTER_NOT_SUPPORTED](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-error-codes) is returned from **ISupportFilteredSync::AddFilter**.

## See also

[FILTERING_TYPE Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-filtering_type)

[IFilterRequestCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ifilterrequestcallback)

[IRequestFilteredSync Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-irequestfilteredsync)

[ISupportFilteredSync Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isupportfilteredsync)