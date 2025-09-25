# CREDSPP_SUBMIT_TYPE enumeration

## Description

The **CREDSPP_SUBMIT_TYPE** enumeration specifies the type of credentials specified by a [CREDSSP_CRED](https://learn.microsoft.com/windows/desktop/api/credssp/ns-credssp-credssp_cred) structure.

## Constants

### `CredsspPasswordCreds:2`

The credentials are a user name and password.

### `CredsspSchannelCreds:4`

The credentials are Schannel credentials.

### `CredsspCertificateCreds:13`

The credentials are in a certificate.

### `CredsspSubmitBufferBoth:50`

The credentials contain both certificate and Schannel credentials.

### `CredsspSubmitBufferBothOld:51`

### `CredsspCredEx:100`

## See also

[CREDSSP_CRED](https://learn.microsoft.com/windows/desktop/api/credssp/ns-credssp-credssp_cred)