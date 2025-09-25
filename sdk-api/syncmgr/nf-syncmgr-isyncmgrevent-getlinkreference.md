# ISyncMgrEvent::GetLinkReference

## Description

Gets the reference for the hot link for the event. The hot link is a displayed property that the user can click to execute an action. This allows the handler to show an available action that the user can see at a glance in the folder.

## Parameters

### `ppszLinkReference` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to a link reference as a Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The link reference is executed when the user clicks on the hot link. When the user clicks the link, Sync Center calls [GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject), requesting the SYNCMGR_OBJECTID_EventLinkClick object for the [ISyncMgrEventLinkUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgreventlinkuioperation) interface. The object is initialized with an [ISyncMgrEvent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrevent) interface pointer that can be used by the *Run* method. If the handler does not support this object ID, Sync Center passes the link reference to [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea).

The event is expected to allocate the string buffer using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), which Sync Center uses to deallocate the string buffer.