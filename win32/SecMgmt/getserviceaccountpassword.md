# GetServiceAccountPassword function

Retrieves the service account password, available to [*security support providers*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSPs), such as Kerberos SSP.

## Parameters

*AccountName* \[in\]

Null-terminated account name of the Group Managed Service Account (gMSA) account. The user name can be one of the following forms:

- SAM account name of the gMSA.
- User name in a fully qualified domain name (FQDN), such as *DomainName*__\\__*UserName* or __www.__*domain*__.com\\__*name*. The user name must be a SAM name only. The domain name can be a DNS name or a NetBIOS name.
- Implicit user principal name (UPN) for the gMSA account, for example, *SomeName*__@__*Domain*__.com__ where, according to the definition of an implicit UPN, the *Domain*__.com__ is the actual domain DNS name.

*DomainName* \[in, optional\]

Optional null-terminated domain name. This is valid only if the *AccountName* parameter is a SAM account name. The domain name can only be a NetBIOS name or a fully qualified domain name (FQDN).

*CredFetch* \[in\]

A value of the [**CRED\_FETCH**](https://learn.microsoft.com/windows/win32/secmgmt/cred-fetch) enumeration that specifies how to retrieve the credential.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **CredFetchDefault** | The operating system first attempts to retrieve the password from the local cache if it is not time to fetch the password. If it is time to fetch the password, then the operating system contacts the domain controller, otherwise, return any cached passwords with a status value of success.<br> |
| **CredFetchDPAPI** | Returns the local DPAPI credential to the caller. SSPs generally would not require use of this value.<br> |
| **CredFetchForced** | Forces the operating system to attempt to read the password from the domain controller. During the password rollover time, the password may have changed at the domain controller and other member hosts, but the gMSA member host recognizes the password as still valid. This can happen due to clock skew issues between different domain controllers. When this value is specified, the operating system determines if there could be a possible password change due to clock skew and if so, retrieves the password. Otherwise, the cached credential is returned. If there is no cached credential, then the operating system attempts to get one from the domain controller.<br> |

*FileTimeExpiry* \[in, out, optional\]

On input, if this value is nonnull and is not a zero **FILETIME**, *FileTimeExpiry* contains the expiry time of the service account credentials as known to the caller. If the *FileTimeExpiry* parameter is the same as one of the current credentials, this call fails. On output, the *FileTimeExpiry* parameter contains the expiry time of the credential being returned.

*CurrentPassword* \[out\]

The current password of the gMSA.

*PreviousPassword* \[out\]

The previous password of the gMSA.

*FileTimeCurrPwdValidForOutbound* \[out, optional\]

Denotes the time after which the current password is valid for outbound requests. The caller should compare the current time with this value and use the current password returned only if the current time is greater than or equal to the value returned by this parameter. The use of this parameter is designed for callers that do not have retry in the outbound logic, for example, NTLM.

## Return value

If the function succeeds, the return value is STATUS\_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see [LSA Policy Function Return Values](https://learn.microsoft.com/windows/win32/secmgmt/management-return-values).

You can use the [**LsaNtStatusToWinError**](https://learn.microsoft.com/windows/desktop/api/Ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

When you have finished using the buffers returned in the *CurrentPassword* and *PreviousPassword* parameters, free them by calling the [**FreeLsaHeap**](https://learn.microsoft.com/windows/desktop/api/ntlsa/nc-ntlsa-lsa_free_lsa_heap) function.

## Remarks

The **GetServiceAccountPassword** function can be called in the following scenarios:

- From the logon functions of Security Support Providers (SSP), the SSP should detect that the SERVICE\_ACCOUNT\_PASSWORD is being used to log on to the entity and should check that the caller has TCB privilege or is a network service. Then the SSP should allow the log on process to proceed by getting the latest credential by calling the **GetServiceAccountPassword** function with the **CredFetchDefault** value in the [**CRED\_FETCH**](https://learn.microsoft.com/windows/win32/secmgmt/cred-fetch) enumeration.

- From SSPs in their [**InitializeSecurityContext**](https://learn.microsoft.com/windows/win32/SecAuthN/initializesecuritycontext--general) and [**AcceptSecurityContext**](https://learn.microsoft.com/windows/win32/SecAuthN/acceptsecuritycontext--general) calls. SSPs should detect that the SERVICE\_ACCOUNT\_PASSWORD is being used for these calls, and if the call is for nonprimary credentials, then the SSP should ensure that the caller has either TCB privilege or is a network service. Then the SSP should call the **GetServiceAccountPassword** function with the **CredFetchDefault** value in the [**CRED\_FETCH**](https://learn.microsoft.com/windows/win32/secmgmt/cred-fetch) enumeration and proceed with the call. If the **InitializeSecurityContext** and **AcceptSecurityContext** calls fail, then the SSP should use the *FileTimeExpiry* retrieved from the previous call to **GetServiceAccountPassword** and use it as input to calling **GetServiceAccountPassword** again using the **CredFetchForced** value in the **CRED\_FETCH** enumeration. If a new gMSA credential is available, the second call will succeed with new credentials, and the SSP should then retry with the new credentials.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Secpkg.h |

