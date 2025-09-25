# CertResyncCertificateChainEngine function

## Description

Resyncs the certificate chain engine, which resynchronizes the stores the store's engine and updates the engine caches.

## Parameters

### `hChainEngine` [in, optional]

The chain engine to resynchronize.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).