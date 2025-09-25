# ACCESS_DENIED_CALLBACK_ACE structure

## Description

The **ACCESS_DENIED_CALLBACK_ACE** structure defines an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) for the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) that controls access to an object. An access-denied ACE denies access to an object for a specific [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) identified by a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

When the [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) function is called, each **ACCESS_DENIED_CALLBACK_ACE** structure contained in the DACL of a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure passed through a pointer to the **AuthzAccessCheck** function invokes a call to the application–defined [AuthzAccessCheckCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzaccesscheckcallback) function, in which a pointer to the **ACCESS_DENIED_CALLBACK_ACE** structure found is passed in the *pAce* parameter.

## Members

### `Header`

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure that specifies the size and type of ACE. It also contains flags that control inheritance of the ACE by child objects. The **AceType** member of the **ACE_HEADER** structure should be set to ACCESS_DENIED_CALLBACK_ACE_TYPE, and the **AceSize** member should be set to the total number of bytes allocated for the **ACCESS_DENIED_CALLBACK_ACE** structure.

### `Mask`

Specifies an
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) structure that specifies the access rights explicitly denied by this ACE.

### `SidStart`

The first **DWORD** of a trustee's SID. The remaining bytes of the SID are stored in contiguous memory after the **SidStart** member. This SID can be appended with application data.

## Remarks

[ACE structures](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace) must be aligned on **DWORD** boundaries. All Windows memory-management functions return **DWORD**-aligned handles to memory.

The access rights specified by the **Mask** member are granted to any [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) that possesses an enabled SID that matches the SID stored in the **SidStart** member.

When an **ACCESS_DENIED_CALLBACK_ACE** structure is created, sufficient memory must be allocated to accommodate the complete SID of the trustee in the **SidStart** member and the contiguous memory that follows it.

## See also

[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[AddAuditAccessObjectAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessobjectace)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)