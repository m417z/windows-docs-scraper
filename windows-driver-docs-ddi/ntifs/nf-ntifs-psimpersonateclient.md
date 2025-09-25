# PsImpersonateClient function

## Description

The **PsImpersonateClient** routine causes a server thread to impersonate a client.

## Parameters

### `Thread` [in, out]

Pointer to the server thread that is to impersonate the client.

### `Token` [in]

Pointer to the token to be assigned as the impersonation token. This token can be a primary token or an impersonation token. Set to **NULL** to end the impersonation.

### `CopyOnOpen` [in]

Specifies whether the token can be opened directly. Set to **TRUE** to specify that the token cannot be opened directly. In this case, the token must be duplicated, and the duplicate token used instead. Set to **FALSE** to allow the token to be opened directly.

### `EffectiveOnly` [in]

Set to **FALSE** to allow the server to enable groups and privileges that are currently disabled in the client security context, **TRUE** otherwise.

### `ImpersonationLevel` [in]

A [SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level) value that specifies the impersonation level at which the server is to access the token.

## Return value

**PsImpersonateClient** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | It was not possible to impersonate a client because of job restrictions. |
| **STATUS_NO_MEMORY** | There was insufficient memory to complete the operation. |

## Remarks

**PsImpersonateClient** causes the specified server thread to impersonate the specified client.

The server thread could already be impersonating a client when **PsImpersonateClient** is called. If this is the case, the reference count on the token representing that client is decremented. To preserve this token for later use, drivers should call [PsReferenceImpersonationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psreferenceimpersonationtoken) before calling **PsImpersonateClient** and save the pointer that is returned by **PsReferenceImpersonationToken**.

To end the new impersonation and return the server thread to the previous impersonation, call **PsImpersonateClient** again, passing the saved pointer for the *Token* parameter. To end all impersonations, call the [PsRevertToSelf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psreverttoself) routine.

Otherwise, to end the impersonation and return the server thread to its original security context (that is, the one represented by its primary token), call **PsImpersonateClient** again, passing a **NULL** pointer for the *Token* parameter.

The **PsImpersonateClient** routine can fail to successfully return the server thread to the previous impersonation if the thread is already impersonating or there are job restrictions.

The routine ensures whether client impersonation can actually occur by checking various conditions, including the following:

* The token passed by the caller doesn't have an anonymous authentication ID
* The process's token referenced from the server thread and the given token have equal security identifiers (SIDs)
* Neither of the tokens are restricted

If none of the conditions are met, the routine makes a copy of the existing token passed to the call and assigns the newly copied token as impersonation token albeit with limited security impersonation level; that is, the server thread can only obtain information about the client. If token copying is not possible, the routine fails with a NTSTATUS code.

It is extremely unsafe to raise the privilege state of an untrusted user thread (take a user's thread and impersonate LocalSystem, for example). If an untrusted user thread had its privilege raised, the user could grab the thread token after it has been elevated and subvert the security of the entire system.

In cases where a higher privilege state is required, the task should be dispatched to a work queue where the task can be safely handled by system worker thread . This way no impersonation is necessary.

The [SeImpersonateClientEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seimpersonateclientex) routine can be used to cause a thread to impersonate a user.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)

[PsReferenceImpersonationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psreferenceimpersonationtoken)

[PsRevertToSelf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psreverttoself)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)

[SeImpersonateClientEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seimpersonateclientex)