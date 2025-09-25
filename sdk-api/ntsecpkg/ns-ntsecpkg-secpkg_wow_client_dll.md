# SECPKG_WOW_CLIENT_DLL structure

## Description

The **SECPKG_WOW_CLIENT_DLL** structure contains the path to the WOW-aware 32-bit DLL.

This structure is used by the
[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) and
[SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn) functions.

## Members

### `WowClientDllPath`

A [SECURITY_STRING](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-security_string) that contain the path to the WOW-aware client 32-bit library.