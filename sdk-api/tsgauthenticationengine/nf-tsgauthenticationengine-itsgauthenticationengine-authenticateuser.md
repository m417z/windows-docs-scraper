# ITSGAuthenticationEngine::AuthenticateUser

## Description

Authenticates a user.

Remote Desktop Gateway (RD Gateway) calls this method when it receives a new connection request. The authentication plug-in
should authenticate the user based on the cookie referenced by the *cookieData*
parameter. The authentication plug-in should then use the
[ITSGAuthenticateUserSink](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nn-tsgauthenticationengine-itsgauthenticateusersink) interface to notify
RD Gateway about the result of authentication.

## Parameters

### `mainSessionId` [in]

A unique identifier assigned to the connection request by RD Gateway.

### `cookieData` [in]

A pointer to a **BYTE** that contains the cookie provided by the user.

### `numCookieBytes` [in]

The number of bytes referenced by the *cookieData* parameter.

### `context` [in]

A pointer to a **ULONG** that contains a value specific to this connection. This
value should be passed back to RD Gateway by using the methods of the
[ITSGAuthenticateUserSink](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nn-tsgauthenticationengine-itsgauthenticateusersink) interface.

### `pSink` [in]

A pointer to a
[ITSGAuthenticateUserSink](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nn-tsgauthenticationengine-itsgauthenticateusersink) interface that
the authentication plug-in must use to notify RD Gateway about the result of authentication.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this method returns **S_OK**, RD Gateway waits for the authentication
plug-in to call a method of the
[ITSGAuthenticateUserSink](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nn-tsgauthenticationengine-itsgauthenticateusersink) interface. If any
other value is returned, RD Gateway immediately denies the connection request.

For a sample that uses the **AuthenticateUser** method, see the [Remote Desktop Gateway Pluggable Authentication and Authorization](https://github.com/microsoftarchive/msdn-code-gallery-community-m-r/tree/master/Remote%20Desktop%20Gateway%20Pluggable%20Authentication%20and%20Authorization%20Sample) sample.

## See also

[ITSGAuthenticationEngine](https://learn.microsoft.com/windows/desktop/api/tsgauthenticationengine/nn-tsgauthenticationengine-itsgauthenticationengine)