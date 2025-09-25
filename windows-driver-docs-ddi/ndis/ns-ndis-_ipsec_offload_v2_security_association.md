# _IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION structure

## Description

[The IPsec Task Offload feature is deprecated and should not be used.]

The IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION structure specifies a single security association
(SA).

## Members

### `Flags`

A set of flags that can be combined with a bitwise OR operation. Otherwise, set this member to
zero. The following values are valid:

#### IPSEC_OFFLOAD_V2_ESN_SA

Specifies ESN SA.

### `Operation`

The IPsec operation for which the SA is to be used. The
[IPSEC_OFFLOAD_V2_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-_ipsec_offload_v2_operation) enumeration defines the supported operations.

### `Spi`

A 32 bit security parameters index (SPI) for the SA.

### `AuthenticationAlgorithm`

The integrity (authentication) algorithm for the SA, formatted as an
[IPSEC_OFFLOAD_V2_ALGORITHM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_algorithm_info) structure.

### `EncryptionAlgorithm`

The confidentiality (encryption/decryption) algorithm for the SA, formatted as an
IPSEC_OFFLOAD_V2_ALGORITHM_INFO structure.

**Note** For AES-GCM, the
**EncryptionAlgorithm** member contains the key information. The
**AuthenticationAlgorithm** member of IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION, and the key length and
offset in IPSEC_OFFLOAD_V2_ALGORITHM_INFO, should not be used.

### `SequenceNumberHighOrder`

The sequence number high-order extension. This sequence number high-order extension is defined in
RFC 4304. This member represents the high-order portion of the sequence number that is not included in
the IPsec header.

## Remarks

The IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION structure is an element in the
**SecAssoc** variable-length array in the
[IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_add_sa) structure.
The number of SAs in the IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION structure is specified in the
**NumExtHdrs** member of IPSEC_OFFLOAD_V2_ADD_SA.

A
**SecAssoc** element that is specified for use in processing authentication headers (AH) will have an
operation type (the
**Operation** member) of
**IPsecOffloadV2Ah** and will have the authentication algorithm in the
**AuthenticationAlgorithm** member. The SA will not have an encryption algorithm in the
**EncryptionAlgorithm** member, so
**EncryptionAlgorithm** will contain zeros.

**Note** For AES-GCM, the
**EncryptionAlgorithm** member contains the key information. The
**AuthenticationAlgorithm** member of IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION, and the key length and
offset in IPSEC_OFFLOAD_V2_ALGORITHM_INFO, should not be used.

A
**SecAssoc** element that is specified for use in processing encapsulating security payloads (ESPs)
will have an operation type (the
**Operation** member) of
**IPsecOffloadV2Esp** and can have an authentication algorithm, an encryption algorithm, or both. Note
that for combined mode algorithms, only the
**EncryptionAlgorithm** member will be specified.

## See also

[IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_add_sa)

[IPSEC_OFFLOAD_V2_ALGORITHM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_algorithm_info)

[IPSEC_OFFLOAD_V2_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-_ipsec_offload_v2_operation)