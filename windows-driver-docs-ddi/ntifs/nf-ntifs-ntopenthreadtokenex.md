# NtOpenThreadTokenEx function

## Description

The **NtOpenThreadTokenEx** routine opens the access token associated with a thread.

## Parameters

### `ThreadHandle` [in]

Handle to the thread whose access token is to be opened. The handle must have THREAD_QUERY_INFORMATION access. Use the **NtCurrentThread** macro to specify the current thread.

### `DesiredAccess` [in]

[**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) structure specifying the requested types of access to the access token. These requested access types are compared with the token's discretionary access-control list ([**DACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)) to determine which access rights are granted or denied.

### `OpenAsSelf` [in]

Boolean value specifying whether the access check is to be made against the security context of the thread calling **NtOpenThreadTokenEx** or against the security context of the process for the calling thread.

If this parameter is **FALSE**, the access check is performed using the security context for the calling thread. If the thread is impersonating a client, this security context can be that of a client process. If this parameter is **TRUE**, the access check is made using the security context of the process for the calling thread.

### `HandleAttributes` [in]

Attributes for the created handle. Only OBJ_KERNEL_HANDLE is currently supported. If the caller is not running in the system process context, it must specify OBJ_KERNEL_HANDLE for this parameter.

### `TokenHandle` [out]

Pointer to a caller-allocated variable that receives a handle to the newly opened access token.

## Return value

**NtOpenThreadTokenEx** returns STATUS_SUCCESS or an appropriate error status. Possible error status codes include the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED |
**ThreadHandle** did not have THREAD_QUERY_INFORMATION access. |
| STATUS_CANT_OPEN_ANONYMOUS | The client requested the SecurityAnonymous impersonation level. However, an anonymous token cannot be opened. For more information, see [**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level). |
| STATUS_INVALID_HANDLE | **ThreadHandle** was not a valid handle. |
| STATUS_INVALID_PARAMETER | The specified **HandleAttributes** did not include OBJ_KERNEL_HANDLE. |
| STATUS_NO_TOKEN | An attempt has been made to open a token associated with a thread that is not currently impersonating a client. |
| STATUS_OBJECT_TYPE_MISMATCH | **ThreadHandle** was not a thread handle. |

## Remarks

**NtOpenThreadTokenEx** opens the access token associated with a thread and returns a handle for that token.

The **OpenAsSelf** parameter allows a server process to open the access token for a client process when the client process has specified the SecurityIdentification impersonation level for the **SECURITY_IMPERSONATION_LEVEL** enumerated type. Without this parameter, the calling process is not able to open the client's access token using the client's security context because it is impossible to open executive-level objects using the SecurityIdentification impersonation level.

Any handle obtained by calling **NtOpenThreadTokenEx** must eventually be released by calling **NtClose**.

Driver routines that run in a process context other than that of the system process must set the OBJ_KERNEL_HANDLE attribute for the **HandleAttributes** parameter of **NtOpenThreadTokenEx**. This restricts the use of the handle returned by **NtOpenThreadTokenEx** to processes running in kernel mode. Otherwise, the handle can be accessed by the process in whose context the driver is running.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[**PsDereferencePrimaryToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceprimarytoken)

[**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)

[**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[**ZwOpenProcessTokenEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwopenprocesstokenex)