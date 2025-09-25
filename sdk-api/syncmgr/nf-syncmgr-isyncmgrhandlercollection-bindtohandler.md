# ISyncMgrHandlerCollection::BindToHandler

## Description

Instantiates a specified sync handler when called by Sync Center.

## Parameters

### `pszHandlerID` [in]

Type: **LPCWSTR**

The ID of the sync handler.

### `riid` [in]

Type: **REFIID**

The IID of the requested interface. This will typically be IID_ISyncMgrHandler. If the method fails when passed IID_ISyncMgrHandler, it is recalled using IID_ISyncMgrSynchronize, the IID of the older [ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize) interface. When the method returns successfully, a pointer to the requested interface is referenced in the *ppv* parameter.

### `ppv` [out]

Type: **void****

When this method returns, contains an address of a pointer to an interface representing the sync handler.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is possible for this method to be called by Sync Center without it first calling [ISyncMgrHandlerCollection::GetHandlerEnumerator](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandlercollection-gethandlerenumerator). This is because Sync Center caches information about handlers and their items. The handler collection can return an interface pointer for an existing sync handler or it can create a new instance.

## See also

[ISyncMgrHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrhandler)

[ISyncMgrHandlerCollection](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrhandlercollection)