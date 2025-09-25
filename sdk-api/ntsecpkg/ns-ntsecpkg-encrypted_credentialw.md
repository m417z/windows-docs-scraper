# ENCRYPTED_CREDENTIALW structure

## Description

Represents an encrypted credential.

## Members

### `Cred`

A pointer to a [CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credentiala) structure that contains the encrypted credential.

### `ClearCredentialBlobSize`

The size, in bytes, of the unencrypted credential.

## See also

[CrediFreeCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-credfreecredentialsfn)

[CrediRead](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-credreadfn)

[CrediReadDomainCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-credreaddomaincredentialsfn)

[CrediWrite](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-credwritefn)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)