## Description

Contains data for FIDO authentication.

## Members

### `cbHeaderLength`

The header length, in bytes.

### `cbStructureLength`

The length of the structure, in bytes.

### `Secret`

The secret. Offsets are from the beginning of this structure.

### `NewSecret`

The new secret.

### `EncryptedNewSecret`

The new secret, encrypted. For storage by cloud AP.

### `NetworkLogonBuffer`

Opaque data, which is understood by plugin. May contain signed Nonce and other data to perform a network logon.

### `ulSignatureCount`

The signature count to be stored in public cached information, required for CredProv.

## Remarks

## See also