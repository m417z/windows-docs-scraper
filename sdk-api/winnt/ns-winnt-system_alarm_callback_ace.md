# SYSTEM_ALARM_CALLBACK_ACE structure

## Description

Not supported.

The **SYSTEM_ALARM_CALLBACK_ACE** structure is reserved for future use.

## Members

### `Header`

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure that specifies the size and type of ACE. It also contains flags that control inheritance of the ACE by child objects. The **AceType** member of the **ACE_HEADER** structure should be set to SYSTEM_ALARM_CALLBACK_ACE_TYPE.

### `Mask`

Specifies an
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) structure that gives the access rights that cause audit messages to be generated. The SUCCESSFUL_ACCESS_ACE_FLAG and FAILED_ACCESS_ACE_FLAG flags in the **AceFlags** member of the [ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure indicate whether messages are generated for successful access attempts, unsuccessful access attempts, or both.

### `SidStart`

The first **DWORD** of a trustee's ACE. This ACE can be appended with application data. When the [AuthzAccessCheckCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzaccesscheckcallback) function is called, this ACE is passed as the *pAce* parameter of that function.

## Remarks

ACE structures must be aligned on **DWORD** boundaries. All Windows memory-management functions return **DWORD**-aligned handles to memory.