# ISyncMgrSessionCreator::CreateSession

## Description

Notifies Sync Center that synchronization of the specified items has begun.

## Parameters

### `pszHandlerID` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the unique ID of the handler. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `ppszItemIDs` [in]

Type: **LPCWSTR***

The address of a pointer to a buffer containing an array of item IDs, managed by the handler specified in *pszHandlerID*, to be synchronized. Each ID is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `cItems` [in]

Type: **ULONG**

The number of item IDs contained in the buffer referenced in *ppszItemIDs*.

### `ppCallback` [in]

Type: **[ISyncMgrSyncCallback](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsynccallback)****

The address of a pointer to an instance of [ISyncMgrSyncCallback](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsynccallback) used to report progress and events. This value can be **NULL** if no callback is needed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Both *pszHandlerID* and *ppszItemIDs* must be specified.

#### Examples

The following example shows the outline of an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceHandler::Synchronize(...)
{
    ...
    ISyncMgrSyncCallback *pCallback = NULL;

    hr = pCreator->CreateSession(_pszHandlerID, ppszItemIDs, cItems, &pCallback);
    if (SUCCEEDED(hr))
    {
        // Perform synchronization.
    }

    return hr;
}

```