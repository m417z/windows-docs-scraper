# SeQuerySubjectContextToken macro

## Description

The **SeQuerySubjectContextToken** macro retrieves the access token for a security subject context.

## Syntax

```cpp
PACESS_TOKEN
SeQuerySubjectContextToken(SubjectContext);
```

## Parameters

### `SubjectContext`

[in] Pointer to an opaque [**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#security_subject_context) structure containing the subject context to query. This opaque structure was obtained from the operating system in a call to [**SeCaptureSubjectContextEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontextex)
or [**SeCaptureSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontext). Drivers must not modify or try to directly access any members of this structure to make security decisions.

## Remarks

**SeQuerySubjectContextToken** returns the effective token from **SubjectContext**. The effective token is the client token, if present; otherwise it is the primary (process) token.

**SeQuerySubjectContextToken** can return either a primary or impersonation token. Since drivers must not directly access any members of the [**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#security_subject_context) structure, you should first pass it to [**SeAccessCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck) or [**SePrivilegeCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck) to avoid security issues in authorization; for example, if this is an impersonation token, it requires an impersonation level of **SecurityImpersonation** or higher. Once you've confirmed authorization status, you can then pass the access token pointer returned by **SeQuerySubjectContextToken** to [**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken).

**SeQuerySubjectContextToken** does not affect the lock status or access token of the subject context.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**PsDereferenceImpersonationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceimpersonationtoken)

[**PsDereferencePrimaryToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceprimarytoken)

[**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#security_subject_context)

[**SeQueryAuthenticationIdToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**SeTokenIsAdmin**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisadmin)

[**SeTokenIsRestricted**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisrestricted)