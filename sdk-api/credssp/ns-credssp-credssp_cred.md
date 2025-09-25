# CREDSSP_CRED structure

## Description

 The **CREDSSP_CRED** structure specifies authentication data for both Schannel and Negotiate [security packages](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Members

### `Type`

The [CREDSPP_SUBMIT_TYPE](https://learn.microsoft.com/windows/win32/api/credssp/ne-credssp-credspp_submit_type) enumeration value that specifies the type of credentials contained in this structure.

### `pSchannelCred`

A pointer to a set of Schannel credentials.

### `pSpnegoCred`

A pointer to a set of Negotiate credentials.

## See also

[AcquireCredentialsHandle (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea)

[CREDSPP_SUBMIT_TYPE](https://learn.microsoft.com/windows/win32/api/credssp/ne-credssp-credspp_submit_type)