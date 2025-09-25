# WslRegisterDistribution function

## Description

Registers a new distribution with the Windows Subsystem for Linux (WSL).

## Parameters

### `distributionName` [in]

Unique name representing a distribution (for example, "Fabrikam.Distro.10.01").

### `tarGzFilename` [in]

Full path to a .tar.gz file containing the file system of the distribution to register.

## Return value

This function can return one of the following values. Use the SUCCEEDED and FAILED macros to test the return value of this function.

|  |  |
| --- | --- |
| **Return Code** | **Description** |
| S_OK | Distribution successfully registered with the Windows Subsystem for Linux. |
| HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS) | Failed because a distribution with this name has already been registered. |