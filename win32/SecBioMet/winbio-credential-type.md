# WINBIO\_CREDENTIAL\_TYPE enumeration

Defines flags that can be used to filter on the credential type. This enumeration is used by the [**WinBioSetCredential**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbiosetcredential), [**WinBioRemoveCredential**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioremovecredential), and [**WinBioGetCredentialState**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbiogetcredentialstate) functions.

## Constants

**WINBIO\_CREDENTIAL\_PASSWORD**

Filters password credentials.

**WINBIO\_CREDENTIAL\_ALL**

Filters all credentials.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Enumerations](https://learn.microsoft.com/windows/win32/secbiomet/client-application-enumerations)

[**WinBioGetCredentialState**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbiogetcredentialstate)

[**WinBioRemoveCredential**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioremovecredential)

[**WinBioSetCredential**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbiosetcredential)

