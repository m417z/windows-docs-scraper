# PstAcquirePrivateKey function

## Description

Associates the caller's [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) with the specified [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `pCert` [in]

The certificate with which to associate the private key.

## Return value

If the function succeeds, return **STATUS_SUCCESS**.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.