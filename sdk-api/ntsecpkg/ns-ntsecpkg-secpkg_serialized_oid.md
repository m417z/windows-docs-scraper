# SECPKG_SERIALIZED_OID structure

## Description

The **SECPKG_SERIALIZED_OID** structure contains the security package's object identifier (OID).

This structure is used by the
[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) and
[SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn) functions.

## Members

### `OidLength`

The length of the OID.

### `OidAttributes`

The attributes of the OID.

### `OidValue`

The value of the OID. The value of SECPKG_MAX_OID_LENGTH is currently set to 32.