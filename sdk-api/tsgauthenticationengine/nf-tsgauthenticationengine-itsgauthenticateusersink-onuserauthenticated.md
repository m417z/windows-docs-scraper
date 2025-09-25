# ITSGAuthenticateUserSink::OnUserAuthenticated

## Description

Notifies Remote Desktop Gateway (RD Gateway) that the authentication plug-in has successfully authenticated the user.

## Parameters

### `userName` [in]

The name of the user who initiated the connection.

### `userDomain` [in]

The domain of the user who initiated the connection.

### `context` [in]

A pointer to a **ULONG** that contains a value that identifies this connection. Use the value that was passed by the [AuthenticateUser](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nf-tsgauthenticationengine-itsgauthenticationengine-authenticateuser) method.

### `userToken` [in, optional]

A pointer to a **HANDLE** that specifies the user token of the user. If the user is not running Windows, set this parameter to **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can call this method from your implementation of [AuthenticateUser](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nf-tsgauthenticationengine-itsgauthenticationengine-authenticateuser). If authentication requires more than 1 second, we recommend launching a separate thread to perform authentication.

For a sample that uses the **OnUserAuthenticated** method, see the [Remote Desktop Gateway Pluggable Authentication and Authorization](https://github.com/microsoftarchive/msdn-code-gallery-community-m-r/tree/master/Remote%20Desktop%20Gateway%20Pluggable%20Authentication%20and%20Authorization%20Sample) sample.

## See also

[AuthenticateUser](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nf-tsgauthenticationengine-itsgauthenticationengine-authenticateuser)

[ITSGAuthenticateUserSink](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nn-tsgauthenticationengine-itsgauthenticateusersink)