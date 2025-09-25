# SECPKG_NEGO2_INFO structure

## Description

The **SECPKG_NEGO2_INFO** structure contains extended package information used for NEGO2 negotiations.

This structure is used by the
[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) and
[SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn) functions.

## Members

### `AuthScheme`

The authentication identifier.

### `PackageFlags`

The flags associated with the authentication package.