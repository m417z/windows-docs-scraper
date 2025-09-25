# SrpGetEnterprisePolicy function

## Description

**Note** Windows Information Protection (WIP) policy can be applied on Windows 10, version 1607.

Gets information about the enterprise policy of an app.

## Parameters

### `tokenHandle` [in]

Token Handle to be checked.

### `policyFlags` [out]

A collection of flags that indicate among other things whether the host app is allowed by the managing enterprise policy, and has been enlightened for Windows Information Protection.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.