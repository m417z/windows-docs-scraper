# PsDereferencePrimaryToken function

## Description

The **PsDereferencePrimaryToken** routine decrements the reference count of a primary token.

## Parameters

### `PrimaryToken` [in]

Pointer to the primary token whose reference count is to be decremented.

## Remarks

If the token's reference count reaches zero, the token is deleted.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[PsDereferenceImpersonationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceimpersonationtoken)