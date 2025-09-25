# ITSGAuthenticateUserSink::ReauthenticateUser

## Description

Notifies Remote Desktop Gateway (RD Gateway) that it should silently reauthenticate and reauthorize the
user.

## Parameters

### `context` [in]

A pointer to a **ULONG** that contains a value specific to this connection. Use
the value that was passed by the
[AuthenticateUser](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nf-tsgauthenticationengine-itsgauthenticationengine-authenticateuser)
method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When this method is called, RD Gateway silently attempts to reauthenticate and reauthorize the
user. If the attempt fails, it disconnects the user. The authentication plug-in can use this method to
periodically reauthenticate the user as needed.

For a sample that uses the **ReauthenticateUser** method, see the [Remote Desktop Gateway Pluggable Authentication and Authorization](https://github.com/microsoftarchive/msdn-code-gallery-community-m-r/tree/master/Remote%20Desktop%20Gateway%20Pluggable%20Authentication%20and%20Authorization%20Sample) sample.

## See also

[ITSGAuthenticateUserSink](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nn-tsgauthenticationengine-itsgauthenticateusersink)