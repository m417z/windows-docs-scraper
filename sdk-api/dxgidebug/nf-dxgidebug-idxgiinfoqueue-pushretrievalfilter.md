# IDXGIInfoQueue::PushRetrievalFilter

## Description

Pushes a retrieval filter onto the retrieval-filter stack.

## Parameters

### `Producer` [in]

 A [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) value that identifies the entity that pushes the filter.

### `pFilter` [in]

A pointer to a [DXGI_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ns-dxgidebug-dxgi_info_queue_filter) structure that describes the filter.

## Return value

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue)