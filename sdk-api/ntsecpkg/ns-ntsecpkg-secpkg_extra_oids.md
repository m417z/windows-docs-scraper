# SECPKG_EXTRA_OIDS structure

## Description

The **SECPKG_EXTRA_OIDS** structure contains the object identifiers (OIDs) for the extended security package.

This structure is used by the
[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) and
[SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn) functions.

## Members

### `OidCount`

The total number of OIDs in the security package.

### `Oids`

A [SECPKG_SERIALIZED_OID](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_serialized_oid) structure containing the OID data.