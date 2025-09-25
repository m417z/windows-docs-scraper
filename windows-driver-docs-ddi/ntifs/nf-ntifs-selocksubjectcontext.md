# SeLockSubjectContext function (ntifs.h)

## Description

The **SeLockSubjectContext** routine locks the primary and impersonation tokens of a captured subject context.

## Parameters

### `SubjectContext` [in]

Pointer to the [**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#security_subject_context) structure. This opaque structure is obtained from the operating system in a call to [**SeCaptureSubjectContextEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontextex)
or [**SeCaptureSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontext).

## Remarks

**SeLockSubjectContext** acquires read locks on the primary and impersonation tokens of a captured subject context. Each call to **SeLockSubjectContext** must be matched by a subsequent call to [**SeUnlockSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seunlocksubjectcontext).

To capture a subject context, use [**SeCaptureSubjectContextEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontextex)
or [**SeCaptureSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontext).

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#security_subject_context)

[**SeCaptureSubjectContextEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontextex)

[**SeUnlockSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seunlocksubjectcontext)