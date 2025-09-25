# IWSManConnectionOptionsEx2::SetProxy

## Description

Sets the proxy information for the session.

## Parameters

### `accessType` [in]

Specifies the proxy access type. This parameter must be set to one of the values in the [WSManProxyAccessTypeFlags](https://learn.microsoft.com/windows/desktop/api/wsmandisp/ne-wsmandisp-wsmanproxyaccesstypeflags) enumeration. The default value is **WSManProxyWinHttpConfig**.

### `authenticationMechanism` [in]

Specifies the authentication mechanism to use for the proxy. This parameter is optional and the default value is 0. If this parameter is set to 0, the WinRM client chooses either Kerberos or Negotiate. Otherwise, this parameter must be set to one of the values in the [WSManProxyAuthenticationFlags](https://learn.microsoft.com/windows/desktop/api/wsmandisp/ne-wsmandisp-wsmanproxyauthenticationflags) enumeration. The default value from the enumeration is **WSManFlagProxyAuthenticationUseNegotiate**.

### `userName` [in]

Specifies the user name for proxy authentication. This parameter is optional. If a value is not specified for this parameter, the default credentials are used.

### `password` [in]

Specifies the password for proxy authentication. This parameter is optional. If a value is not specified for this parameter, the default credentials are used.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default credentials are the credentials under which the current thread is operating.

## See also

[IWSManConnectionOptionsEx2](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanconnectionoptionsex2)