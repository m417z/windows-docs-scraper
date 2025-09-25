# RtlAddAccessAllowedAceEx function

## Description

The **RtlAddAccessAllowedAceEx** routine adds an access-allowed access control entry ([**ACE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)
) with inheritance ACE flags to an access control list ([**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)). The access is granted to the specified security identifier ([**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)).

## Parameters

### `Acl` [in, out]

A pointer to a caller-allocated buffer that contains the ACL to be modified. **RtlAddAccessAllowedAceEx** adds an access-allowed ACE to the end of this ACL. The ACE is in the form of an [**ACCESS_ALLOWED_ACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_access_allowed_ace) structure.

### `AceRevision` [in]

ACL revision level of the ACE to be added. This value can be ACL_REVISION or ACL_REVISION_DS. It must be ACL_REVISION_DS if the ACL contains an object-specific ACE.

### `AceFlags` [in]

Bitmask specifying the inherit flags of the ACE to be added.

### `AccessMask` [in]

A bitmask of one or more [**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) flags that specify the access rights to be granted to the specified SID. For more information, see the description of the **DesiredAccess** parameter of [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).

### `Sid` [in]

A pointer to the SID structure that represents a user, group, or logon account that is being granted access.

## Return value

**RtlAddAccessAllowedAceEx** can return one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The ACE was successfully added. |
| STATUS_ALLOTTED_SPACE_EXCEEDED | A new ACE does not fit into the ACL. A larger ACL buffer is required. For more information about how to calculate the size of an ACL, see [**RtlCreateAcl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl). |
| STATUS_INVALID_ACL | The specified ACL is not correctly formed. |
| STATUS_INVALID_PARAMETER | The AceFlags parameter was invalid. |
| STATUS_INVALID_SID | The specified SID structure is not structurally valid. |
| STATUS_REVISION_MISMATCH | The specified **AceRevision** is not known or is not compatible with that of the ACL. |

## Remarks

Unlike [**RtlAddAccessAllowedAce**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtladdaccessallowedace), this routine sets the inheritance ACE flags.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK, such as:

* [Access Control Lists](https://learn.microsoft.com/windows/win32/secauthz/access-control-lists)

* [Creating or Modifying an ACL](https://learn.microsoft.com/windows/win32/secauthz/creating-or-modifying-an-acl)

* [Getting Information from an ACL](https://learn.microsoft.com/windows/win32/secauthz/getting-information-from-an-acl)

## See also

[**ACCESS_ALLOWED_ACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_access_allowed_ace)

[**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[**ACE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[**RtlCreateAcl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl)

[**RtlCreateSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[**RtlCreateSecurityDescriptorRelative**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreatesecuritydescriptorrelative)

[**RtlLengthSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[**RtlSetDaclSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[**RtlSetOwnerSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor)

[**RtlValidSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SeAssignSecurity**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seassignsecurity)

[**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)