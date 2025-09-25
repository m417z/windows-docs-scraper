# SYSTEM_SCOPED_POLICY_ID_ACE structure

## Description

The **SYSTEM_SCOPED_POLICY_ID_ACE** structure defines an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) for the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) that specifies the scoped policy identifier for a securable object.

## Members

### `Header`

An [ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure that specifies the size and type of the ACE. The structure also contains flags that control inheritance of the ACE by child objects. The **AceType** member of the **ACE_HEADER** structure must be set to **SYSTEM_SCOPED_POLICY_ID_ACE**, and the **AceSize** member must be set to the total number of bytes allocated for the **SYSTEM_SCOPED_POLICY_ID_ACE** structure.

### `Mask`

The access policy associated with the SACL that contains this ACE.

### `SidStart`

Specifies the first **DWORD** of a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid).