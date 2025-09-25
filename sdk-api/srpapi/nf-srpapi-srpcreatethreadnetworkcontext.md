# SrpCreateThreadNetworkContext function

## Description

**Note** Windows Information Protection (WIP) policy can be applied on Windows 10, version 1607.

Sets the enterprise ID as the data context of the current thread. This is allowed only if the process already has the same enterprise ID present in its process context. It optionally returns the existing thread token.

## Parameters

### `enterpriseId` [in]

The enterprise ID to set in the current thread's token.

### `threadNetworkContext` [out]

On success, holds the existing thread token.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.