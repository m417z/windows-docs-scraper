# SECPKG_EXTENDED_INFORMATION_CLASS enumeration

## Description

The **SECPKG_EXTENDED_INFORMATION_CLASS** enumeration describes the type of information to set or get for a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

This enumeration is used by the
[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) and
[SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn) functions.

## Constants

### `SecpkgGssInfo:1`

GSS OID information used to identify the security package in GSS-compatible negotiations.

### `SecpkgContextThunks`

Identifies the calls to the
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function that are handled in the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) process space (LSA mode) rather than being handled in the client process space (user mode).

### `SecpkgMutualAuthLevel`

The mutual authentication level used in the system. This value is valid for the
[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) function only.

### `SecpkgWowClientDll`

Identifies that the WOW client supports a 32-bit version. Otherwise, the WOW client expects the process to run in 64-bit mode. LSA operations are done by the 64-bit version. When the security context is handed back to the client, the 32-bit WOW-aware version is loaded and hands it any information from the 64-bit version.

### `SecpkgExtraOids`

Identifies that extra object identifiers (OIDs) are available.

### `SecpkgMaxInfo`

The end value for the enumeration. This value is not a valid parameter value.

### `SecpkgNego2Info`

Identifies the SPNego information for the security package.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This constant is not available.