# WINBIO\_IDENTITY structure

The **WINBIO\_IDENTITY** structure contains an identifying value associated with a biometric template.

## Members

**Type**

Specifies the format of the identity information contained in this structure. This can be one of the following values:

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------|
| **WINBIO\_ID\_TYPE\_NULL** | The template has no associated ID.<br> |
| **WINBIO\_ID\_TYPE\_WILDCARD** | The structure matches all template identities.<br> |
| **WINBIO\_ID\_TYPE\_GUID** | The structure contains a GUID associated with the template.<br> |
| **WINBIO\_ID\_TYPE\_SID** | The structure contains the account SID associated with the template.<br> |

**Value**

A union that can contain one of the following values:

**Null**

Contains 1 if the **Type** member is **WINBIO\_ID\_TYPE\_NULL**.

**Wildcard**

Contains 1 if the **Type** member is **WINBIO\_ID\_TYPE\_WILDCARD**.

**TemplateGuid**

Contains a 128-bit GUID value that identifies the template if the **Type** member is **WINBIO\_ID\_TYPE\_GUID**.

**AccountSid**

A structure that contains an account SID if the **Type** member is **WINBIO\_ID\_TYPE\_SID**.

**Size**

The number of characters in the SID.

**Data**

An array of unsigned characters that contain the SID. The current maximum size of the array is 68 characters.

## Remarks

This structure is used in the following functions:

- [**WinBioDeleteTemplate**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbiodeletetemplate)
- [**WinBioEnrollCommit**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioenrollcommit)
- [**WinBioEnumEnrollments**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioenumenrollments)
- [**WinBioGetCredentialState**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbiogetcredentialstate)
- [**WinBioIdentify**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioidentify)
- [**WinBioRemoveCredential**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioremovecredential)
- [**WinBioVerify**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioverify)
- [**WinBioVerifyWithCallback**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioverifywithcallback)

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Structures](https://learn.microsoft.com/windows/win32/secbiomet/client-application-structures)

