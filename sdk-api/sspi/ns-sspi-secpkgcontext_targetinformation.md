# SecPkgContext_TargetInformation structure

## Description

The **SecPkgContext_TargetInformation** structure returns information about the credential used for the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This structure is returned by the [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function.

## Members

### `MarshalledTargetInfoLength`

Size, in bytes, of **MarshalledTargetInfo**.

### `MarshalledTargetInfo`

Array of bytes that represent the credential, if a credential is provided by a credential manager.