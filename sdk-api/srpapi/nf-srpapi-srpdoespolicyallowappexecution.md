# SrpDoesPolicyAllowAppExecution function

## Description

**Note** Windows Information Protection (WIP) policy can be applied on Windows 10, version 1607.

Evaluates whether a packaged app will be allowed to execute based on software restriction policies.

## Parameters

### `packageId` [in]

Provides package name, publisher name, and version of the packaged app.

### `isAllowed` [out]

A boolean value that indicates whether the app is allowed to execute.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.