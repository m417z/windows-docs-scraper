# SeImpersonateClientEx function

## Description

The **SeImpersonateClientEx** routine causes a thread to impersonate a user.

## Parameters

### `ClientContext` [in]

Pointer to the user's security client context.

### `ServerThread` [in, optional]

Pointer to the thread that is to impersonate the user. If not specified, the calling thread is used.

## Return value

**SeImpersonateClientEx** returns an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The impersonation attempt succeeded. |
| **STATUS_ACCESS_DENIED** | The thread specified in *ServerThread* parameter did not have sufficient access rights to impersonate the user whose security client context is specified in the *ClientContext* parameter. |
| **STATUS_NO_MEMORY** | **SeImpersonateClientEx** encountered a pool allocation failure when allocating memory for the impersonation information structure. |

## Remarks

**SeImpersonateClientEx** is used to cause a thread to impersonate a user. The client security context in *ClientContext* is assumed to be up to date.

It is extremely unsafe to raise the privilege state of an untrusted user thread (take a user's thread and impersonate LocalSystem, for example). If an untrusted user thread had its privilege raised, the user could grab the thread token after it has been elevated and subvert the security of the entire system.

In cases where a higher privilege state is required, the task should be dispatched to a work queue where the task can be safely handled by system worker thread. This way no impersonation is necessary.

To end the impersonation of the user, call the [SeStopImpersonatingClient](https://learn.microsoft.com/windows-hardware/drivers/ifs/sestopimpersonatingclient) routine.

The [PsImpersonateClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psimpersonateclient) routine can be used to cause a server thread to impersonate a client.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[PsImpersonateClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psimpersonateclient)

[SeCreateClientSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secreateclientsecurity)

[SeCreateClientSecurityFromSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secreateclientsecurityfromsubjectcontext)

[SeStopImpersonatingClient](https://learn.microsoft.com/windows-hardware/drivers/ifs/sestopimpersonatingclient)