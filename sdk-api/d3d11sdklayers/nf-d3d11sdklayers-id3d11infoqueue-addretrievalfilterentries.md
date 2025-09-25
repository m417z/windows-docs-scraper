# ID3D11InfoQueue::AddRetrievalFilterEntries

## Description

Add storage filters to the top of the retrieval-filter stack.

## Parameters

### `pFilter` [in]

Type: **[D3D11_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ns-d3d11sdklayers-d3d11_info_queue_filter)***

Array of retrieval filters (see [D3D11_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ns-d3d11sdklayers-d3d11_info_queue_filter)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The following code example shows how to use **ID3D11InfoQueue::AddRetrievalFilterEntries**:

```

D3D11_MESSAGE_CATEGORY cats[] = { ..., ..., ... };
D3D11_MESSAGE_SEVERITY sevs[] = { ..., ..., ... };
UINT ids[] = { ..., ..., ... };

D3D11_INFO_QUEUE_FILTER filter;
memset( &filter, 0, sizeof(filter) );

// To set the type of messages to allow,
// set filter.AllowList as follows:
filter.AllowList.NumCategories = sizeof(cats / sizeof(D3D11_MESSAGE_CATEGORY));
filter.AllowList.pCategoryList = cats;
filter.AllowList.NumSeverities = sizeof(sevs / sizeof(D3D11_MESSAGE_SEVERITY));
filter.AllowList.pSeverityList = sevs;
filter.AllowList.NumIDs = sizeof(ids) / sizeof(UINT);
filter.AllowList.pIDList = ids;

// To set the type of messages to deny, set filter.DenyList
// similarly to the preceding filter.AllowList.

// The following single call sets all of the preceding information.
hr = infoQueue->AddRetrievalFilterEntries( &filter );

```

## See also

[ID3D11InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11infoqueue)