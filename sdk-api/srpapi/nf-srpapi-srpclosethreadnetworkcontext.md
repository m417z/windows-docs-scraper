# SrpCloseThreadNetworkContext function

## Description

**Note** Windows Information Protection (WIP) policy can be applied on Windows 10, version 1607.

Restores a thread back to the original context, which may have been optionally returned from [SrpCreateThreadNetworkContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/srpapi/nf-srpapi-srpcreatethreadnetworkcontext).

## Parameters

### `threadNetworkContext` [in, out]

A handle to the original context’s token.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.