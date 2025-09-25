# SECPKG_CRED_CLASS enumeration

## Description

Indicates the type of credential used in a client context. The **SECPKG_CRED_CLASS** enumeration is used in the [SecPkgContext_CredInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_credinfo) structure.

## Constants

### `SecPkgCredClass_None:0`

No credentials are supplied.

### `SecPkgCredClass_Ephemeral:10`

Indicates the credentials used to log on to the system.

### `SecPkgCredClass_PersistedGeneric:20`

Indicates saved credentials that are not target specific.

### `SecPkgCredClass_PersistedSpecific:30`

Indicates saved credentials that are target specific.

### `SecPkgCredClass_Explicit` = 40

Indicates credentials explicitly supplied by the user.