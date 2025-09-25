# NtSetInformationToken function

## Description

The **NtSetInformationToken** routine modifies information in a specified token. The calling process must have appropriate access rights to set the information.

## Parameters

### `TokenHandle` [in]

Handle for an access token in which information is to be modified.

### `TokenInformationClass` [in]

A value from the [**TOKEN_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class) enumerated type identifying the type of information to be modified. The possible values for this parameter are listed in the **TokenInformationClass** Value column of the table shown in the description of the **TokenInformation** parameter.

### `TokenInformation` [in]

Pointer to a caller-supplied buffer containing the information to be modified in the token. The structure of the information in this buffer depends upon the value of **TokenInformationClass**, as shown in the following table. All structures must be aligned on a 32-bit boundary.

| TokenInformationClass value | Effect on TokenInformation buffer |
| --------------------------- | --------------------------------- |
| **TokenDefaultDacl** | The buffer contains a [**TOKEN_DEFAULT_DACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_default_dacl) structure specifying the default [**DACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl) for newly created objects. TOKEN_ADJUST_DEFAULT access is required to set this information. The buffer contents are not validated for structural correctness or consistency. |
| **TokenGroups** | Not a valid information class. This information is read-only. |
| **TokenOwner** | The buffer contains a [**TOKEN_OWNER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_owner) structure specifying the default owner [**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid) for newly created objects. TOKEN_ADJUST_DEFAULT access is required to set this information. The owner values that may be specified are restricted to the user and group IDs with an attribute indicating they can be assigned as the owner of objects. |
| **TokenPrimaryGroup** | The buffer contains a [**TOKEN_PRIMARY_GROUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_primary_group) structure specifying the default primary group **SID** for newly created objects. TOKEN_ADJUST_DEFAULT access is required to set this information. Must be one of the group IDs already in the token. |
| **TokenPrivileges** | Not a valid information class. This information is read-only. |
| **TokenSource** | Not a valid information class. This information is read-only. |
| **TokenStatistics** | Not a valid information class. This information is read-only. |
| **TokenUser** | Not a valid information class. This information is read-only. |

### `TokenInformationLength` [in]

Size, in bytes, of the structure passed in the **TokenInformation** buffer. Must be greater than or equal to the minimum value given in the following table.

| TokenInformationClass value | Minimum TokenInformationLength |
| --------------------------- | ------------------------------ |
| **TokenDefaultDacl** | **sizeof**(**TOKEN_DEFAULT_DACL**) |
| **TokenOwner** | **sizeof**(**TOKEN_OWNER**) |
| **TokenPrimaryGroup** | **sizeof**(**TOKEN_PRIMARY_GROUP**) |

## Return value

**NtSetInformationToken** returns STATUS_SUCCESS or an appropriate error status. Possible error status codes include the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED | **TokenHandle** did not have the required access. |
| STATUS_ALLOTTED_SPACE_EXCEEDED | The space allotted for storage of the default discretionary access control and the primary group ID is not large enough to accept the new value of one of these fields. |
| STATUS_INFO_LENGTH_MISMATCH | The value of **TokenInformationLength** was less than the required minimum. |
| STATUS_INSUFFICIENT_RESOURCES | The specified default owner's security information could not be captured. |
| STATUS_INVALID_HANDLE | **TokenHandle** was not a valid handle. |
| STATUS_INVALID_INFO_CLASS | **TokenInformationClass** was not a valid token information class. |
| STATUS_INVALID_OWNER | The caller cannot set the specified ID to be an owner (or default owner) of an object. |
| STATUS_INVALID_PRIMARY_GROUP | The caller cannot set the specified ID to be the primary group of an object. |
| STATUS_INVALID_SID | The specified default owner's security information was not valid. |
| STATUS_OBJECT_TYPE_MISMATCH | **TokenHandle** was not a token handle. |

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

> [!NOTE]
> If the call to the **NtSetInformationToken** function occurs in kernel mode, you should use the name "[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)" instead of "**NtSetInformationToken**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**NtQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationtoken)

[**PsDereferenceImpersonationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceimpersonationtoken)

[**PsDereferencePrimaryToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceprimarytoken)

[**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SeQueryAuthenticationIdToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken)

[**SeQuerySubjectContextToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken)

[**SeTokenIsAdmin**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisadmin)

[**SeTokenIsRestricted**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisrestricted)

[**TOKEN_DEFAULT_DACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_default_dacl)

[**TOKEN_GROUPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups)

[**TOKEN_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class)

[**TOKEN_OWNER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_owner)

[**TOKEN_PRIMARY_GROUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_primary_group)

[**TOKEN_PRIVILEGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_privileges)

[**TOKEN_SOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_source)

[**TOKEN_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_statistics)

[**TOKEN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_type)

[**TOKEN_USER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_user)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)