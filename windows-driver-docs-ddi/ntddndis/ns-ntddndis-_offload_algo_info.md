# _OFFLOAD_ALGO_INFO structure

## Description

The OFFLOAD_ALGO_INFO structure specifies an algorithm used for a security association (SA).

## Members

### `algoIdentifier`

The confidentiality or integrity algorithm used for the SA.

If the algorithm is a confidentiality algorithm (that is, if the OFFLOAD_ALGO_INFO structure is
specifying a
**ConfAlgo**),
**algoIdentifier** can be any of the following values:

#### OFFLOAD_IPSEC_CONF_NONE

Specifies no confidentiality algorithm. Used for null encryption--that is, when a packet is not
encrypted but its ESP header contains authentication information.

#### OFFLOAD_IPSEC_CONF_DES

Specifies the DES algorithm.

#### OFFLOAD_IPSEC_CONF_3_DES

Specifies the triple-DES algorithm.

If the algorithm is an integrity algorithm (that is, if the OFFLOAD_ALGO_INFO structure is specifying
an
**IntegrityAlgo**),
**algoIdentifier** can be one of the following values:

#### OFFLOAD_IPSEC_INTEGRITY_NONE

Specifies no integrity algorithm. Used when the ESP header contains no authentication
information.

#### OFFLOAD_IPSEC_INTEGRITY_MD5

Specifies the keyed MD5 algorithm.

#### OFFLOAD_IPSEC_INTEGRITY_SHA

Specifies the SHA 1 algorithm.

### `algoKeylen`

The length, in bytes, of the key for the algorithm. The key is contained in the buffer at
**KeyMat**Â¸ which is the variable-length array specified in the
[OFFLOAD_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_ipsec_add_sa) structure.

If only an integrity algorithm (
**IntegrityAlgo**) is specified in the
[OFFLOAD_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_security_association) structure,
**algoKeylen** indicates the length of the key for the integrity algorithm,
starting from the beginning of the buffer at
**KeyMat**.

If both an integrity and a confidentiality algorithm (
**IntegrityAlgo** and
**ConfAlgo**) are specified,
**algoKeylen** for the integrity algorithm indicates the length of the key for
the integrity algorithm, starting from the beginning of the buffer at
**KeyMat**. The
**algoKeylen** for the confidentiality algorithm, in this case, indicates the
length of the key for the confidentiality algorithm, starting the from the end of the key for the
integrity algorithm.

### `algoRounds`

The number of transformation rounds that the encryption algorithm performs.

**Note** This member is only used for
[IPsec Offload Version 1](https://learn.microsoft.com/windows-hardware/drivers/network/ipsec-offload-version-1).

## Remarks

The OFFLOAD_ALGO_INFO structure specifies algorithm information in the
**IntegrityAlgo**,
**ConfAlgo**, and
**Reserved** members of the
[OFFLOAD_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_security_association) structure.

## See also

[OFFLOAD_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_ipsec_add_sa)

[OFFLOAD_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_security_association)