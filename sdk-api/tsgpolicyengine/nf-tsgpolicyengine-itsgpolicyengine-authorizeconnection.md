# ITSGPolicyEngine::AuthorizeConnection

## Description

Determines whether the specified connection is authorized to connect to Remote Desktop Gateway (RD Gateway).

RD Gateway calls this method after a user has been successfully authenticated. The authorization plug-in should then use the [ITSGAuthorizeConnectionSink](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgauthorizeconnectionsink) interface to notify RD Gateway about the result of authorization.

## Parameters

### `mainSessionId` [in]

A unique identifier assigned to the connection request by RD Gateway.

### `username` [in]

The user name.

### `authType` [in]

A value of the [AAAuthSchemes](https://learn.microsoft.com/windows/win32/api/tsgpolicyengine/ne-tsgpolicyengine-aaauthschemes) enumeration type that specifies the type of authentication used to connect to RD Gateway.

### `clientMachineIP` [in]

The IP address of the user's computer.

### `clientMachineName` [in]

The name of the user's computer.

### `sohData` [in]

A pointer to a **BYTE** that contains the statement of health (SoH) provided by the user's computer. If the authorization plug-in does not require a statement of health, this parameter is **NULL**. For more information, see the [IsQuarantineEnabled](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nf-tsgpolicyengine-itsgpolicyengine-isquarantineenabled) method.

### `numSOHBytes` [in]

The number of bytes referenced by the *sohData* parameter.

### `cookieData` [in]

A pointer to a **BYTE** that contains the cookie provided by the user. If the **authType** parameter is not set to **AA_AUTH_COOKIE**, this parameter is **NULL**.

### `numCookieBytes` [in]

The number of bytes referenced by the *cookieData* parameter.

### `userToken` [in]

A pointer to a **HANDLE** that specifies the user token of the user. If the user is not running Windows, this parameter is **NULL**.

### `pSink` [in]

A pointer to an [ITSGAuthorizeConnectionSink](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgauthorizeconnectionsink) interface that the authorization plug-in must use to notify RD Gateway about the result of authorization.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this method returns **S_OK**, RD Gateway waits for the authorization
plug-in to call a method of the
[ITSGAuthorizeConnectionSink](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgauthorizeconnectionsink) interface. If
any other value is returned, RD Gateway immediately denies the authorization request.

If authorization requires more than 1 second, we recommend starting a separate thread to perform
authorization.

For a sample that uses the **AuthorizeConnection** method, see the [Remote Desktop Gateway Pluggable Authentication and Authorization](https://github.com/microsoftarchive/msdn-code-gallery-community-m-r/tree/master/Remote%20Desktop%20Gateway%20Pluggable%20Authentication%20and%20Authorization%20Sample) sample.

## See also

[ITSGAuthorizeConnectionSink](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgauthorizeconnectionsink)

[ITSGPolicyEngine](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgpolicyengine)

[IsQuarantineEnabled](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nf-tsgpolicyengine-itsgpolicyengine-isquarantineenabled)