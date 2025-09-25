# GetCurrentProcessHandle function

## Description

The **GetCurrentProcessHandle** function returns the system handle for the current process.

## Parameters

### `hp`

Receives the system handle for the current process.

## Remarks

In kernel-mode debugging, the only process in the target is the virtual process created for the kernel. In this case, an artificial handle is created. The artificial handle can only be used with the debugger.