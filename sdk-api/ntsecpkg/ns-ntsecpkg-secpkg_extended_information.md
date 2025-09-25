# SECPKG_EXTENDED_INFORMATION structure

## Description

The **SECPKG_EXTENDED_INFORMATION** structure is used to hold information about optional package capabilities.

This structure is used by the
[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) and
[SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn) functions.

## Members

### `Class`

A value from the
[SECPKG_EXTENDED_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/ntsecpkg/ne-ntsecpkg-secpkg_extended_information_class) enumeration which identifies the information in the structure.

### `Info`

Structure that contains the information.

### `Info.GssInfo`

A
[SECPKG_GSS_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_gss_info) structure that contains information used for GSS-compatible negotiations.

### `Info.ContextThunks`

A
[SECPKG_CONTEXT_THUNKS](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_context_thunks) structure that contains information about
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) calls to be executed in LSA mode.

### `Info.MutualAuthLevel`

A
[SECPKG_MUTUAL_AUTH_LEVEL](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_mutual_auth_level) structure that contains the authentication level used by a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

### `Info.WowClientDll`

A
[SECPKG_WOW_CLIENT_DLL](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_wow_client_dll) structure that contains the path to the WOW client's 32-bit version of the DLL used by a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). LSA operations are done by the 64-bit version. When the security context is handed back to the client, the 32-bit WOW-aware version is loaded and hands it any information from the 64-bit version.

### `Info.ExtraOids`

A
[SECPKG_EXTRA_OIDS](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_extra_oids) structure that contains the extra object identifiers (OIDs) used by a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

### `Info.Nego2Info`

A
[SECPKG_NEGO2_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_nego2_info) structure that contains the Nego2 information used by a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).