# ISyncMgrEventStore::GetEvent

## Description

Gets a specified event object.

## Parameters

### `rguidEventID` [in]

Type: **REFGUID**

A reference to event **GUID**.

### `ppEvent` [out]

Type: **[ISyncMgrEvent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrevent)****

The address of [ISyncMgrEvent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrevent) interface pointer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.