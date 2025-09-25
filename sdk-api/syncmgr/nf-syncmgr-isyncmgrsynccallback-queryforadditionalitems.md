# ISyncMgrSyncCallback::QueryForAdditionalItems

## Description

Retrieves an enumerator of the set of items that have a pending request to be synchronized. This is the set of items that will be synchronized after the current synchronization is finished.

## Parameters

### `ppenumItemIDs` [out]

Type: **[IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring)****

When this method returns, contains the address of a pointer to an instance of [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) that enumerates sync item IDs. This value is **NULL** if no items are pending.

### `ppenumPunks` [out]

Type: **[IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown)****

When this method returns, contains the address of a pointer to an instance of [IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown) enumerating [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interfaces that are passed to [StartHandlerSync](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-starthandlersync) or [StartItemSync](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-startitemsync). This value is **NULL** if no interfaces are pending.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or an error value otherwise. Returns **S_FALSE** if no items are pending.

## Remarks

Item IDs retrieved by a call to the **Next** method of the retrieved enumerator interface have a maximum length of **MAX_SYNCMGR_ID** including the terminating null character. The calling application is responsible for deallocating each item ID retrieved through the **Next** method by using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).