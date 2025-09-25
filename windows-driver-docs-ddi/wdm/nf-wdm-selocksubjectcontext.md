# SeLockSubjectContext function (wdm.h)

## Description

The **SeLockSubjectContext** routine locks the primary and impersonation tokens of a captured subject context.

## Parameters

### `SubjectContext` [in]

Pointer to a SECURITY_SUBJECT_CONTEXT structure returned by a call to **SeCaptureSubjectContext**.

## Remarks

**SeLockSubjectContext** acquires read locks on the primary and impersonation tokens of a captured subject context.

To capture a subject context, use **SeCaptureSubjectContext**.

Each call to **SeLockSubjectContext** must be matched by a subsequent call to **SeUnlockSubjectContext**.

For more information about security and access control, see the documentation on these topics in the Microsoft Windows SDK.

## See also

[SECURITY_SUBJECT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[SeCaptureSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontext)

[SeUnlockSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seunlocksubjectcontext)