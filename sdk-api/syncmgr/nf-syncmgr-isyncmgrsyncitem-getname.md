# ISyncMgrSyncItem::GetName

## Description

Gets the UI display name of the sync item.

## Parameters

### `ppszName` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to a buffer containing the item's display name. This string is of maximum length MAX_SYNCMGR_NAME including the terminating **null** character. Longer strings are truncated.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If **GetName** fails or an empty string is returned in *ppszItemID*, the sync item is not shown in the handler's folder and Sync Center will not attempt to synchronize it.

The ID retrieved by this method is available in the handler's folder UI as the System.DisplayName (PKEY_DisplayName) property.

The item is responsible for allocating the string buffer pointed to by *ppszComment* through [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). Sync Center deallocates the string buffer through [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

Sync Center calls this method whenever the [UpdateItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updateitem) method is called.

In older Sync Manager implementations, this information was retrieved through the [SYNCMGRHANDLERINFO](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrhandlerinfo) structure.

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceSyncItem::GetName(__out LPWSTR *ppszName)
{
    *ppszName = NULL;
    HRESULT hr = SHCoAllocString(_pszItemName, ppszName);
    return hr;
}

```