# ID3D11InfoQueue::GetStorageFilter

## Description

Get the storage filter at the top of the storage-filter stack.

## Parameters

### `pFilter` [out, optional]

Type: **[D3D11_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ns-d3d11sdklayers-d3d11_info_queue_filter)***

Storage filter at the top of the storage-filter stack.

### `pFilterByteLength` [in, out]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Size of the storage filter in bytes. If pFilter is **NULL**, the size of the storage filter will be output to this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11infoqueue)