# WINBIO\_CREDENTIAL\_STATE enumeration

Defines values that specify whether a credential has been associated with the biometric data for an end user. This enumeration is used by the [**WinBioGetCredentialState**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbiogetcredentialstate) function.

## Constants

**WINBIO\_CREDENTIAL\_NOT\_SET**

A credential has been associated with the end user.

**WINBIO\_CREDENTIAL\_SET**

A credential has not been associated with the end user.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Enumerations](https://learn.microsoft.com/windows/win32/secbiomet/client-application-enumerations)

[**WinBioGetCredentialState**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbiogetcredentialstate)

