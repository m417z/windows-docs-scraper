# PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY structure

## Description

Used to impose new behavior on handle references that are not valid.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

This member is reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.RaiseExceptionOnInvalidHandleReference`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.HandleExceptionsPermanentlyEnabled`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

#### - HandleExceptionsPermanentlyEnabled : 1

When set to 1, exceptions for invalid kernel handles are permanently enabled.

#### - RaiseExceptionOnInvalidHandleReference : 1

When set to 1, an exception is raised if an invalid handle to a kernel object is used. Except as noted in the Remarks section, once exceptions for invalid handles are enabled for a process, they cannot be disabled.

#### - ReservedFlags : 30

This member is reserved for system use.

## Remarks

As a general rule, strict handle checking cannot be turned off once it is turned on. Therefore, when calling the [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy) function with this policy, the values of the **RaiseExceptionOnInvalidHandleReference** and **HandleExceptionsPermanentlyEnabled** substructure members must be the same. It is not possible to enable invalid handle exceptions only temporarily.

The exception to the general rule about strict handle checking always being a permanent state is that debugging tools such as Application Verifier can cause the operating system to enable invalid handle exceptions temporarily. Under those cases, it is possible for the [GetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy) function to return with **RaiseExceptionOnInvalidHandleReference** set to 1, but **HandleExceptionsPermanentlyEnabled** set to 0.