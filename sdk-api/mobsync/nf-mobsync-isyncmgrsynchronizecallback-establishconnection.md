# ISyncMgrSynchronizeCallback::EstablishConnection

## Description

Called by the registered application's handler when a network connection is required.

## Parameters

### `pwszConnection` [in]

Type: **LPCWSTR**

The name of the connection to dial.

### `dwReserved` [in]

Type: **DWORD**

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The connection was successfully established. |

## Remarks

SyncMgr should use the default autodial connection if *pwszConnection* is **NULL**.

When an instance of **EstablishConnection** is called by a handler, SyncMgr tries to establish the connection. If a subsequent
**EstablishConnection** is called then SyncMgr attempts the new connection without causing the previous connection to stop responding. All connections remain until all handlers have finished synchronizing. After all handlers have synchronized, then any opened connections are closed by SyncMgr.

## See also

[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)