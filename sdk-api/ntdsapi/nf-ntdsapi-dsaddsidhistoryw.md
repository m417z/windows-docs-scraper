# DsAddSidHistoryW function

## Description

The **DsAddSidHistory** function retrieves the primary account security identifier (SID) of a security principal from one domain and adds it to the **sIDHistory** attribute of a security principal in another domain in a different forest. When the source domain is in Windows 2000 native mode, this function also retrieves the **sIDHistory** values of the source principal and adds them to the destination principal **sIDHistory**.

The **DsAddSidHistory** function performs a security-sensitive function by adding the primary account SID of an existing security principal to the **sIDHistory** of a principal in a domain in a different forest, effectively granting to the latter access to all resources accessible to the former. For more information about the use and security implications of this function, see [Using DsAddSidHistory](https://learn.microsoft.com/windows/desktop/AD/using-dsaddsidhistory).

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `Flags` [in]

Reserved for future use. Set to **NULL**.

### `SrcDomain` [in]

Pointer to a null-terminated string that specifies the name of the domain to query for the SID of *SrcPrincipal*.

If the source domain runs on Windows Server operating systems, *SrcDomain* can be either a domain name system (DNS) name, for example, fabrikam.com, or a flat NetBIOS, for example, Fabrikam, name. DNS names should be used when possible.

### `SrcPrincipal` [in]

Pointer to a null-terminated string that specifies the name of a security principal, user or group, in the source domain. This name is a domain-relative Security Account Manager (SAM) name, for example: evacorets.

### `SrcDomainController` [in]

Pointer to a null-terminated string that specifies the name of the primary domain controller (PDC) Emulator in the source domain to use for secure retrieval of the source principal SID and audit generation.

If this parameter is **NULL**, [DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) will select the primary domain controller.

*SrcDomainController* can be either a DNS name or a flat NetBIOS name. DNS names should be used when possible.

### `SrcDomainCreds` [in]

Contains an identity handle that represents the identity and credentials of a user with administrative rights in the source domain. To obtain this handle, call [DsMakePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmakepasswordcredentialsa). This user must be a member of either the Administrators or the Domain Administrators group. If this call is made from a remote computer to the destination DC, then both the remote computer and the destination DC must support 128-bit encryption to privacy-protect the credentials. If 128-bit encryption is unavailable and *SrcDomainCreds* are provided, then the call must be made on the destination DC.

If this parameter is **NULL**, the credentials of the caller are used for access to the source domain.

### `DstDomain` [in]

Pointer to a null-terminated string that specifies the name of the destination domain in which *DstPrincipal* resides. This name can either be a DNS name, for example, fabrikam.com, or a NetBIOS name, for example, Fabrikam. The destination domain must run Windows 2000 native mode.

### `DstPrincipal` [in]

Pointer to a null-terminated string that specifies the name of a security principal, user or group, in the destination domain. This domain-relative SAM name identifies the principal whose **sIDHistory** attribute is updated with the SID of the *SrcPrincipal*.

## Return value

Returns a Win32 error codes including the following.

## See also

[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsMakePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmakepasswordcredentialsa)

[Using DsAddSidHistory](https://learn.microsoft.com/windows/desktop/AD/using-dsaddsidhistory)

[ldap_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind_s)

**ldap_open**

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsAddSidHistory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).