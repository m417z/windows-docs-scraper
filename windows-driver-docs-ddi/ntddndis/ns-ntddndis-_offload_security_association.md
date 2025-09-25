# _OFFLOAD_SECURITY_ASSOCIATION structure

## Description

The OFFLOAD_SECURITY_ASSOCIATION structure specifies a single security association (SA).

## Members

### `Operation`

The Internet Protocol security (IPsec) operation for which the SA is to be used. The following
operations are supported:

#### AUTHENTICATE

The SA will be used for authentication (integrity checking).

#### ENCRYPT

The SA will be used for encryption/decryption (confidentiality).

### `SPI`

The Security Parameters Index (SPI) for the SA.

### `IntegrityAlgo`

The integrity (authentication) algorithm for the SA, formatted as an
[OFFLOAD_ALGO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_algo_info) structure.

### `ConfAlgo`

The confidentiality (encryption/decryption) algorithm for the SA, formatted as an
OFFLOAD_ALGO_INFO structure.

### `Reserved`

This member is reserved.

## Remarks

The OFFLOAD_SECURITY_ASSOCIATION structure is used with the
[OID_TCP_TASK_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-sa) and
[OID_TCP_TASK_IPSEC_ADD_UDPESP_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-udpesp-sa) OIDs.

## See also

[OFFLOAD_ALGO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_algo_info)

[OID_TCP_TASK_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-sa)

[OID_TCP_TASK_IPSEC_ADD_UDPESP_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-udpesp-sa)