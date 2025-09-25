# WslLaunch function

## Description

Launches a Windows Subsystem for Linux (WSL) process in the context of a particular distribution.

## Parameters

### `distributionName` [in]

Unique name representing a distribution (for example, "Fabrikam.Distro.10.01").

### `command` [in, optional]

Command to execute. If no command is supplied, launches the default shell.

### `useCurrentWorkingDirectory` [in]

Governs whether or not the launched process should inherit the calling process's working directory. If FALSE, the process is started in the WSL default user's home directory ("~").

### `stdIn` [in]

Handle to use for **STDIN**.

### `stdOut` [in]

Handle to use for **STDOUT**.

### `stdErr` [in]

Handle to use for **STDERR**.

### `process` [out]

Pointer to address to receive the process HANDLE associated with the newly-launched WSL process.

## Return value

Returns S_OK on success, or a failing HRESULT otherwise.

## Remarks

Caller is responsible for calling **CloseHandle** on the value returned in *phProcess* on success.