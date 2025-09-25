# RtlGetAce function

## Description

The **RtlGetAce** routine obtains a pointer to an access control entry (ACE) in an access control list (ACL).

## Parameters

### `Acl` [in]

Pointer to an ACL containing the ACE to be retrieved.

### `AceIndex` [in]

Specifies the ACE to which a pointer is retrieved. A value of zero corresponds to the first ACE in the ACL, 1 to the second ACE, and so on.

### `Ace` [out]

Pointer to a caller-allocated variable to receive the address of the ACE within the ACL.

## Return value

**RtlGetAce** returns STATUS_SUCCESS or an error status code such as STATUS_INVALID_PARAMETER.

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[RtlCreateAcl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl)