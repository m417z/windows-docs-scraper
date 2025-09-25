# ITSGPolicyEngine::AuthorizeResource

## Description

Determines which resources the specified connection is authorized to connect to.

Remote Desktop Gateway (RD Gateway) calls this method after a user has been successfully authenticated. The authorization plug-in should then use the [ITSGAuthorizeConnectionSink](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgauthorizeconnectionsink) interface to notify RD Gateway about the result of authorization.

## Parameters

### `mainSessionId` [in]

A unique identifier assigned to the connection request by RD Gateway.

### `subSessionId` [in]

A unique identifier assigned to the subsession by RD Gateway. A subsession is a session launched from another session.

### `username` [in]

The user name.

### `resourceNames` [in]

A list of resources to authorize.

### `numResources` [in]

The number of resources referenced by the *resourceNames* parameter.

### `alternateResourceNames` [in]

A pointer to a **BSTR** that contains a list of alternate resource names. This parameter is only valid when RD Connection Broker is in use.

### `numAlternateResourceName` [in]

The number of alternate resource names referenced by the *alternateResourceNames* parameter.

### `portNumber` [in]

The port number specified by the user.

### `operation` [in]

The operation that the user is attempting on the resource. This parameter is always set to "RDP".

### `cookie` [in]

A pointer to a **BYTE** that contains the cookie provided by the user. If the user did not authenticate by using a cookie, this parameter is **NULL**.

### `numBytesInCookie` [in]

The number of bytes referenced by the *cookie* parameter.

### `pSink` [in]

A pointer to an [ITSGAuthorizeResourceSink](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgauthorizeresourcesink) interface that the authorization plug-in must use to notify RD Gateway about the result of authorization.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this method returns **S_OK**, RD Gateway waits for the authorization
plug-in to call a method of the
[ITSGAuthorizeResourceSink](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgauthorizeresourcesink) interface. If any
other value is returned, RD Gateway immediately denies the authorization request.

If authorization requires more than 1 second, we recommend starting a separate thread to perform
authorization.

For a sample that uses the **AuthorizeResource** method, see the [Remote Desktop Gateway Pluggable Authentication and Authorization](https://github.com/microsoftarchive/msdn-code-gallery-community-m-r/tree/master/Remote%20Desktop%20Gateway%20Pluggable%20Authentication%20and%20Authorization%20Sample) sample.

## See also

[ITSGPolicyEngine](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgpolicyengine)