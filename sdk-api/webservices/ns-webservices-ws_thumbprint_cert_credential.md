# WS_THUMBPRINT_CERT_CREDENTIAL structure

## Description

The type for specifying a certificate credential using the
certificate's thumbprint, store location and store name. The
specified credential is loaded when the containing channel or listener
is opened.

The thumbprint is the best option for specifying a certificate when
subject name based specification is expected to be ambiguous due to
the presence of multiple certificates with matching subject names in
the cert store being specified.

## Members

### `credential`

The base type from which this type and all other certificate credential types derive.

### `storeLocation`

The certificate store location (such as CERT_SYSTEM_STORE_CURRENT_USER
or CERT_SYSTEM_STORE_LOCAL_MACHINE) that contains the specified
certificate.

### `storeName`

The certificate store name (such as "My") that contains the specified
certificate.

### `thumbprint`

The SHA-1 thumbprint (such as
"c0f89c8d4e4e80f250b58c3fae944a0edee02804") of the specified
certificate. The supplied value should be a hexadecimal string
without whitespace characters or a leading 0x. A tool such as
certmgr.exe may be used to find the thumbprint of a certificate.