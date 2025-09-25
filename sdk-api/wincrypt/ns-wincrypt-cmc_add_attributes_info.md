# CMC_ADD_ATTRIBUTES_INFO structure

## Description

The **CMC_ADD_ATTRIBUTES_INFO** structure contains certificate attributes to be added to a certificate.

## Members

### `dwCmcDataReference`

**DWORD** data reference number.

### `cCertReference`

Count of elements in the **rgdwCertReference** array.

### `rgdwCertReference`

Array of certificate reference numbers.

### `cAttribute`

Count of the elements in the **rgAttribute** array.

### `rgAttribute`

Array of pointers to the
[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) certificate attributes to be added.