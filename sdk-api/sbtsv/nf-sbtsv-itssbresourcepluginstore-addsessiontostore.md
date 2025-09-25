# ITsSbResourcePluginStore::AddSessionToStore

## Description

Adds a new session to the resource plug-in store. Call this method when a user has logged on to a new session.

## Parameters

### `pSession` [in]

A pointer to an [ITsSbSession](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbsession) session object. The target name, user name, domain name, and session ID are required fields.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[ITsSbResourcePluginStoreEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbresourcepluginstoreex)

[ITsSbSession](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbsession)