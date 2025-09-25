# ACL structure

## Description

The **ACL** structure is the header of an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL). A complete ACL consists of an **ACL** structure followed by an ordered list of zero or more [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs).

## Members

### `AclRevision`

Specifies the revision level of the ACL. This value should be ACL_REVISION, unless the ACL contains an object-specific ACE, in which case this value must be ACL_REVISION_DS. All ACEs in an ACL must be at the same revision level.

### `Sbz1`

Specifies a zero byte of [padding](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that aligns the **AclRevision** member on a 16-bit boundary.

### `AclSize`

Specifies the size, in bytes, of the ACL. This value includes the **ACL** structure, all the ACEs, and the potential unused memory.

### `AceCount`

Specifies the number of ACEs stored in the ACL.

### `Sbz2`

Specifies two zero-bytes of [padding](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that align the **ACL** structure on a 32-bit boundary.

## Remarks

An ACL includes a sequential list of zero or more ACEs. The individual ACEs in an ACL are numbered from 0 to *n*, where *n*+1 is the number of ACEs in the ACL. When editing an ACL, an application refers to an ACE within the ACL by the ACE's index.

There are two types of ACL: discretionary and system.

A [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) is controlled by the owner of an object or anyone granted WRITE_DAC access to the object. It specifies the access particular users and groups can have to an object. For example, the owner of a file can use a DACL to control which users and groups can and cannot have access to the file.

An object can also have system-level security information associated with it, in the form of a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) controlled by a system administrator. A SACL allows the system administrator to audit any attempts to gain access to an object.

For a list of currently defined ACE structures, see [ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace).

A fourth ACE structure, [SYSTEM_ALARM_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_alarm_ace), is not currently supported.

The **ACL** structure is to be treated as though it were opaque and applications are not to attempt to work with its members directly. To ensure that ACLs are semantically correct, applications can use the functions listed in the See Also section to create and manipulate ACLs.

Each **ACL** and [ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace) structure begins on a **DWORD** boundary.

The maximum size for an ACL, including its ACEs, is 64 KB.

## See also

[AddAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addace)

[DeleteAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-deleteace)

[GetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getaclinformation)

[GetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptordacl)

[GetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorsacl)

[InitializeAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializeacl)

[IsValidAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidacl)

[SetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setaclinformation)

[SetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl)

[SetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorsacl)