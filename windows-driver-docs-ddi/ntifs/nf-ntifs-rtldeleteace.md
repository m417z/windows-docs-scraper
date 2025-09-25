# RtlDeleteAce function

## Description

The **RtlDeleteAce** routine deletes an access control entry (ACE) from a specified access control list (ACL).

## Parameters

### `Acl` [in, out]

Pointer to the ACL to be modified. **RtlDeleteAce** deletes the specified ACE from this ACL.

### `AceIndex` [in]

Specifies the ACE to delete. A value of zero corresponds to the first ACE in the ACL, 1 to the second ACE, and so on.

## Return value

**RtlDeleteAce** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_INVALID_PARAMETER | One of the parameter values was invalid. |

Possible reasons for STATUS_INVALID_PARAMETER include:

* The specified ACL is invalid.
* The specified index value is out of range.
* STATUS_INVALID_PARAMETER is an error code.

## Remarks

For information about calculating the size of an ACL, see the Remarks section of the reference entry for [**RtlCreateAcl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl).

To add an ACE to an ACL, use [**RtlAddAce**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtladdace).

To obtain a pointer to an ACE in an ACL, use [**RtlGetAce**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetace).

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**ACE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[**RtlAddAce**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtladdace)

[**RtlCreateAcl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl)

[**RtlGetAce**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetace)