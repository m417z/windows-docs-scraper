# ISyncMgrEvent::GetContext

## Description

Gets a context object that can be used by a handler to display properties or execute a context menu action.

## Parameters

### `ppszContext` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to the context as a Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The handler is expected to allocate the buffer using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), which Sync Center uses to deallocate the string buffer.