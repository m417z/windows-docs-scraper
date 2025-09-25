## Description

**NtPrivilegeCheck** is reserved for system use.

## Parameters

### `ClientToken` [in]

A handle to a token object representing a client attempting access. This handle must be obtained from a communication session layer, such as from an LPC Port or Local Named Pipe, to prevent possible security policy violations.

### `RequiredPrivileges` [in, out]

Pointer to a [**PRIVILEGE_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_privilege_set) structure. The **Privilege** member of this structure is an array of LUID_AND_ATTRIBUTES structures. Before calling **SePrivilegeCheck**, use the **Privilege** array to indicate the set of privileges to check. Set the **Control** member to PRIVILEGE_SET_ALL_NECESSARY if all of the privileges must be enabled; or set it to zero if it is sufficient that any one of the privileges be enabled.

### `Result` [out]

Receives a boolean flag indicating whether the client has all the specified privileges. A value of TRUE indicates the client has all the specified privileges; otherwise a value of FALSE is returned.

## Return value

**NtPrivilegeCheck** returns STATUS_SUCCESS on successful completion. Otherwise, it returns an error code, such as the following.

| Return code | Description |
| ----------- | ----------- |
| STATUS_PRIVILEGE_NOT_HELD | The caller does not have sufficient privilege to use this privileged system service. |

## Remarks

An access token contains a list of the privileges held by the account associated with the token. These privileges can be enabled or disabled; most are disabled by default. **NtPrivilegeCheck** checks only for enabled privileges. To get a list of all the enabled and disabled privileges held by an access token, call [**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken).

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**LUID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_luid_and_attributes)

[**PRIVILEGE_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_privilege_set)

[**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#security_subject_context)

[**SeAccessCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)

[**SeAppendPrivileges**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seappendprivileges)

[**SeFreePrivileges**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefreeprivileges)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**SeSinglePrivilegeCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-sesingleprivilegecheck)