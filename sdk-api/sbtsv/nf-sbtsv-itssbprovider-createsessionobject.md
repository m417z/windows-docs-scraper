# ITsSbProvider::CreateSessionObject

## Description

Plug-ins can use the **CreateSessionObject** method to create an [ITsSbSession](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbsession) session object.

## Parameters

### `TargetName` [in]

A **BSTR** variable that contains the target name.

### `UserName` [in]

A **BSTR** variable that contains the user name.

### `Domain` [in]

A **BSTR** variable that contains the domain.

### `SessionId` [in]

A **DWORD** variable that contains the session ID.

### `ppSession` [out]

A pointer to a pointer to the new session object. When you have finished using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)

[ITsSbSession](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbsession)