# WS_OPAQUE_WINDOWS_INTEGRATED_AUTH_CREDENTIAL structure

## Description

Type for supplying a Windows Integrated Authentication credential as an opaque handle created by
SspiPromptForCredentials and the related family of APIs. This feature
is available only on Windows 7 and later.

## Members

### `credential`

The base type from which this type and all other Windows Integrated Authentication credential types derive.

### `opaqueAuthIdentity`

The opaque form of authentication identity. The supplied value must be of the type PSEC_WINNT_AUTH_IDENTITY_OPAQUE.