# SeCaptureSubjectContext function (wdm.h)

## Description

The **SeCaptureSubjectContext** routine captures the security context of the calling thread for access validation and auditing.

## Parameters

### `SubjectContext` [out]

Pointer to a caller-allocated [SECURITY_SUBJECT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure.

## Remarks

The **SeCaptureSubjectContext** routine returns a pointer to a [SECURITY_SUBJECT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure, which contains references to access tokens. The contents of that structure can change. The [SeLockSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-selocksubjectcontext) routine locks the primary access token and any impersonation tokens associated with the structure.

When using routines that query token information, such as [SeQueryAuthenticationIdToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken), [SeQuerySubjectContextToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken), [SeQueryInformationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken), and [SePrivilegeCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck), more than once in the same security context, lock the subject context with [SeLockSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-selocksubjectcontext) to obtain consistent results.

File systems must call **SeCaptureSubjectContext** before performing access validation or generating audit messages. This is necessary to provide a consistent security context to routines such as [SeQueryAuthenticationIdToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken), [SeQuerySubjectContextToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken), and [SePrivilegeCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck). After these operations have been performed, the captured context should be released as soon as possible by calling [SeReleaseSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sereleasesubjectcontext).

For more information about security and access control, see the documentation on these topics in the Microsoft Windows SDK.

## See also

[SECURITY_SUBJECT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[SeLockSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-selocksubjectcontext)

[SePrivilegeCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck)

[SeQueryAuthenticationIdToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken)

[SeQuerySubjectContextToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken)

[SeReleaseSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sereleasesubjectcontext)

[SeUnlockSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seunlocksubjectcontext)