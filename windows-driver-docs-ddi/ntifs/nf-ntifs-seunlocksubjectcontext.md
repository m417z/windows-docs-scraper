# SeUnlockSubjectContext function (ntifs.h)

## Description

The **SeUnlockSubjectContext** routine unlocks the tokens of a captured subject context that were locked by a call to **SeLockSubjectContext**.

## Parameters

### `SubjectContext` [in]

Pointer to a SECURITY_SUBJECT_CONTEXT structure whose tokens are to be unlocked.

## Remarks

**SeUnlockSubjectContext** releases the read locks on the tokens in the captured subject context.

Each call to **SeLockSubjectContext** must be matched by a subsequent call to **SeUnlockSubjectContext**.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#security_subject_context)

[**SeCaptureSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontext)

[**SeCaptureSubjectContextEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontextex)

[**SeLockSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-selocksubjectcontext)

[**SePrivilegeCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck)

[**SeQueryAuthenticationIdToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken)

[**SeQuerySubjectContextToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken)

[**SeReleaseSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sereleasesubjectcontext)