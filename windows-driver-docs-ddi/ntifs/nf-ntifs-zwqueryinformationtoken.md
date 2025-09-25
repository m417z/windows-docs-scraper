# ZwQueryInformationToken function

## Description

The **ZwQueryInformationToken** routine retrieves a specified type of information about an access token. The calling process must have appropriate access rights to obtain the information.

## Parameters

### `TokenHandle` [in]

Handle for an access token from which information is to be retrieved. If **TokenInformationClass** is set to **TokenSource**, the handle must have TOKEN_QUERY_SOURCE access. For all other **TokenInformationClass** values, the handle must have TOKEN_QUERY access. For more information about access rights for access-token objects, see the Security section of the Windows SDK documentation.

### `TokenInformationClass` [in]

A value from the [**TOKEN_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class) enumerated type identifying the type of information to be retrieved. The possible values for this parameter are listed in the **TokenInformationClass** Value column of the table shown in the description of the **TokenInformation** parameter.

### `TokenInformation` [out]

Pointer to a caller-allocated buffer that receives the requested information about the token. The structure put into this buffer depends upon the value of **TokenInformationClass**, as shown in the following table. All structures must be aligned on a 32-bit boundary.

| TokenInformationClass value | Effect on TokenInformation buffer |
| --------------------------- | --------------------------------- |
| **TokenDefaultDacl** | The buffer receives a [**TOKEN_DEFAULT_DACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_default_dacl) structure containing the default [**DACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl) for newly created objects. |
| **TokenGroups** | The buffer receives a [**TOKEN_GROUPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups) structure containing the group accounts associated with the token. |
| **TokenImpersonationLevel** | The buffer receives a [**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level) value indicating the impersonation level of the token. If the access token is not an impersonation token, the call to **ZwQueryInformationToken** fails. |
| **TokenOwner** | The buffer receives a [**TOKEN_OWNER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_owner) structure containing the default owner [**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid) for newly created objects. |
| **TokenPrimaryGroup** | The buffer receives a [**TOKEN_PRIMARY_GROUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_primary_group) structure containing the default primary group SID for newly created objects. |
| **TokenPrivileges** | The buffer receives a [**TOKEN_PRIVILEGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_privileges) structure containing the token's privileges. |
| **TokenSessionId** | The buffer receives a 32-bit value specifying the Terminal Services session identifier associated with the token. If the token is associated with the Terminal Server console session, the session identifier is zero. A nonzero session identifier indicates a Terminal Services client session. In a non-Terminal Services environment, the session identifier is zero. |
| **TokenSource** | The buffer receives a [**TOKEN_SOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_source) structure containing the source of the token. TOKEN_QUERY_SOURCE access is needed to retrieve this information. |
| **TokenStatistics** | The buffer receives a [**TOKEN_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_statistics) structure containing various token statistics. |
| **TokenType** | The buffer receives a [**TOKEN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_type) value indicating whether the token is a primary or impersonation token. |
| **TokenUser** | The buffer receives a [**TOKEN_USER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_user) structure containing the token's user account. |

### `TokenInformationLength` [in]

Length, in bytes, of the caller-allocated **TokenInformation** buffer.

### `ReturnLength` [out]

Pointer to a caller-allocated variable that receives the actual length, in bytes, of the information returned in the **TokenInformation** buffer. If either of the following conditions is true, no data is returned in the **TokenInformation** buffer:

* The size of the requested token information structure is greater than **TokenInformationLength**. In this case, **ReturnLength** receives the actual number of bytes needed to store the requested information.

* The value of **TokenInformationClass** is **TokenDefaultDacl**, and there is no default DACL established for the token. In this case, **ReturnLength** receives zero.

## Return value

**ZwQueryInformationToken** returns STATUS_SUCCESS or an appropriate error status. Possible error status codes include the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED | **TokenHandle** did not have the required access. |
| STATUS_BUFFER_TOO_SMALL | The size of the requested token information structure is greater than **TokenInformationLength**. The number of bytes required is returned in **ReturnLength**. |
| STATUS_INVALID_HANDLE | **TokenHandle** was not a valid handle. |
| STATUS_INVALID_INFO_CLASS | **TokenInformationClass** was not a valid token information class. |
| STATUS_OBJECT_TYPE_MISMATCH | **TokenHandle** was not a token handle. |

## Remarks

The **ZwQueryInformationToken** routine can be used by a file system or file system filter driver to determine the [**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid) of the caller that initiated the request during [**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) processing. If **TokenUser** is specified for the **TokenInformationClass** parameter passed to **ZwQueryInformationToken**, a [**TOKEN_USER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_user) structure is returned in the buffer pointed to by the **TokenInformation** parameter. This returned buffer contains an [**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes) structure with the user **SID**.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

> [!NOTE]
> If the call to the **ZwQueryInformationToken** function occurs in user mode, you should use the name "**NtQueryInformationToken**" instead of "**ZwQueryInformationToken**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

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

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)