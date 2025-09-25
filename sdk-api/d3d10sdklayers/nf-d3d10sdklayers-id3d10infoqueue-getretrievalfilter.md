# ID3D10InfoQueue::GetRetrievalFilter

## Description

Get the retrieval filter at the top of the retrieval-filter stack.

## Parameters

### `pFilter` [out]

Type: **[D3D10_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter)***

Retrieval filter at the top of the retrieval-filter stack.

### `pFilterByteLength` [in, out]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Size of the retrieval filter in bytes. If pFilter is **NULL**, the size of the retrieval filter will be output to this parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)