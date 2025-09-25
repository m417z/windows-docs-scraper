# LsaAddAccountRights function

## Description

The **LsaAddAccountRights** function assigns one or more [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to an account. If the account does not exist, **LsaAddAccountRights** creates it.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The handle must have the POLICY_LOOKUP_NAMES access right. If the account identified by the *AccountSid* parameter does not exist, the handle must have the POLICY_CREATE_ACCOUNT access right. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `AccountSid` [in]

Pointer to the SID of the account to which the function assigns [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

### `UserRights` [in]

Pointer to an array of
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structures. Each structure contains the name of a privilege to add to the account. For a list of privilege names, see
[Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants).

### `CountOfRights` [in]

Specifies the number of elements in the *UserRights* array.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be the following value or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_NO_SUCH_PRIVILEGE** | One of the privilege names is not valid. |

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## Remarks

If you specify privileges already granted to the account, they are ignored.

For an example that demonstrates calling this function, see
[Managing Account Permissions](https://learn.microsoft.com/windows/desktop/SecMgmt/managing-account-permissions).

## See also

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaEnumerateAccountRights](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumerateaccountrights)

[LsaRemoveAccountRights](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaremoveaccountrights)