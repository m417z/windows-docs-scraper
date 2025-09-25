# SECPKG_CONTEXT_THUNKS structure

## Description

The **SECPKG_CONTEXT_THUNKS** structure contains information about
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) calls to be executed in LSA mode.

This structure is used by the
[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) and
[SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn) functions.

## Members

### `InfoLevelCount`

The number of attributes specified by the *Levels* parameter.

### `Levels`

An array of one or more context attributes. For a complete list of valid values, see
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa).