# IDXGIInfoQueue::PushCopyOfStorageFilter

## Description

Pushes a copy of the storage filter that is currently on the top of the storage-filter stack onto the storage-filter stack.

## Parameters

### `Producer` [in]

 A [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) value that identifies the entity that pushes the copy of the storage filter.

## Return value

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue)