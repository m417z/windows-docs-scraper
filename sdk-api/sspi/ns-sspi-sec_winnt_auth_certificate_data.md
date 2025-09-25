# SEC_WINNT_AUTH_CERTIFICATE_DATA structure

## Description

Specifies serialized certificate information.

## Members

### `cbHeaderLength`

The size, in bytes, of the structure header.

### `cbStructureLength`

The size, in bytes, of the certificate information.

### `Certificate`

A structure that specifies the offset from the beginning of this structure and the size, in bytes, of the certificate data.

## See also

[SEC_WINNT_AUTH_BYTE_VECTOR](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_byte_vector)