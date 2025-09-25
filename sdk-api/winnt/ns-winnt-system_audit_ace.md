# SYSTEM_AUDIT_ACE structure

## Description

The **SYSTEM_AUDIT_ACE** structure defines an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) for the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) that specifies what types of access cause system-level notifications. A system-audit ACE causes an audit message to be logged when a specified [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) attempts to gain access to an object. The trustee is identified by a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

## Members

### `Header`

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure that specifies the size and type of ACE. It also contains flags that control inheritance of the ACE by child objects. The **AceType** member of the **ACE_HEADER** structure should be set to SYSTEM_AUDIT_ACE_TYPE, and the **AceSize** member should be set to the total number of bytes allocated for the **SYSTEM_AUDIT_ACE** structure.

### `Mask`

Specifies an
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) structure that gives the access rights that cause audit messages to be generated. The SUCCESSFUL_ACCESS_ACE_FLAG and FAILED_ACCESS_ACE_FLAG flags in the **AceFlags** member of the [ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure indicate whether messages are generated for successful access attempts, unsuccessful access attempts, or both.

### `SidStart`

The first **DWORD** of a trustee's SID. The remaining bytes of the SID are stored in contiguous memory after the **SidStart** member. This SID can be appended with application data.

An access attempt of a kind specified by the **Mask** member by any trustee whose SID matches the **SidStart** member causes the system to generate an audit message. If an application does not specify a SID for this member, audit messages are generated for the specified access rights for all trustees.

## Remarks

Audit messages are stored in an event log that can be manipulated by using the Windows API event-logging functions or by using the Event Viewer (Eventvwr.exe).

ACE structures should be aligned on **DWORD** boundaries. All Windows memory-management functions return **DWORD**-aligned handles to memory.

When a **SYSTEM_AUDIT_ACE** structure is created, sufficient memory must be allocated to accommodate the complete SID of the trustee in the **SidStart** member and the contiguous memory that follows it.

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)