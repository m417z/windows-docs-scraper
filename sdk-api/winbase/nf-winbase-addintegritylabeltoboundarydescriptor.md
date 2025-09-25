# AddIntegrityLabelToBoundaryDescriptor function

## Description

Adds a new required security identifier (SID) to the specified boundary descriptor.

## Parameters

### `BoundaryDescriptor` [in, out]

A handle to the boundary descriptor. The [CreateBoundaryDescriptor](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createboundarydescriptora) function returns this handle.

### `IntegrityLabel` [in]

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that represents the mandatory integrity level for the namespace. Use one of the following RID values to create the SID:

**SECURITY_MANDATORY_UNTRUSTED_RID**
**SECURITY_MANDATORY_LOW_RID**
**SECURITY_MANDATORY_MEDIUM_RID**
**SECURITY_MANDATORY_SYSTEM_RID**
**SECURITY_MANDATORY_PROTECTED_PROCESS_RID**
For more information, see [Well-Known SIDs](https://learn.microsoft.com/windows/desktop/SecAuthZ/well-known-sids).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A process can create a private namespace only with an integrity level that is equal to or lower than the current integrity level of the process. Therefore, a high integrity-level process can create a high, medium or low integrity-level namespace. A medium integrity-level process can create only a medium or low integrity-level namespace.

A process would usually specify a namespace at the same integrity level as the process for protection against squatting attacks by lower integrity-level processes.

The security descriptor that the creator places on the namespace determines who can open the namespace. So a low or medium integrity-level process could be given permission to open a high integrity level namespace if the security descriptor of the namespace permits it.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0601 or later.

## See also

[CreateBoundaryDescriptor](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createboundarydescriptora)