# CMC_ADD_EXTENSIONS_INFO structure

## Description

The **CMC_ADD_EXTENSIONS_INFO** structure contains certificate extension control attributes to be added to a certificate.

## Members

### `dwCmcDataReference`

**DWORD** data reference number.

### `cCertReference`

**DWORD** count of elements in the **rgdwCertReference** array.

### `rgdwCertReference`

Array of certificate reference numbers.

### `cExtension`

**DWORD** count of the elements in the **rgExtension** array.

### `rgExtension`

Array of pointers to the
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) certificate extensions to be added.