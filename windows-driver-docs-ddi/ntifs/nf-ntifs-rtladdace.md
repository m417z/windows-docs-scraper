# RtlAddAce function

## Description

The **RtlAddAce** routine adds one or more access control entries (ACEs) to a specified access control list ([**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)).

## Parameters

### `Acl` [in, out]

Pointer to the ACL to be modified. **RtlAddAce** adds the specified ACEs to this ACL.

### `AceRevision` [in]

ACL revision level of the ACE to be added. Windows version requirements are the following:

| Value | Meaning |
| ----- | ------- |
| ACL_REVISION | The revision level valid on all Windows versions. |
| ACL_REVISION_DS | The revision level valid starting with Windows 2000. |

**AceRevision** must be ACL_REVISION_DS if the ACL in **Acl** contains an object-specific ACE.

### `StartingAceIndex` [in]

Specifies the position in the ACL's list of ACEs at which to add new ACEs. A value of zero inserts the ACEs at the beginning of the list. A value of MAXULONG appends the ACEs to the end of the list.

### `AceList` [in]

Pointer to a buffer containing a list of one or more ACEs to be added to the specified ACL. The ACEs in the list must be stored contiguously.

### `AceListLength` [in]

Size, in bytes, of the input buffer pointed to by the **AceList** parameter.

## Return value

**RtlAddAce** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_BUFFER_TOO_SMALL | The new ACEs do not fit into the ACL. A larger ACL buffer is required. STATUS_BUFFER_TOO_SMALL is an error code. |
| STATUS_INVALID_PARAMETER | One of the parameter values was invalid. Possible reasons include that the specified ACL is invalid or the specified revision is unknown, is not compatible with revisions in the ACE list, or is not compatible with the revision of the ACL. STATUS_INVALID_PARAMETER is an error code. |

## Remarks

For information about calculating the size of an ACL, see the Remarks section of the reference entry for [**RtlCreateAcl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl).

To obtain a pointer to an ACE in an ACL, use [**RtlGetAce**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetace).

To delete an ACE from an ACL, use [**RtlDeleteAce**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldeleteace).

To add an access-allowed ACE to an ACL, use [**RtlAddAccessAllowedAce**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtladdaccessallowedace).

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**ACE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[**RtlAddAccessAllowedAce**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtladdaccessallowedace)

[**RtlCreateAcl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl)

[**RtlDeleteAce**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldeleteace)

[**RtlGetAce**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetace)