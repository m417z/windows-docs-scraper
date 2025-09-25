# WS_RAW_SYMMETRIC_SECURITY_KEY_HANDLE structure

## Description

The type for specifying a symmetric cryptographic key as raw bytes.

## Members

### `keyHandle`

The base type from which this type and all other key handle types derive.

### `rawKeyBytes`

The cryptographic key as raw bytes. It is strongly recommended that
after the key is supplied in this form to any API, it is immediately
cleared using SecureZeroMemory.