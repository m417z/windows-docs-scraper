# WslConfigureDistribution function

## Description

Modifies the behavior of a distribution registered with the Windows Subsystem for Linux (WSL).

## Parameters

### `distributionName`

Unique name representing a distribution (for example, "Fabrikam.Distro.10.01").

### `defaultUID`

The Linux user ID to use when launching new WSL sessions for this distribution.

### `wslDistributionFlags`

Flags specifying what behavior to use for this distribution.

## Return value

Returns S_OK on success, or a failing HRESULT otherwise.