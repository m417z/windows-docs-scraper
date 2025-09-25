# NetworkIsolationGetEnterpriseIdClose function

## Description

This API is used for closing the handle returned by [NetworkIsolationGetEnterpriseIdAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-networkisolationgetenterpriseidasync) as well as for synchronizing the operation.

Example of NetworkIsolationGetEnterpriseIdClose usage: https://github.com/microsoft/EnterpriseStateClassify

## Parameters

### `hOperation` [in]

The handle to release.

### `bWaitForOperation` [in]

Indicates whether to wait for synchronization.

## Return value

Returns ERROR_SUCCESS if successful, or an error value otherwise.