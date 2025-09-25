# _IPSEC_OFFLOAD_V2_ALGORITHM_INFO structure

## Description

[The IPsec Task Offload feature is deprecated and should not be used.]

The IPSEC_OFFLOAD_V2_ALGORITHM_INFO structure specifies an algorithm that is used for a security
association (SA).

## Members

### `Identifier`

The encryption or authentication algorithm that is used for the SA.

If the algorithm is an encryption algorithm,
**Identifier** can be any of the following values:

#### IPSEC_OFFLOAD_V2_ENCRYPTION_NONE

Specifies no confidentiality algorithm. This value is used for null encryption--that is, when a
packet is not encrypted but does include ESP authentication information.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_DES_CBC

Specifies the DES algorithm for encrypting and decrypting ESP payloads.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_3_DES_CBC

Specifies the triple-DES algorithm for encrypting and decrypting ESP payloads.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_128

Specifies the AES-GCM 128 algorithm for encrypting and computing a cryptographic checksum or
decrypting and validating a cryptographic checksum for an ESP payload. Note that this is a combined
mode algorithm.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_192

Specifies the AES-GCM 192 algorithm for encrypting and computing a cryptographic checksum or
decrypting and validating a cryptographic checksum for an ESP payload. Note that this is a combined
mode algorithm.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_256

Specifies the AES-GCM 256 algorithm for encrypting and computing a cryptographic checksum or
decrypting and validating a cryptographic checksum for an ESP payload. Note that this is a combined
mode algorithm.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_128

Specifies the Advanced Encryption Standard - cipher-block chaining mode (AES-CBC) 128 algorithm
for encrypting and decrypting ESP payloads.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_192

Specifies the AES-CBC 192 algorithm for encrypting and decrypting ESP payloads.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_256

Specifies the AES-CBC 256 algorithm for encrypting and decrypting ESP payloads.

If the algorithm is an authentication algorithm,
**Identifier** can be one of the following values:

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_MD5

Specifies the keyed message digest 5 (MD5) algorithm for computing or validating a cryptographic
checksum.

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_SHA_1

Specifies the secure hash algorithm (SHA) 1 algorithm for computing or validating a
cryptographic checksum.

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_SHA_256

Specifies the SHA 256 algorithm for computing or validating a cryptographic checksum.

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_128

Specifies the Advanced Encryption Standard - Galois/Counter Mode (AES- GMAC) 128 algorithm for
computing or validating a cryptographic checksum.

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_192

Specifies the AES- GMAC 192 algorithm for computing or validating a cryptographic
checksum.

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_256

Specifies the AES- GMAC 256 algorithm for computing or validating a cryptographic
checksum.

### `KeyLength`

The length, in bytes, of the key for the algorithm. The key is contained in the array at the
**KeyData** member in the
[IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_add_sa) structure.

**KeyLength** indicates the length of the cryptographic algorithm, starting at the offset that is
specified in
**KeyOffsetBytes** .

If both algorithms (
**AuthenticationAlgorithm** and
**EncryptionAlgorithm** ) are specified in IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION, the keys are
concatenated. The respective keys start at the offset that is specified in
**KeyOffsetBytes** .

### `KeyOffsetBytes`

The offset, in bytes, into in the array at the
**KeyData** member in the
[IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_add_sa) structure.

### `AdditionalInfo`

Additional information that should be interpreted differently based on the algorithm. For AES-GCM,
**AdditionalInfo** contains the ICV length.

## Remarks

The IPSEC_OFFLOAD_V2_ALGORITHM_INFO structure specifies algorithm information in the
**EncryptionAlgorithm** and
**AuthenticationAlgorithm** members of the
[IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_security_association) structure.

## See also

[IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_add_sa)

[IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_security_association)