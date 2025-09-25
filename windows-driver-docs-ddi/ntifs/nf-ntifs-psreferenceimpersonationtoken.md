# PsReferenceImpersonationToken function

## Description

The **PsReferenceImpersonationToken** routine increments the reference count of the impersonation token for the specified thread.

## Parameters

### `Thread` [in, out]

Address of the thread whose impersonation token's reference count is to be incremented.

### `CopyOnOpen` [out]

Pointer to a caller-allocated Boolean variable. On return, this parameter receives TRUE if the token cannot be opened directly. In this case, the token must be duplicated, and the duplicate token must be used instead. If the token can be opened directly, this parameter receives FALSE.

### `EffectiveOnly` [out]

Pointer to a caller-allocated Boolean variable. On return, this parameter receives FALSE if the thread is allowed to enable groups and privileges that are currently disabled in the client security context, TRUE otherwise.

### `ImpersonationLevel` [out]

Pointer to a caller-allocated SECURITY_IMPERSONATION_LEVEL variable. On return, this parameter receives a value that specifies the impersonation level at which the thread is allowed to access the token.

## Return value

**PsReferenceImpersonationToken** returns a pointer to the impersonation token for the given thread. If the thread is not currently impersonating a client, a NULL pointer is returned.

## Remarks

If the thread is currently impersonating a client, **PsReferenceImpersonationToken** increments the reference count of the impersonation token and returns a pointer to the token. If the returned pointer is non-**NULL**, the impersonation token's reference count must be decremented by calling one of the following functions:

* **ObDereferenceObject**, for Windows 2000
* **PsDereferenceImpersonationToken**, for Microsoft Windows XP or later

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[**PsDereferenceImpersonationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceimpersonationtoken)

[**PsImpersonateClient**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psimpersonateclient)

[**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)