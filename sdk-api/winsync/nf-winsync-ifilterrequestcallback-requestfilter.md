# IFilterRequestCallback::RequestFilter

## Description

Requests that the filter that is specified by the destination provider be used by the source provider during change enumeration.

## Parameters

### `pFilter` [in]

The filter that is specified by the destination provider. This filter is passed to the source provider to be used during change enumeration.

### `filteringType` [in]

A [FILTERING_TYPE](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-filtering_type) enumeration value that indicates the type of information that is included in a change batch during filtered synchronization.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_FILTER_NOT_SUPPPORTED** | When the filter that is specified by *pFilter* is not supported by the source provider. This is also returned when the source provider does not implement [ISupportFilteredSync](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isupportfilteredsync). |

## Remarks

Filter negotiation is achieved by using the following steps:

1. Before the source provider begins enumerating changes, starts filter negotiation by calling [IRequestFilteredSync::SpecifyFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-irequestfilteredsync-specifyfilter) on the destination provider.
2. During processing of [IRequestFilteredSync::SpecifyFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-irequestfilteredsync-specifyfilter), the destination provider passes filters to **IFilterRequestCallback::RequestFilter**.
3. During processing of **IFilterRequestCallback::RequestFilter**, calls [ISupportFilteredSync::AddFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isupportfilteredsync-addfilter) on the source provider. If the source provider does not support the requested filter, the destination provider can continue to request filters until it finds one that is supported.

When a filter has been successfully negotiated, the source provider uses it to determine which items to include during change enumeration.

## See also

[FILTERING_TYPE Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-filtering_type)

[IFilterRequestCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ifilterrequestcallback)

[IRequestFilteredSync Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-irequestfilteredsync)

[ISupportFilteredSync Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isupportfilteredsync)