# PsDereferenceImpersonationToken function

## Description

The **PsDereferenceImpersonationToken** routine decrements the reference count of an impersonation token.

## Parameters

### `ImpersonationToken` [in]

Pointer to the impersonation token whose reference count is to be decremented. If this is a **NULL** pointer, **PsDereferenceImpersonationToken** does nothing.

## Remarks

If the token's reference count reaches zero, the token is deleted.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[PsImpersonateClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psimpersonateclient)

[PsReferenceImpersonationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psreferenceimpersonationtoken)