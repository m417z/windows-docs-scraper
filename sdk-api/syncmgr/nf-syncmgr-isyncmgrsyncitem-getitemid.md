# ISyncMgrSyncItem::GetItemID

## Description

Gets the unique ID of a sync item.

## Parameters

### `ppszItemID` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to a buffer containing the item's ID. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The ID retrieved by this method cannot change. Typically, the ID is in the form of a GUID string. However, this is not a requirement. The ID can be any string that is unique in the context of the handler.

If **GetItemID** fails or an empty string is returned in *ppszItemID*, the sync item is not shown in the handler's folder and Sync Center will not attempt to synchronize it.

The ID retrieved by this method is available in the folder UI as the System.Sync.ItemID (PKEY_Sync_HandlerID) property.

The item is responsible for allocating the string buffer pointed to by *ppszComment* through [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). Sync Center deallocates the string buffer through [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

In older Sync Manager implementations, this data was retrieved through the [SYNCMGRITEM](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgritem) structure.

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceSyncItem::GetItemID(__out LPWSTR *ppszItemID)
{
    HRESULT hr = S_OK;
    *ppszName = NULL;

    // Generate the string version of the ID.
    if (_pszItemID == NULL)
    {
        LPOLESTR pszItemID = NULL;
        hr = StringFromCLSID(_guidItemID, &_pszItemID);
    }

    if (SUCCEEDED(hr))
    {
        // Duplicate the item ID string for the caller.
        hr = SHCoAllocString(_pszItemID, ppszItemID);
    }

    return hr;
}

```