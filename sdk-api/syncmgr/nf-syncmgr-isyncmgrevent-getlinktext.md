# ISyncMgrEvent::GetLinkText

## Description

Gets the text for the hot link for the event. The hot link is a displayed property that the user can click to execute an action. This allows the handler to show an available action that the user can see at a glance in the folder. The link text is the text that is displayed to the user.

## Parameters

### `ppszLinkText` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to the link text as a Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The event is expected to allocate the string buffer using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), which Sync Center uses to deallocate the string buffer.