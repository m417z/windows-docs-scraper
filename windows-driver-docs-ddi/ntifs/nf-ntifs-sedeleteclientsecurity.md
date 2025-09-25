# SeDeleteClientSecurity macro

## Description

The **SeDeleteClientSecurity** routine deletes a client security context.

## Parameters

### `ClientContext`

Pointer to the client security context structure to be deleted.

## Remarks

**SeDeleteClientSecurity** deletes a client security context structure and performs any necessary cleanup, such as removing any client token references.

Each call to **SeCreateClientSecurity** or **SeCreateClientSecurityFromSubjectContext** must be matched by a subsequent call to **SeDeleteClientSecurity**.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**SeCreateClientSecurity**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secreateclientsecurity)

[**SeCreateClientSecurityFromSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secreateclientsecurityfromsubjectcontext)