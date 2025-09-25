# ITsSbResourcePluginStore::EnumerateSessions

## Description

Enumerates a specified set of sessions.

## Parameters

### `targetName` [in]

The name of the target.

### `userName` [in]

The name of the user account.

### `userDomain` [in]

The domain name of the user account.

### `poolName` [in]

The name of the pool.

### `initialProgram` [in]

The name of the published remote application.

### `pSessionState` [in]

A pointer to the [TSSESSION_STATE](https://learn.microsoft.com/windows/win32/api/sessdirpublictypes/ne-sessdirpublictypes-tssession_state) value of the sessions to enumerate.

### `pdwCount` [in, out]

Returns a pointer to the number of sessions returned.

### `ppVal` [out]

Returns the list of sessions requested.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[ITsSbResourcePluginStoreEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbresourcepluginstoreex)