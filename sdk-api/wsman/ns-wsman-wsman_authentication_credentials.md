# WSMAN_AUTHENTICATION_CREDENTIALS structure

## Description

Defines the authentication method and the credentials used for server or proxy authentication.

## Members

### `authenticationMechanism`

Defines the authentication mechanism. This member can be set to zero. If it is set to zero, the WinRM client will choose between Kerberos and Negotiate. If it is not set to zero, this member must be one of the values of the [WSManAuthenticationFlags](https://learn.microsoft.com/windows/desktop/api/wsman/ne-wsman-wsmanauthenticationflags) enumeration.

### `userAccount`

Defines the credentials used for authentication. See [WSMAN_USERNAME_PASSWORD_CREDS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_username_password_creds) for more information.

### `certificateThumbprint`

Defines the certificate thumbprint.