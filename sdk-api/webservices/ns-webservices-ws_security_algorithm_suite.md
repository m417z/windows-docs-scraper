# WS_SECURITY_ALGORITHM_SUITE structure

## Description

Defines the security algorithms and key lengths to be used with
WS-Security. This setting is relevant to message security bindings
and mixed-mode security bindings.

## Members

### `canonicalizationAlgorithm`

Algorithm to use for XML canonicalization, such as the exclusive XML
canonicalization algorithm.
Setting this value to [WS_SECURITY_ALGORITHM_DEFAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_algorithm_id) will default to
**WS_SECURITY_ALGORITHM_CANONICALIZATION_EXCLUSIVE**.

### `digestAlgorithm`

Algorithm to use for message part digests, such as SHA-1, SHA-256,
SHA-384, or SHA-512.
Setting this value to [WS_SECURITY_ALGORITHM_DEFAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_algorithm_id) will default to
**WS_SECURITY_ALGORITHM_DIGEST_SHA1**.

### `symmetricSignatureAlgorithm`

Algorithm to use for message authentication codes (also known as MACs
or symmetric signatures) such as HMAC-SHA1, HMAC-SHA256, HMAC-SHA384, or HMAC-SHA512.
Setting this value to [WS_SECURITY_ALGORITHM_DEFAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_algorithm_id) will default to
**WS_SECURITY_ALGORITHM_SYMMETRIC_SIGNATURE_HMAC_SHA1**.

### `asymmetricSignatureAlgorithm`

Algorithm to use for asymmetric signatures.
Setting this value to [WS_SECURITY_ALGORITHM_DEFAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_algorithm_id) will default to
**WS_SECURITY_ALGORITHM_ASYMMETRIC_SIGNATURE_RSA_SHA1**.

### `encryptionAlgorithm`

Algorithm to use for message part encryption. Reserved for future use. Should be set to [WS_SECURITY_ALGORITHM_DEFAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_algorithm_id).

### `keyDerivationAlgorithm`

Algorithm to use for deriving keys from other symmetric keys.
Setting this value to [WS_SECURITY_ALGORITHM_DEFAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_algorithm_id) will default to
**WS_SECURITY_ALGORITHM_KEY_DERIVATION_P_SHA1**.

### `symmetricKeyWrapAlgorithm`

Algorithm to use for encrypting symmetric keys with other symmetric
keys. Reserved for future use. Should be set to [WS_SECURITY_ALGORITHM_DEFAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_algorithm_id).

### `asymmetricKeyWrapAlgorithm`

Algorithm to use for encrypting symmetric keys with asymmetric
keys. Setting this value to [WS_SECURITY_ALGORITHM_DEFAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_algorithm_id) will default to
**WS_SECURITY_ALGORITHM_ASYMMETRIC_KEYWRAP_RSA_OAEP**.

### `minSymmetricKeyLength`

The minimum key length (in bits) of symmetric key security tokens.
Setting this value to 0 will default to 128 bits.

### `maxSymmetricKeyLength`

The maximum key length (in bits) of symmetric key security tokens.
Setting this value to 0 will default to 512 bits.

### `minAsymmetricKeyLength`

The minimum key length (in bits) of asymmetric key security tokens.
Setting this value to 0 will default to 1024 bits.

### `maxAsymmetricKeyLength`

The maximum key length (in bits) of asymmetric key security tokens.
Setting this value to 0 will default to 16384 bits.

### `properties`

Algorithm properties. Reserved for future use. Should be set to **NULL**.

### `propertyCount`

Number of entries in properties array. Reserved for future use. Should be set to 0.

## Remarks

When key derivation is used, the key length restrictions apply to the
source security token from which the signing or encryption derived
token are derived.