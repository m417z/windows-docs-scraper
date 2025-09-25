# AppPolicyProcessTerminationMethod enumeration

## Description

The AppPolicyProcessTerminationMethod enumeration indicates the method used to end a process.

## Constants

### `AppPolicyProcessTerminationMethod_ExitProcess`

Allows DLLs to execute code at shutdown. This value is expected for a desktop application, or for a Desktop Bridge application.

### `AppPolicyProcessTerminationMethod_TerminateProcess`

Immediately ends the process. This value is expected for a UWP app.