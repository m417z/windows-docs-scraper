# JOBOBJECT_SECURITY_LIMIT_INFORMATION structure

## Description

[JOBOBJECT_SECURITY_LIMIT_INFORMATION is available for use in the operating systems specified in the Requirements section. Support for this structure was removed starting with Windows Vista. For information, see Remarks.]

Contains the security limitations for a job object.

## Members

### `SecurityLimitFlags`

The security limitations for the job. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_OBJECT_SECURITY_FILTER_TOKENS**<br><br>0x00000008 | Applies a filter to the token when a process impersonates a client. Requires at least one of the following members to be set: **SidsToDisable**, **PrivilegesToDelete**, or **RestrictedSids**. |
| **JOB_OBJECT_SECURITY_NO_ADMIN**<br><br>0x00000001 | Prevents any process in the job from using a token that specifies the local administrators group. |
| **JOB_OBJECT_SECURITY_ONLY_TOKEN**<br><br>0x00000004 | Forces processes in the job to run under a specific token. Requires a token handle in the **JobToken** member. |
| **JOB_OBJECT_SECURITY_RESTRICTED_TOKEN**<br><br>0x00000002 | Prevents any process in the job from using a token that was not created with the [CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken) function. |

### `JobToken`

A handle to the primary token that represents a user. The handle must have TOKEN_ASSIGN_PRIMARY access.

If the token was created with
[CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken), all processes in the job are limited to that token or a further restricted token. Otherwise, the caller must have the SE_ASSIGNPRIMARYTOKEN_NAME privilege.

### `SidsToDisable`

A pointer to a
[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that specifies the SIDs to disable for access checking, if **SecurityLimitFlags** is JOB_OBJECT_SECURITY_FILTER_TOKENS.

This member can be NULL if you do not want to disable any SIDs.

### `PrivilegesToDelete`

A pointer to a
[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges) structure that specifies the privileges to delete from the token, if **SecurityLimitFlags** is JOB_OBJECT_SECURITY_FILTER_TOKENS.

This member can be NULL if you do not want to delete any privileges.

### `RestrictedSids`

A pointer to a
[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that specifies the deny-only SIDs that will be added to the access token, if **SecurityLimitFlags** is JOB_OBJECT_SECURITY_FILTER_TOKENS.

This member can be NULL if you do not want to specify any deny-only SIDs.

## Remarks

After security limitations are placed on processes in a job, they cannot be revoked.

Starting with Windows Vista, you must set security limitations individually for each process associated with a job object, rather than setting them for the job object by using [SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject). For information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

## See also

[CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)