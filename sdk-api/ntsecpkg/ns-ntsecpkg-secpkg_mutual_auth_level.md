# SECPKG_MUTUAL_AUTH_LEVEL structure

## Description

The **SECPKG_MUTUAL_AUTH_LEVEL** structure contains the authentication level used by a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

This structure is used by the
[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) and
[SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn) functions.

## Members

### `MutualAuthLevel`

The mutual authentication level.