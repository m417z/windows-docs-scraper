# LsaEnumerateAccountsWithUserRight function

## Description

The **LsaEnumerateAccountsWithUserRight** function returns the accounts in the database of a [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object that hold a specified [privilege](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The accounts returned by this function hold the specified privilege directly through the user account, not as part of membership to a group.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The handle must have POLICY_LOOKUP_NAMES and POLICY_VIEW_LOCAL_INFORMATION user rights. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `UserRight` [in]

Pointer to an
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that specifies the name of a privilege. For a list of privileges, see
[Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants) and
Account Rights Constants.

If this parameter is **NULL**, the function enumerates all accounts in the LSA database of the system associated with the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object.

### `Buffer` [out]

Pointer to a variable that receives a pointer to an array of
[LSA_ENUMERATION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_enumeration_information) structures. The **Sid** member of each structure is a pointer to the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of an account that holds the specified privilege.

When you no longer need the information, free the memory by passing the returned pointer to
the [LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory) function.

### `CountReturned` [out]

Pointer to a variable that receives the number of entries returned in the *EnumerationBuffer* parameter.

## Return value

If the function succeeds, the function returns STATUS_SUCCESS.

If the function fails, it returns an **NTSTATUS** code, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Value | Description |
| --- | --- |
| **STATUS_NO_SUCH_PRIVILEGE** | The privilege string specified was not a valid privilege. |
| **STATUS_NO_MORE_ENTRIES** | There were no accounts with the specified privilege. |

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the **NTSTATUS** code to a Windows error code.

## See also

[LSA_ENUMERATION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_enumeration_information)

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory)

[LsaOpenPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaopenpolicy)