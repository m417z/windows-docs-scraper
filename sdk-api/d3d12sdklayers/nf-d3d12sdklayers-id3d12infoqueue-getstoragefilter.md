# ID3D12InfoQueue::GetStorageFilter

## Description

Get the storage filter at the top of the storage-filter stack.

## Parameters

### `pFilter` [out, optional]

Type: **[D3D12_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ns-d3d12sdklayers-d3d12_info_queue_filter)***

Storage filter at the top of the storage-filter stack.

### `pFilterByteLength` [in, out]

Type: **SIZE_T***

Size of the storage filter in bytes. If *pFilter* is NULL, the size of the storage filter will be output to this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue)