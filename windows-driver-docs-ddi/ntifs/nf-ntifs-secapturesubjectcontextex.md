## Description

**SeCaptureSubjectContextEx** takes a snapshot of the calling thread's security context for access validation and auditing.

## Parameters

### `Thread`

[in] The thread from which to capture the thread token. This parameter is optional. When it's NULL, **SeCaptureSubjectContextEx** doesn't capture an impersonation token.

### `Process`

 [in] Pointer to the [ID of the process](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) from which to capture the primary token.

### `SubjectContext`

[out] Pointer to an opaque caller-allocated [**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#security_subject_context) structure. **SeCaptureSubjectContextEx** will write the snapshot of the calling thread's security profile, which contains references to access tokens, in this structure. *Drivers must not modify or try to directly access any members of this structure to make security decisions. Instead, to avoid security issues in authorization, pass this opaque structure in calls to [**SeAccessCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck) or [**SePrivilegeCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck).*

## Remarks

 You must call **SeCaptureSubjectContextEx** before performing services such as access validation or generating audit messages. This is necessary to provide a consistent security context to routines such as the following:

* [**SeQueryAuthenticationIdToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken)
* [**SeQuerySubjectContextToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken)
* [**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)
* [**SePrivilegeCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck)

After access validation, privilege checking, and audit generation services have been performed, release the captured context as soon as possible by calling [**SeReleaseSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sereleasesubjectcontext).

 **SeCaptureSubjectContextEx** locks tokens as necessary while taking the snapshot of the calling thread's security context.

On return, references to access tokens are contained in the structure that **SubjectContext** points to. The contents of that structure can change. To prevent this, call [**SeLockSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-selocksubjectcontext) to lock the primary access token and any impersonation tokens associated with the structure. For example, when using routines that query token information more than once in the same security context (such as the ones previously listed), lock the subject context with **SeLockSubjectContext** to obtain consistent results.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#security_subject_context)

[**SeLockSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-selocksubjectcontext)

[**SePrivilegeCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck)

[**SeQueryAuthenticationIdToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**SeQuerySubjectContextToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken)

[**SeReleaseSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sereleasesubjectcontext)

[**SeUnlockSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seunlocksubjectcontext)