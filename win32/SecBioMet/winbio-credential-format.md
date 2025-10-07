# WINBIO\_CREDENTIAL\_FORMAT enumeration

Defines flags that can be used to specify the end-user credential format. This enumeration is used by the [**WinBioSetCredential**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbiosetcredential) function.

## Constants

**WINBIO\_PASSWORD\_GENERIC**

The password is in a generic format.

**WINBIO\_PASSWORD\_PACKED**

The password is in a compressed format.

**WINBIO\_PASSWORD\_PROTECTED**

The password credential was wrapped with [**CredProtect**](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credprotecta).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Enumerations](https://learn.microsoft.com/windows/win32/secbiomet/client-application-enumerations)

[**WinBioSetCredential**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbiosetcredential)

