# IKE_AUTHENTICATION_PRESHARED_KEY structure

## Description

The **IKE_AUTHENTICATION_PRESHARED_KEY** structure contains information about the preshared key used in the Internet Key Exchange (IKE) protocol.

## Members

### `SecurityFlags`

A bitmap that defines the security characteristics of a login connection.

| Value | Meaning |
| --- | --- |
| **ISCSI_SECURITY_FLAG_TUNNEL_MODE_PREFERRED** | The Host Bus Adapter (HBA) initiator should establish the TCP/IP connection to the target portal using IPsec tunnel mode. |
| **ISCSI_SECURITY_FLAG_TRANSPORT_MODE_PREFERRED** | The HBA initiator should establish the TCP/IP connection to the target portal using IPsec transport mode. |
| **ISCSI_SECURITY_FLAG_PFS_ENABLED** | The HBA initiator should establish the TCP/IP connection to the target portal with Perfect Forward Secrecy (PFS) mode enabled if IPsec is required. |
| **ISCSI_SECURITY_FLAG_AGGRESSIVE_MODE_ENABLED** | The HBA initiator should establish the TCP/IP connection to the target portal with aggressive mode enabled. |
| **ISCSI_SECURITY_FLAG_MAIN_MODE_ENABLED** | The HBA initiator should establish the TCP/IP connection to the target portal with main mode enabled. |
| **ISCSI_SECURITY_FLAG_IKE_IPSEC_ENABLED** | The HBA initiator should establish the TCP/IP connection to the target portal using IKE/IPsec protocol. If not set then IPsec is not required to login to the target. |
| **ISCSI_SECURITY_FLAG_VALID** | The other mask values are valid; otherwise, security flags are not specified. |

### `IdType`

The type of key identifier. The following table specifies the values that can be assigned to this member:

| ID Types | Meaning |
| --- | --- |
| **ID_IPV4_ADDR** | Indicates four bytes of binary data that constitute a version 4 IP address. |
| **ID_FQDN** | An ANSI string that contains a fully qualified domain name. This string does not contain terminators. |
| **ID_USER_FQDN** | An ANSI string that contains a fully qualified user name. This string does not contain terminators. |
| **ID_IPV6_ADDR** | Indicates 16 bytes of binary data that constitute a version 6 IP address. |

### `IdLengthInBytes`

The length, in bytes, of the key identifier.

### `Id`

The identifier of the preshared key used in the IKE protocol.

### `KeyLengthInBytes`

The length, in bytes, of the preshared key.

### `Key`

The preshared key.