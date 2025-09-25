# ITSGAuthorizeConnectionSink::OnConnectionAuthorized

## Description

Notifies Remote Desktop Gateway (RD Gateway) about the result of an attempt to authorize a connection.

## Parameters

### `hrIn` [in]

The result of the authorization attempt. Specify **S_OK** to indicate that the attempt succeeded. Specify any other value to indicate that the attempt failed.

### `mainSessionId` [in]

A unique identifier assigned to the connection request by RD Gateway.

### `cbSoHResponse` [in]

The number of bytes referenced by the *pbSoHResponse* parameter.

### `pbSoHResponse` [in]

A pointer to a **BYTE** that specifies the response to the request for a statement of health (SoH). If the *hrIn* parameter is not **S_OK**, this parameter is ignored.

### `idleTimeout` [in]

The number of minutes that the connection can remain idle before being disconnected. If the *hrIn* parameter is not **S_OK**, this parameter is ignored.

### `sessionTimeout` [in]

 The maximum number of minutes allotted to the session. If the *hrIn* parameter is not **S_OK**, this parameter is ignored.

### `sessionTimeoutAction` [in]

The action to be taken when the session times out. If the *hrIn* parameter is not **S_OK**, this parameter is ignored. This parameter can be one of the following values.

#### SESSION_TIMEOUT_ACTION_DISCONNECT

Disconnect the session.

#### SESSION_TIMEOUT_ACTION_SILENT_REAUTH

Silently reauthenticate and reauthorize the session.

### `trustClass` [in]

This parameter is reserved. Always set it to **AA_TRUSTEDUSER_TRUSTEDCLIENT**. If the *hrIn* parameter is not **S_OK**, this parameter is ignored.

### `policyAttributes` [in]

An array of Boolean values that specify the redirection settings associated with the connection. Each element of the array corresponds to a value of the [PolicyAttributeType](https://learn.microsoft.com/windows/win32/api/tsgpolicyengine/ne-tsgpolicyengine-policyattributetype) enumeration. If the *hrIn* parameter is not **S_OK**, this parameter is ignored.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can call this method from your implementation of
[AuthorizeConnection](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nf-tsgpolicyengine-itsgpolicyengine-authorizeconnection). If
authentication requires more than 1 second, we recommend launching a separate thread to perform
authentication.

For a sample that uses the **OnConnectionAuthorized** method, see the [Remote Desktop Gateway Pluggable Authentication and Authorization](https://github.com/microsoftarchive/msdn-code-gallery-community-m-r/tree/master/Remote%20Desktop%20Gateway%20Pluggable%20Authentication%20and%20Authorization%20Sample) sample.

## See also

[ITSGAuthorizeConnectionSink](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgauthorizeconnectionsink)