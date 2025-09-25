# ITSGAuthenticationEngine::CancelAuthentication

## Description

Cancels an existing authentication request.

Remote Desktop Gateway (RD Gateway) calls this method when the user who initiated the connection terminates the connection, or when the connection fails.

## Parameters

### `mainSessionId` [in]

An identifier assigned to the connection request.

### `context` [in]

A pointer to a **ULONG** that contains a value that identifies this connection. This value should be passed back to RD Gateway by using the methods of the [ITSGAuthenticateUserSink](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nn-tsgauthenticationengine-itsgauthenticateusersink) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITSGAuthenticationEngine](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nn-tsgauthenticationengine-itsgauthenticationengine)