# _DEBUG_CREATE_PROCESS_OPTIONS structure

## Description

The DEBUG_CREATE_PROCESS_OPTIONS structure specifies the process creation options to use when creating a new process.

## Members

### `CreateFlags`

The flags to use when creating the process. In addition to the flags described in the "Process Creation Flags" topic in the Platform SDK documentation, the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) uses the following flags when creating a process.

| Values | Description |
| --- | --- |
| DEBUG_CREATE_PROCESS_NO_DEBUG_HEAP | (Microsoft Windows Server 2003 and later) Prevents the debug heap from being used in the new process. |
| DEBUG_CREATE_PROCESS_THROUGH_RTL | The native NT RTL process creation routines should be used instead of Win32. This is only meaningful for special processes that run as NT native processes. No Win32 process can be created with this flag. |

When creating and attaching to a process through the debugger engine, set one of the Platform SDK's process creation flags: DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS.

### `EngCreateFlags`

The engine specific flags used when creating the process. **EngCreateFlags** is a combination of the following bit-flags:

| Value | Description |
| --- | --- |
| DEBUG_ECREATE_PROCESS_INHERIT_HANDLES | The new process will inherit system handles from the debugger or process server. |
| DEBUG_ECREATE_PROCESS_USE_VERIFIER_FLAGS | (Windows Vista and later) Use Application Verifier flags in the **VerifierFlags** field. |
| DEBUG_ECREATE_PROCESS_USE_IMPLICIT_COMMAND_LINE | Use the debugger's or process server's implicit command line to start the process instead of a supplied command line. |

### `VerifierFlags`

The Application Verifier flags. Only used if DEBUG_ECREATE_PROCESS_USE_VERIFIER_FLAGS is set in the **EngCreateFlags** field. For possible values, see the [Application Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/application-verifier) documentation.

### `Reserved`

Set to zero.