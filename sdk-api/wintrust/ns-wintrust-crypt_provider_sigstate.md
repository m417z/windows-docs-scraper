# CRYPT_PROVIDER_SIGSTATE structure

## Description

The **CRYPT_PROVIDER_SIGSTATE** structure is used to communicate between policy providers and Wintrust.

## Members

### `cbStruct`

Size, in bytes, of this structure.

### `rhSecondarySigs`

Pointer to an array of secondary signature handles.

### `hPrimarySig`

Handle of the primary signature.

### `fFirstAttemptMade`

Specifies whether the first attempt to verify a signature has been made.

### `fNoMoreSigs`

Specifies whether there exist further signatures that await verification.

### `cSecondarySigs`

Number of secondary signatures.

### `dwCurrentIndex`

Index of the signature currently being verified.

### `fSupportMultiSig`

Specifies whether the policy provider supports multiple signatures.

### `dwCryptoPolicySupport`

Identifies the portion of the policy provider that supports cryptographic policy. This can be one of the following values:

* WSS_OBJTRUST_SUPPORT
* WSS_SIGTRUST_SUPPORT
* WSS_CERTTRUST_SUPPORT

### `iAttemptCount`

### `fCheckedSealing`

### `pSealingSignature`

## See also

[WINTRUST_SIGNATURE_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_signature_settings)