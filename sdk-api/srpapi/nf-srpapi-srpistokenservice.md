# SrpIsTokenService function

## Description

**Note** Windows Information Protection (WIP) policy cannot be applied on Windows 10, version 1511 (build 10586) or earlier.

Identifies whether a service is a token service.

## Parameters

### `TokenHandle` [in]

Token Handle to be checked.

### `IsTokenService` [out]

A boolean value that indicates whether the service is a token service.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.