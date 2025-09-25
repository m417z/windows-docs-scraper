# ISyncMgrSyncCallback::AddItemToSession

## Description

Adds a specified item to the set of items currently being synchronized.

## Parameters

### `pszItemID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the item to add. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. Returns E_INVALIDARG if *pszItemID* is already part of the session.

## Remarks

**ISyncMgrSyncCallback::AddItemToSession** is called by the sync handler.

#### Examples

The following example shows the usage of **ISyncMgrSyncCallback::AddItemToSession** by the [Synchronize](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-synchronize) method.

```cpp
HRESULT CMyDeviceHandler::Synchronize(...)
{
    ...

    // Start synchronizing the handler.

    ...

    // Check for additional items to sync.
    IEnumString *penumItemIDs = NULL;

    hr = pCallback->QueryForAdditionalItems(&penumItemIDs);
    if (hr == S_OK)
    {
        while (hr == S_OK)
        {
            LPWSTR pszItemID;
            ULONG cFetched;
            hr = penumItemIDs->Next(1, &pszItemID, &cFetched);
            if ((hr == S_OK) && (cFetched == 1))
            {
                // Add this item to the set of items we are syncing.
                hr = pCallback->AddItemToSession(pszItemID);
                CoTaskMemFree(pszItemID);
            }
        }
        penumItemIDs->Release();
    }
    ...
}

```