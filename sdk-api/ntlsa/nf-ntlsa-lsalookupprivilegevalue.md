# LsaLookupPrivilegeValue function

## Description

Retrieves the [locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID) used by the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) to represent the specified privilege name.

This function is not declared in a public header.

Do not use this function. Instead, use [LookupPrivilegeValue](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegevaluea).

## Parameters

### `PolicyHandle`

A handle to the LSA [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object.

### `Name`

A pointer to a null-terminated string that specifies the name of the privilege, as defined in the Winnt.h header file.

### `Value`

A pointer to a variable that receives the LUID by which the privilege is known by the LSA.

## Return value

If the function succeeds, return **STATUS_SUCCESS**.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.