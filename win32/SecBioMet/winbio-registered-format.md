# WINBIO\_REGISTERED\_FORMAT structure

The **WINBIO\_REGISTERED\_FORMAT** structure specifies a registered data format as an owner/format pair.

## Members

**Owner**

An IBIA (International Biometric Industry Association) assigned owner value.

**Type**

An owner assigned format.

## Remarks

Because Windows currently supports only fingerprint readers, the following values should be used in the **WINBIO\_REGISTERED\_FORMAT** structure.

| Constant | Meaning |
|---------------------------------------------|-----------------------------------------------------------------------------------------------------------------------|
| WINBIO\_ANSI\_381\_FORMAT\_OWNER<br> | InterNational Committee for Information Technology Standards (INCITS) technical committee M1 (biometrics).<br> |
| WINBIO\_ANSI\_381\_FORMAT\_TYPE<br> | ANSI INCITS 381 finger image based data interchange format.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Structures](https://learn.microsoft.com/windows/win32/secbiomet/client-application-structures)

[**WINBIO\_ANSI\_381\_FORMAT Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-ansi-381-format-constants)

[**WINBIO\_BDB\_ANSI\_381\_HEADER**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bdb-ansi-381-header)

[**WINBIO\_BIR\_HEADER**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-header)

