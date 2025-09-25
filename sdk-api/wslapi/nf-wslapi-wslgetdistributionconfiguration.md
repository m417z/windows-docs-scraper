# WslGetDistributionConfiguration function

## Description

 Retrieves the current configuration of a distribution registered with the Windows Subsystem for Linux (WSL).

## Parameters

### `distributionName` [in]

Unique name representing a distribution (for example, "Fabrikam.Distro.10.01").

### `distributionVersion` [out]

The version of WSL for which this distribution is configured.

### `defaultUID` [out]

The default user ID used when launching new WSL sessions for this distribution.

### `wslDistributionFlags` [out]

The flags governing the behavior of this distribution.

### `defaultEnvironmentVariables` [out]

The address of a pointer to an array of default environment variable strings used when launching new WSL sessions for this distribution.

### `defaultEnvironmentVariableCount` [out]

The number of elements in *pDefaultEnvironmentVariablesArray*.

## Return value

Returns S_OK on success, or a failing HRESULT otherwise.

## Remarks

The caller is responsible for freeing each string in *pDefaultEnvironmentVariablesArray* (and the array itself) via **CoTaskMemFree**.