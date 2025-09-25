# SeCreateClientSecurity function

## Description

The **SeCreateClientSecurity** routine initializes a security client context structure with the information needed to call **SeImpersonateClientEx**.

## Parameters

### `ClientThread` [in]

Pointer to the thread of the client to be impersonated.

### `ClientSecurityQos` [in]

Pointer to a caller-allocated SECURITY_QUALITY_OF_SERVICE structure indicating what form of impersonation is to be performed.

### `RemoteSession`

Set to TRUE if the server of the client's request is remote.

### `ClientContext` [out]

Pointer to a caller-allocated SECURITY_CLIENT_CONTEXT structure to be initialized.

## Return value

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The security client context was successfully initialized. |
| STATUS_BAD_IMPERSONATION_LEVEL | The client to be impersonated is currently impersonating a client of its own, and one of the following is true: (1) The client's effective token cannot be passed on for use by another server, because its impersonation level is **SecurityAnonymous** or **SecurityIdentification**. (2) **ServerIsRemote** is TRUE, and the client thread is impersonating its client at other than **SecurityDelegation** level. |

## Remarks

**SeCreateClientSecurity** initializes a client security context block to represent a client's security context.

If the **ContextTrackingMode** member of **ClientSecurityQos** is set to SECURITY_DYNAMIC_TRACKING and **ServerIsRemote** is set to FALSE, **SeCreateClientSecurity** uses a reference to the client's effective token. Otherwise, **SeCreateClientSecurity** creates a copy of the client's token.

Each call to **SeCreateClientSecurity** must be matched by a subsequent call to **SeDeleteClientSecurity**.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**SeDeleteClientSecurity**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sedeleteclientsecurity)

[**SeImpersonateClientEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seimpersonateclientex)