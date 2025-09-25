# CERT_EXTENSIONS structure

## Description

The **CERT_EXTENSIONS** structure contains an array of extensions.

## Members

### `cExtension`

Number of elements in the array **rgExtension**.

### `rgExtension`

Array of structures, each holding information of type [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) about a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) or [CRL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)