# ShutdownMSPCallHelper function

## Description

The
**ShutdownMSPCallHelper** helper template function is called in the derived class' implementation of
[ShutdownMSPCall](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-shutdownmspcall). It manipulates the passed-in aggregated TAPI call object Unknown pointer via dynamic casts to obtain a pointer to the inner MSP call object, and then calls the
[Shutdown](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-shutdown) method on the MSP call object (see below).

## Parameters

### `pUnknown`

Pointer to IUnknown on aggregated TAPI call object.

### `ppCMSPCall`

Pointer to templated MSP call class, type implementation dependent.

### `unnamedParam3`

TBD

## See also

[CMSPAddress](https://learn.microsoft.com/windows/desktop/api/mspaddr/nl-mspaddr-cmspaddress)