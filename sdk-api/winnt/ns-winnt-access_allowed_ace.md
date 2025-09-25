# ACCESS_ALLOWED_ACE structure

## Description

The **ACCESS_ALLOWED_ACE** structure defines an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) for the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) that controls access to an object. An access-allowed ACE allows access to an object for a specific [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) identified by a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

## Members

### `Header`

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure that specifies the size and type of ACE. It also contains flags that control inheritance of the ACE by child objects. The **AceType** member of the **ACE_HEADER** structure should be set to ACCESS_ALLOWED_ACE_TYPE, and the **AceSize** member should be set to the total number of bytes allocated for the **ACCESS_ALLOWED_ACE** structure.

### `Mask`

Specifies an
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) structure that specifies the access rights granted by this ACE.

### `SidStart`

The first **DWORD** of a trustee's SID. The remaining bytes of the SID are stored in contiguous memory after the **SidStart** member. This SID can be appended with application data.

## Remarks

ACE structures must be aligned on **DWORD** boundaries. All Windows memory-management functions return **DWORD**-aligned handles to memory.

The access rights specified by the **Mask** member are granted to any [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) that possesses an enabled SID that matches the SID stored in the **SidStart** member.

An **ACCESS_ALLOWED_ACE** structure can be created in an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) by a call to the [AddAccessAllowedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedace) or [AddAccessAllowedAceEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedaceex) function. When these functions are used, the correct amount of memory needed to accommodate the trustee's SID is allocated and the values of the **Header.AceType** and **Header.AceSize** members are set automatically. If the **AddAccessAllowedAceEx** function is used, the **Header.AceFlags** member is also set. When an **ACCESS_ALLOWED_ACE** structure is created outside an ACL, sufficient memory must be allocated to accommodate the complete SID of the trustee in the **SidStart** member and the contiguous memory following it, and the values of the **Header.AceType**, **Header.AceFlags**, and **Header.AceSize** members must be set explicitly by the application.

## See also

[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[AddAccessAllowedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedace)

[AddAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addace)

[GetAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getace)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)