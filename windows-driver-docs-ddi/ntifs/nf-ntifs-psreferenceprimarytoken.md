# PsReferencePrimaryToken function

## Description

The **PsReferencePrimaryToken** routine increments the reference count of the primary token for the specified process.

## Parameters

### `Process` [in, out]

Pointer to the process whose primary token's reference count is to be incremented.

## Return value

**PsReferencePrimaryToken** returns a pointer to the primary token for the given process.

## Remarks

**PsReferencePrimaryToken** increments the reference count of the returned primary token. Thus for every successful call to **PsReferencePrimaryToken**, the primary token's reference count must be decremented by calling one of the following functions:

* **ObDereferenceObject**, for Windows 2000
* **PsDereferencePrimaryToken**, for Microsoft Windows XP and later

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[**PsDereferencePrimaryToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceprimarytoken)

[**PsReferenceImpersonationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psreferenceimpersonationtoken)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)