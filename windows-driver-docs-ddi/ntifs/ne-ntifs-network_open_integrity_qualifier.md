# NETWORK_OPEN_INTEGRITY_QUALIFIER enumeration

## Description

The NETWORK_OPEN_INTEGRITY_QUALIFIER enumeration type contains values that identify the kind of integrity restriction to attach to a file.

## Constants

### `NetworkOpenIntegrityAny`

Indicates that the file has no integrity restrictions. That is, the file has no restrictions about how to sign, encrypt, and so on.

### `NetworkOpenIntegrityNone`

Indicates that the file is not signed or encrypted.

### `NetworkOpenIntegritySigned`

Indicates that the file is signed end-to-end.

### `NetworkOpenIntegrityEncrypted`

Indicates that the file is encrypted end-to-end.

### `NetworkOpenIntegrityMaximum`

Indicates that the file has the best integrity that is available.