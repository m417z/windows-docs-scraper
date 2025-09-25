# WSManAuthenticationFlags enumeration

## Description

Determines the authentication method for the operation.

## Constants

### `WSMAN_FLAG_DEFAULT_AUTHENTICATION:0x0`

Use the default authentication.

### `WSMAN_FLAG_NO_AUTHENTICATION:0x1`

Use no authentication for a remote operation.

### `WSMAN_FLAG_AUTH_DIGEST:0x2`

Use Digest authentication. Only the client computer can initiate a Digest authentication request. The client sends a request to the server to authenticate and receives from the server a token string. The client then sends the resource request, including the user name and a cryptographic hash of the password combined with the token string. Digest authentication is supported for HTTP and HTTPS. WinRM Shell client scripts and applications can specify Digest authentication, but the service cannot.

### `WSMAN_FLAG_AUTH_NEGOTIATE:0x4`

Use Negotiate authentication. The client sends a request to the server to authenticate. The server determines whether to use Kerberos or NTLM. In general, Kerberos is selected to authenticate a domain account and NTLM is selected for local computer accounts. But there are also some special cases in which Kerberos/NTLM are selected. The user name should be specified in the form DOMAIN\username for a domain user or SERVERNAME\username for a local user on a server computer.

### `WSMAN_FLAG_AUTH_BASIC:0x8`

Use Basic authentication. The client presents credentials in the form of a user name and password that are directly transmitted in the request message. You can specify the credentials only of a local administrator account on the remote computer.

### `WSMAN_FLAG_AUTH_KERBEROS:0x10`

Use Kerberos authentication. The client and server mutually authenticate by using Kerberos certificates.

### `WSMAN_FLAG_AUTH_CREDSSP:0x80`

Use CredSSP authentication for a remote operation. If a certificate from the local machine is used to authenticate the server, the Network service must be allowed access to the private key of the certificate.

### `WSMAN_FLAG_AUTH_CLIENT_CERTIFICATE:0x20`

Use client certificate authentication. The certificate thumbprint is passed as part of the [WSMAN_AUTHENTICATION_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_authentication_credentials) structure. The WinRM client will try to find the certificate in the computer store and then, if it is not found, in the current user store. If no matching certificate is found, an error will be reported to the user.