# ISyncMgrEventStore::RemoveEvent

## Description

Removes events, as specified.

## Parameters

### `pguidEventIDs` [in]

Type: **GUID***

A pointer to event **GUID**.

### `cEvents` [in]

Type: **ULONG**

The count of events to remove.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.