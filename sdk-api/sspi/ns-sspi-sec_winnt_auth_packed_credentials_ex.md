# SEC_WINNT_AUTH_PACKED_CREDENTIALS_EX structure

## Description

Specifies serialized credentials and a list of security packages that support the credentials.

## Members

### `cbHeaderLength`

The size, in bytes, of the structure header.

### `Flags`

This member is reserved. Do not use it.

### `PackedCredentials`

The offset and size of the serialized credentials in this structure.

### `PackageList`

The offset and size of the list of security packages in this structure.