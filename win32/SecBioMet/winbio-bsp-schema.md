# WINBIO\_BSP\_SCHEMA structure

The **WINBIO\_BSP\_SCHEMA** structure describes the capabilities of a biometric service provider. This structure is used by the [**WinBioEnumServiceProviders**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioenumserviceproviders) function.

## Members

**BiometricFactor**

The type of biometric measurement used by this device. Currently this must be **WINBIO\_TYPE\_FINGERPRINT**.

**BspId**

A value that uniquely identifies this biometric service provider component.

**Description**

A **NULL**-terminated Unicode string that contains a description of the biometric service provider.

**Vendor**

A **NULL**-terminated Unicode string that contains the name of the vendor supplying the biometric service provider.

**Version**

A [**WINBIO\_VERSION**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-version) structure the contains the software version of the biometric service provider component.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Structures](https://learn.microsoft.com/windows/win32/secbiomet/client-application-structures)

[**WinBioEnumServiceProviders**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioenumserviceproviders)

