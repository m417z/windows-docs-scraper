# SecPkgContext_KeyingMaterial structure

## Description

The **SecPkgContext_KeyingMaterial** structure specifies the exportable keying material for the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Members

### `cbKeyingMaterial`

The length, in bytes, of the keying material to be exported. Must be greater than zero.

### `pbKeyingMaterial`

A pointer to the buffer containing the exported keying material. After use, deallocate the buffer by calling [FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer).