# ITSGAuthenticateUserSink::OnUserAuthenticationFailed

## Description

Notifies Remote Desktop Gateway (RD Gateway) that the authentication plug-in failed to authenticate the user.

## Parameters

### `context` [in]

A pointer to a **ULONG** that contains a value that identifies this connection. Use the value that was passed by the [AuthenticateUser](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nf-tsgauthenticationengine-itsgauthenticationengine-authenticateuser) method.

### `genericErrorCode` [in]

A Windows error code that specifies the cause of the authentication failure.

### `specificErrorCode` [in]

This parameter is reserved. Always set this parameter to zero.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can call this method from your implementation of
[AuthenticateUser](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nf-tsgauthenticationengine-itsgauthenticationengine-authenticateuser). If
authentication requires more than 1 second, we recommend launching a separate thread to perform
authentication.

For a sample that uses the **OnUserAuthenticationFailed** method, see the [Remote Desktop Gateway Pluggable Authentication and Authorization](https://github.com/microsoftarchive/msdn-code-gallery-community-m-r/tree/master/Remote%20Desktop%20Gateway%20Pluggable%20Authentication%20and%20Authorization%20Sample) sample.

## See also

[ITSGAuthenticateUserSink](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nn-tsgauthenticationengine-itsgauthenticateusersink)