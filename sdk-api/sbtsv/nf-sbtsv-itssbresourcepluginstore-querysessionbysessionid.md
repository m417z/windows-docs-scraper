# ITsSbResourcePluginStore::QuerySessionBySessionId

## Description

Returns the session object that has the specified session ID.

## Parameters

### `dwSessionId` [in]

The session ID.

### `TargetName` [in]

The target name.

### `ppSession` [out]

A pointer to a pointer to an [ITsSbSession](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbsession) session object. When you have finished using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A resource plug-in can use this method to retrieve a session object. Unlike the global store, the resource plug-in store does not copy the session object retrieved because the resource plug-in owns the session object.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[ITsSbResourcePluginStoreEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbresourcepluginstoreex)

[ITsSbSession](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbsession)