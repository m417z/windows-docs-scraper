# SECPKG_CREDENTIAL structure

## Description

Specifies the credentials.

## Members

### `Version`

The version.

### `cbHeaderLength`

The length of the header.

### `cbStructureLength`

The length of the structure, including the header, so that all of the content is in a contiguous buffer.

### `ClientProcess`

The identity of the client process.

### `ClientThread`

The identity of the client thread.

### `LogonId`

The logon identity of the caller.

### `ClientToken`

The client token of the caller.

### `SessionId`

The session identity of the caller.

### `ModifiedId`

The modified identity of the caller.

### `fCredentials`

The credentials that are passed in or returned.

### `Flags`

The credential flags.

### `PrincipalName`

Not currently used.

### `PackageList`

The list of packages. This member is only relevant to SPNego.

### `MarshaledSuppliedCreds`

The supplied credentials that are marshaled. This member contains a [SECPKG_SUPPLIED_CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_supplied_credential) structure.