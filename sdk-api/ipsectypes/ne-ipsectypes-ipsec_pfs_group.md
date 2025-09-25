# IPSEC_PFS_GROUP enumeration

## Description

The **IPSEC_PFS_GROUP** enumerated type specifies the Diffie Hellman algorithm that should be used for
Quick Mode PFS (Perfect Forward Secrecy).

## Constants

### `IPSEC_PFS_NONE:0`

Specifies no Quick Mode PFS.

### `IPSEC_PFS_1`

Specifies Diffie Hellman group 1.

### `IPSEC_PFS_2`

Specifies Diffie Hellman group 2.

### `IPSEC_PFS_2048`

Specifies Diffie Hellman group 14.

### `IPSEC_PFS_14`

Specifies Diffie Hellman group 14.

**Note** This group was called Diffie Hellman group 2048 when it was introduced. The name has since been changed to match standard terminology.

**Note** Available only for Windows 8 and Windows Server 2012.

### `IPSEC_PFS_ECP_256`

Specifies Diffie Hellman ECP group 256.

### `IPSEC_PFS_ECP_384`

Specifies Diffie Hellman ECP group 384.

### `IPSEC_PFS_MM`

Use the same Diffie Hellman as the main mode that contains this quick mode.

### `IPSEC_PFS_24`

Specifies Diffie Hellman group 24.

**Note** Available only for Windows 8 and Windows Server 2012.

### `IPSEC_PFS_MAX`

Maximum value for testing only.

## See also

[WFP Enumerated Types](https://learn.microsoft.com/windows/desktop/FWP/fwp-enums)