# _IPSEC_OFFLOAD_V2_OPERATION enumeration

## Description

[The IPsec Task Offload feature is deprecated and should not be used.]

The IPSEC_OFFLOAD_V2_OPERATION enumeration specifies the IPsec operation for which a security
association (SA) is used.

## Constants

### `IPsecOffloadV2Ah`

The SA is used for authentication (integrity checking).

### `IPsecOffloadV2Esp`

The SA is used for encryption/decryption (confidentiality).

### `IPsecOffloadV2Max`

Reserved for NDIS.

## Remarks

The IPSEC_OFFLOAD_V2_OPERATION enumeration specifies the operation for which an SA is used in the
**Operation** member of the
[IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_security_association) structure.

## See also

[IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_security_association)