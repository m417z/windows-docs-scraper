# LsaEnumerateAccountRights function

## Description

The **LsaEnumerateAccountRights** function enumerates the [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) assigned to an account.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The handle must have the POLICY_LOOKUP_NAMES access right. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `AccountSid` [in]

Pointer to the SID of the account for which to enumerate privileges.

### `UserRights` [out]

Receives a pointer to an array of
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structures. Each structure contains the name of a privilege held by the account. For a list of privilege names, see
[Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants)

When you no longer need the information, pass the returned pointer to
[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory).

### `CountOfRights` [out]

Pointer to a variable that receives the number of privileges in the *UserRights* array.

## Return value

If at least one account right is found, the function succeeds and returns STATUS_SUCCESS.

If no account rights are found or if the function fails for any other reason, the function returns an NTSTATUS code such as FILE_NOT_FOUND. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values). Use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## See also

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaAddAccountRights](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaaddaccountrights)

[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory)

[LsaRemoveAccountRights](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaremoveaccountrights)