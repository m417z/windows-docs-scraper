# PST\_AUTHENTICODEDATA structure

\[Protected Storage (Pstore) is available for use in Windows Server 2003 and Windows XP. It is only available for read-only operations in Windows Server 2008 and Windows Vista, but may be unavailable in subsequent versions. Pstore uses an older implementation of data protection. Developers are strongly encouraged to take advantage of the stronger data protection provided by the [**CryptProtectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptprotectdata) and [**CryptUnprotectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptunprotectdata) functions.\]

Defines data to be used in Microsoft Authenticode verification of item data.

## Members

**cbSize**

The size of this structure.

**dwModifiers**

A value that identifies the modifier that one of a chain of callers must verify.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **PST\_AC\_SINGLE\_CALLER**

0 | Only a single level in the call chain to PStore. The caller passes the verification check. The specified image is the immediate caller, and is an application (.exe).\ | | **PST\_AC\_TOP\_LEVEL\_CALLER**

1 | The top-level caller must pass the check, but there may be intermediate DLLs. The specified image is not necessarily the immediate caller, and is an application (.exe).\ | | **PST\_AC\_IMMEDIATE\_CALLER**

2 | The immediate caller must pass the check, but need not be the top-level process. The specified image is the immediate caller, and the image can be an application (.exe) or a DLL.\ |

**szRootCA**

A pointer to a wide character string that represents the root certification authority (CA) for the certificate; use **NULL** to use any available CA.

**szIssuer**

A pointer to a wide character string that represents the CA that issued the certificate; use **NULL** to use any available CA.

**szPublisher**

A pointer to a wide character string that represents the software publisher; use **NULL** to use any available CA.

**szProgramName**

A pointer to a wide character string that represents the program name; use **NULL** to use any available CA.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Pstore.h |

