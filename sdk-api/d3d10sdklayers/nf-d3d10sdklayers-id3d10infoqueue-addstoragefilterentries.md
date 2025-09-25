# ID3D10InfoQueue::AddStorageFilterEntries

## Description

Add storage filters to the top of the storage-filter stack.

## Parameters

### `pFilter` [in]

Type: **[D3D10_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter)***

Array of storage filters (see [D3D10_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

A storage filter defines a grouping of debug messages that should be allowed into the info queue.

## See also

[ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)