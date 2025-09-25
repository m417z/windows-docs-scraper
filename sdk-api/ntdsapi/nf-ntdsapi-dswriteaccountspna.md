# DsWriteAccountSpnA function

## Description

The **DsWriteAccountSpn** function writes an array of service principal names (SPNs) to the **servicePrincipalName** attribute of a specified user or computer account object in Active Directory Domain Services. The function can either register or unregister the SPNs.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `Operation` [in]

Contains one of the [DS_SPN_WRITE_OP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_spn_write_op) values that specifies the operation that **DsWriteAccountSpn** will perform.

### `pszAccount` [in]

Pointer to a constant null-terminated string that specifies the distinguished name of a user or computer object in Active Directory Domain Services. The caller must have write access to the **servicePrincipalName** property of this object.

### `cSpn` [in]

Specifies the number of SPNs in *rpszSpn*. If this value is zero, and *Operation* contains **DS_SPN_REPLACE_SPN_OP**, the function removes all values from the **servicePrincipalName** attribute of the specified account.

### `rpszSpn` [in]

Pointer to an array of constant null-terminated strings that specify the SPNs to be added to or removed from the account identified by the *pszAccount* parameter. The [DsGetSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetspna) function is used to compose SPNs for a service.

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32, RPC or directory service error if unsuccessful.

## Remarks

The **DsWriteAccountSpn** function registers the SPNs for one or more instances of a service. SPNs are used by clients, in conjunction with a trusted authentication service, to authenticate the service. To protect against security attacks where an application or service fraudulently registers an SPN that identifies some other service, the default DACL on user and computer accounts allows only domain administrators to register SPNs in most cases.

One exception to this rule is that a service running under the LocalSystem account can call **DsWriteAccountSpn** to register a simple SPN of the form "ServiceClass/Host:Port" if the host specified in the SPN is the DNS or NetBIOS name of the computer on which the service is running.

Another exception is that the default DACL on computer accounts allows callers to register SPNs on themselves, subject to certain constraints. For example, a computer account can have SPNs relative to its computername, of the form "host/<computername>". Because the computername is contained in the SPN, the SPN is allowable.

None of the rules above apply if the DSA is configured to allow any SPN to be written. This reduces security, however, so it is not recommended.

SPNs passed to **DsWriteAccountSpn** are actually added to the **Service-Principal-Name** attribute of the computer object in *pszAccount*. This call is made using RPC to the domain controller where the account object is stored so it can securely enforce policy on what SPNs are allowed on the account. Using LDAP to write directly to the SPN property is not allowed; all writes must come through this RPC call. Reads using LDAP are allowed.

Permissions required to set SPNs

To write an arbitrary SPN on an account, the writer requires the "Write ServicePrincipalName" right, which is not granted by default to the person who created the account. That person has the 'Write validated SPN" right(present only on machine accounts).

Below is a summary of rights per user on machine accounts:

| User Type | Rights |
| --- | --- |
| Person creating the Account | Write validated SPN |
| Account Operators | Write SPN and Write Validated SPN |
| Authenticated Users | None |
| (self) | Write Validated SPN |

On user accounts there is no "Validated SPN" property or "Write SPN" right. Rather, the "Write public information" property set grants the ability to create arbitrary SPNs.

> [!NOTE]
> The ntdsapi.h header defines DsWriteAccountSpn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DS_SPN_WRITE_OP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_spn_write_op)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsGetSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetspna)