# SYSTEM_RESOURCE_ATTRIBUTE_ACE structure

## Description

The **SYSTEM_RESOURCE_ATTRIBUTE_ACE** structure defines an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) for the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) that specifies the system resource attributes for a securable object.

## Members

### `Header`

An [ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure that specifies the size and type of the ACE. The structure also contains flags that control inheritance of the ACE by child objects. The **AceType** member of the **ACE_HEADER** structure must be set to **SYSTEM_RESOURCE_ATTRIBUTE_ACE**, and the **AceSize** member must be set to the total number of bytes allocated for the **SYSTEM_RESOURCE_ATTRIBUTE_ACE** structure.

### `Mask`

The access policy associated with the SACL that contains this ACE.

### `SidStart`

Specifies the first **DWORD** of a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid). The remaining bytes of the **SID** are stored in contiguous memory after the **SidStart** member in a [CLAIM_SECURITY_ATTRIBUTE_RELATIVE_V1](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-claim_security_attribute_relative_v1) structure.