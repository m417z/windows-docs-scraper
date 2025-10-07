# WINBIO\_BIR structure

The **WINBIO\_BIR** structure represents a biometric information record (BIR). The information record contains header, data, and signature blocks.

## Members

**HeaderBlock**

A [**WINBIO\_BIR\_DATA**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-data) structure that contains the size, in bytes, and offset of the BIR header. The header contains information that describes the contents of the information record.

**StandardDataBlock**

A [**WINBIO\_BIR\_DATA**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-data) structure that contains the size, in bytes, and offset of processed or unprocessed biometric information created by the Windows Biometric Framework (WBF).

**VendorDataBlock**

A [**WINBIO\_BIR\_DATA**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-data) structure that contains the size, in bytes, and offset of processed or unprocessed biometric information provided by vendor sensors and software.

**SignatureBlock**

An optional [**WINBIO\_BIR\_DATA**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-data) structure that contains the size, in bytes, and offset of the digital signature message authentication code (MAC) that can be used to verify the integrity of the BIR. If present, the signature or MAC must cover the header and data blocks.

## Remarks

The use of offsets rather than pointers allows for easy serialization of the BIR and for less complicated translation between 32 and 64-bit environments or between user and kernel mode.

The BIR is compatible with the Common Biometric Exchange Format Framework (CBEFF) defined by NIST 6529-A.

If this structure contains a *StandardDataBlock* value, the *Type* parameter of the header specified by the *HeaderBlock* parameter must be set to **WINBIO\_ANSI\_381\_FORMAT\_TYPE**. This is the only standard data format supported by the current version of the Windows Biometric Framework.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Structures](https://learn.microsoft.com/windows/win32/secbiomet/client-application-structures)

[**WINBIO\_BIR\_DATA**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-data)

[**WINBIO\_BIR\_HEADER**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-header)

