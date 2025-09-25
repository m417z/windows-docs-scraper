# WslLaunchInteractive function

## Description

Launches an interactive Windows Subsystem for Linux (WSL) process in the context of a particular distribution.This differs from [WslLaunch](https://learn.microsoft.com/previous-versions/windows/desktop/api/wslapi/nf-wslapi-wsllaunch) in that the end user will be able to interact with the newly-created process.

## Parameters

### `distributionName` [in]

Unique name representing a distribution (for example, "Fabrikam.Distro.10.01").

### `command` [in, optional]

Command to execute. If no command is supplied, launches the default shell.

### `useCurrentWorkingDirectory` [in]

Governs whether or not the launched process should inherit the calling process's working directory. If FALSE, the process is started in the WSL default user's home directory ("~").

### `exitCode` [out]

Receives the exit code of the process after it exits.

## Return value

Returns S_OK on success, or a failing HRESULT otherwise.