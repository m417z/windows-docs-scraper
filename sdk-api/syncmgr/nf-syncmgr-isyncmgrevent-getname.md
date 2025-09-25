# ISyncMgrEvent::GetName

## Description

Gets the name of the event. This string can be a simple name for the event or a short summary. It is displayed in the folder and in the property sheet for the event.

## Parameters

### `ppszName` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to a name as a Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The event is expected to allocate the string buffer using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), which Sync Center uses to deallocate the string buffer.