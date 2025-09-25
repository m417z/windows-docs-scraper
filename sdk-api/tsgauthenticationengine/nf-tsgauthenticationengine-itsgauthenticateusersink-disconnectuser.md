# ITSGAuthenticateUserSink::DisconnectUser

## Description

Notifies Remote Desktop Gateway (RD Gateway) that it should disconnect the client.

## Parameters

### `context` [in]

A pointer to a **ULONG** that contains a value that identifies the connection to disconnect. Use the value that was passed by the [AuthenticateUser](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nf-tsgauthenticationengine-itsgauthenticationengine-authenticateuser) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The authentication plug-in can use this method to disconnect the client as needed. For example, it can call this method if the client's cookie expires.

## See also

[AuthenticateUser](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nf-tsgauthenticationengine-itsgauthenticationengine-authenticateuser)

[ITSGAuthenticateUserSink](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nn-tsgauthenticationengine-itsgauthenticateusersink)