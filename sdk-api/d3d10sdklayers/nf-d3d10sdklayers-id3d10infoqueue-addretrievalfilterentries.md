# ID3D10InfoQueue::AddRetrievalFilterEntries

## Description

Add storage filters to the top of the retrieval-filter stack.

## Parameters

### `pFilter` [in]

Type: **[D3D10_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter)***

Array of retrieval filters (see [D3D10_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

A retrieval filter is used to define a subgroup of the messages that are already in the info queue.
Retrieval filters affect the messages that will be returned by [ID3D10InfoQueue::GetMessage](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10infoqueue-getmessage).

The number of messages already in the info queue that will be allowed through the retrieval filter can be determined
by calling [ID3D10InfoQueue::GetNumStoredMessagesAllowedByRetrievalFilter](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10infoqueue-getnumstoredmessagesallowedbyretrievalfilter).

## See also

[ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)