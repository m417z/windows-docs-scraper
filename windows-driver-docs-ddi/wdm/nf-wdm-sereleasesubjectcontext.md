# SeReleaseSubjectContext function (wdm.h)

## Description

The **SeReleaseSubjectContext** routine releases a subject security context captured by an earlier call to **SeCaptureSubjectContext**.

## Parameters

### `SubjectContext` [in, out]

Pointer to the captured security context.

## Remarks

File systems must call **SeCaptureSubjectContext** before performing access validation or generating audit messages. This is necessary to provide a consistent security context to routines such as **SeQueryAuthenticationIdToken**, **SeQuerySubjectContextToken**, and **SePrivilegeCheck**. After these operations have been performed, the captured context should be released as soon as possible by calling **SeReleaseSubjectContext**.

For more information about security and access control, see the documentation on these topics in the Microsoft Windows SDK.

## See also

[SECURITY_SUBJECT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[SeCaptureSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontext)

[SeLockSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-selocksubjectcontext)

[SePrivilegeCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck)

[SeQueryAuthenticationIdToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken)

[SeQuerySubjectContextToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken)

[SeUnlockSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seunlocksubjectcontext)