# KERB_ADD_CREDENTIALS_REQUEST_EX structure

## Description

Specifies a message to add, remove, or replace an extra server credential for a logon session, and
the [service principal names](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SPNs) to be associated with that
credential. The **SeTcbPrivilege** constant is required to alter another logon account's credentials.

## Members

### `Credentials`

A [KERB_ADD_CREDENTIALS_REQUEST](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_add_credentials_request) structure that specifies the credentials to add, remove, or replace.

### `PrincipalNameCount`

The number of elements in the **PrincipalNames** array.

### `PrincipalNames`

An array of SPNs to be associated with the user account specified by the **Credentials** member

## Remarks

Calling the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function with this structure affects only the behavior of the [AcceptSecurityContext (Kerberos)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function. Using this structure allows multiple physical and virtual servers to share a single identity.

## See also

[KERB_ADD_CREDENTIALS_REQUEST](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_add_credentials_request)