# LsaRemoveAccountRights function

## Description

The **LsaRemoveAccountRights** function removes one or more [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) from an account. You can specify the privileges to be removed, or you can set a flag to remove all privileges. When you remove all privileges, the function deletes the account. If you specify privileges not held by the account, the function ignores them.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The handle must have the POLICY_LOOKUP_NAMES access right. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `AccountSid` [in]

Pointer to the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the account from which the privileges are removed.

### `AllRights` [in]

If **TRUE**, the function removes all privileges and deletes the account. In this case, the function ignores the *UserRights* parameter. If **FALSE**, the function removes the privileges specified by the *UserRights* parameter.

### `UserRights` [in]

Pointer to an array of
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structures. Each structure contains the name of a privilege to be removed from the account. For a list of privilege names, see
[Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants).

### `CountOfRights` [in]

Specifies the number of elements in the *UserRights* array.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Value | Description |
| --- | --- |
| **STATUS_NO_SUCH_PRIVILEGE** | One of the privilege names is not valid. |
| **STATUS_INVALID_PARAMETER** | Indicates the *UserRights* parameter was **NULL** and the *AllRights* parameter was **FALSE**. |

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## See also

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaAddAccountRights](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaaddaccountrights)

[LsaEnumerateAccountRights](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumerateaccountrights)