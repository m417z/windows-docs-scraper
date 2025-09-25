# RtlAddAccessAllowedAce function

## Description

The **RtlAddAccessAllowedAce** routine adds an access-allowed access control entry (ACE) to an access control list (ACL). The access is granted to the specified security identifier (SID).

## Parameters

### `Acl` [in, out]

Pointer to a caller-allocated buffer containing the ACL to be modified. **RtlAddAccessAllowedAce** adds an access-allowed ACE to the end of this ACL. The ACE is in the form of an ACCESS_ALLOWED_ACE structure.

### `AceRevision` [in]

ACL revision level of the ACE to be added. Windows version requirements are the following:

| Value | Meaning |
| --- | --- |
| ACL_REVISION | The revision level valid on all Windows versions. |
| ACL_REVISION_DS | The revision level valid starting with Windows 2000.<br><br>**Note** *AceRevision* must be ACL_REVISION_DS if the ACL in *Acl* contains an object-specific ACE. |

### `AccessMask` [in]

Bitmask of one or more [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) flags specifying the access rights to be granted to the specified SID. For more information, see the description of the *DesiredAccess* parameter of **ZwCreateFile**.

### `Sid` [in]

Pointer to the SID structure representing a user, group, or logon account that is being granted access.

## Return value

**RtlAddAccessAllowedAce** can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The ACE was successfully added. |
| **STATUS_ALLOTTED_SPACE_EXCEEDED** | A new ACE does not fit into the ACL. A larger ACL buffer is required. See [RtlCreateAcl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl) for information about calculating the size of an ACL. |
| **STATUS_INVALID_ACL** | The specified ACL is not properly formed. |
| **STATUS_INVALID_SID** | The specified SID structure is not structurally valid. |
| **STATUS_REVISION_MISMATCH** | The specified revision is not known or is not compatible with that of the ACL. |

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_access_allowed_ace)

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[RtlCreateAcl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl)

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlCreateSecurityDescriptorRelative](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreatesecuritydescriptorrelative)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlSetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[SeAssignSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seassignsecurity)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)