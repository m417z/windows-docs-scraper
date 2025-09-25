# WSMAN_SHELL_STARTUP_INFO_V10 structure

## Description

Defines the shell startup parameters to be used with the [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) function. The structure must be allocated by the client and passed to the **WSManCreateShell** function.

The configuration passed to the [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) function can directly affect the behavior of a command executed within the shell. A typical example is the *workingDirectory* argument that describes the working directory associated with each process, which the operating system uses when attempting to locate files specified by using a relative path.

In the absence of specific requirements for stream naming, clients and services should attempt to use **STDIN** for input streams, **STDOUT** for the default output stream, and **STDERR** for the error or status output stream.

## Members

### `inputStreamSet`

A pointer to a [WSMAN_STREAM_ID_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_stream_id_set) structure that specifies a set of input streams for the shell. Streams not present in the filter can be ignored by the shell implementation. For the Windows Cmd.exe shell, this value should be L"stdin".
If the value is **NULL**, the implementation uses an array with L"stdin" as the default value.

### `outputStreamSet`

A pointer to a [WSMAN_STREAM_ID_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_stream_id_set) structure that specifies a set of output streams for the shell. Streams not present in the filter can be ignored by the shell implementation. For the Windows cmd.exe shell, this value should be L"stdout stderr".
If the value is **NULL**, the implementation uses an array with L"stdout" and L"stderr" as the default value.

### `idleTimeoutMs`

Specifies the maximum duration, in milliseconds, the shell will stay open without any client request. When the maximum duration is exceeded, the shell is automatically deleted. Any value from 0 to 0xFFFFFFFF can be set. This duration has a maximum value specified by the Idle time-out GPO setting, if enabled, or by the IdleTimeout local configuration. The default value of the maximum duration in the GPO/local configuration is 15 minutes. However, a system administrator can change this value. To use the maximum value from the GPO/local configuration, the client should specify 0 (zero) in this field. If an explicit value between 0 to 0xFFFFFFFF is used, the minimum value between the explicit API value and the value from the GPO/local configuration is used.

### `workingDirectory`

Specifies the starting directory for a shell. It is used with any execution command. If this member is a **NULL** value, a default directory will be used by the remote machine when executing the command. An empty value is treated by the underlying protocol as an omitted value.

### `variableSet`

A pointer to a [WSMAN_ENVIRONMENT_VARIABLE_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_environment_variable_set) structure that specifies an array of variable name and value pairs, which describe the starting environment for the shell. The content of these elements is shell specific and can be defined in terms of other environment variables. If a **NULL** value is passed, the default environment is used on the server side.

#### - name

Specifies an optional friendly name to be associated with the shell. This parameter is only functional when the client passes the flag **WSMAN_FLAG_REQUESTED_API_VERSION_1_1** to WSManInitialize.