# PKU2U_CREDUI_CONTEXT structure

## Description

Specifies a PKU2U client context.

## Members

### `Version`

The version number of the context. This must be **PKU2U_CREDUI_CONTEXT_VERSION**.

### `cbHeaderLength`

The size, in bytes, of this structure, not including the [PKU2U_CERT_BLOB](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-pku2u_cert_blob) structure that follows it.

### `cbStructureLength`

The size, in bytes, of this structure, including the [PKU2U_CERT_BLOB](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-pku2u_cert_blob) structure that follows it.

### `CertArrayCount`

The size, in bytes, of the [PKU2U_CERT_BLOB](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-pku2u_cert_blob) structure that follows this structure.

### `CertArrayOffset`

The number of bytes from the beginning of this structure in memory to the beginning of the [PKU2U_CERT_BLOB](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-pku2u_cert_blob) structure that follows this structure.