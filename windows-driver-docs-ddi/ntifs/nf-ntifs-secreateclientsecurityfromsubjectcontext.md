# SeCreateClientSecurityFromSubjectContext function

## Description

The **SeCreateClientSecurityFromSubjectContext** routine retrieves the access token for a security subject context and uses the result to initialize a security client context with the information needed to call **SeImpersonateClientEx**.

## Parameters

### `SubjectContext` [in]

Pointer to the security subject context of the client to be impersonated.

### `ClientSecurityQos` [in]

Pointer to a caller-allocated SECURITY_QUALITY_OF_SERVICE structure indicating what form of impersonation is to be performed.

### `ServerIsRemote` [in]

Set to TRUE if the server of the client's request is remote.

### `ClientContext` [out]

Pointer to a caller-allocated SECURITY_CLIENT_CONTEXT structure to be initialized.

## Return value

**SeCreateClientSecurityFromSubjectContext** returns STATUS_SUCCESS when it successfully initializes the security client context.

It returns STATUS_BAD_IMPERSONATION_LEVEL when the client to be impersonated is currently impersonating a client of its own, and one of the following is true:

* The client's effective token cannot be passed on for use by another server, because its impersonation level is **SecurityAnonymous** or **SecurityIdentification**.

* **ServerIsRemote** is TRUE, and the client thread is impersonating its client at other than **SecurityDelegation** level.

## Remarks

**SeCreateClientSecurityFromSubjectContext** initializes a client security context block to represent a client's security context.

If the **ContextTrackingMode** member of **ClientSecurityQos** is set to SECURITY_DYNAMIC_TRACKING and **ServerIsRemote** is set to **FALSE**, **SeCreateClientSecurityFromSubjectContext** uses a reference to the client's effective token. Otherwise, **SeCreateClientSecurityFromSubjectContext** creates a copy of the client's token.

Each call to **SeCreateClientSecurityFromSubjectContext** must be matched by a subsequent call to **SeDeleteClientSecurity**.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**SECURITY_SUBJECT_CONTEXT**/(/windows-hardware/drivers/kernel/eprocess##security_subject_context)

[**SeDeleteClientSecurity**/(nf-ntifs-sedeleteclientsecurity.md)

[**SeImpersonateClientEx**/(nf-ntifs-seimpersonateclientex.md)