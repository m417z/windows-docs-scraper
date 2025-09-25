# SECPKG_GSS_INFO structure

## Description

A **SECPKG_GSS_INFO** structure contains information used for GSS-compatible negotiations.

This structure is used by the
[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) and
[SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn) functions.

## Members

### `EncodedIdLength`

The encoded GSS OID length.

### `EncodedId`

The encoded GSS OID.