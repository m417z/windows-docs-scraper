# ACL_SIZE_INFORMATION structure

## Description

The **ACL_SIZE_INFORMATION** structure contains information about the size of an [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure.

## Members

### `AceCount`

The number of [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) in the [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL).

### `AclBytesInUse`

The number of bytes in the ACL actually used to store the ACEs and [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure. This may be less than the total number of bytes allocated to the ACL.

### `AclBytesFree`

The number of unused bytes in the ACL.

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[ACL_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-acl_information_class)

[ACL_REVISION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_revision_information)

[GetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getaclinformation)

[SetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setaclinformation)