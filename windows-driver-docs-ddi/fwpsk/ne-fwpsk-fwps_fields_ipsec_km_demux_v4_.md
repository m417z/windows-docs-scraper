# FWPS_FIELDS_IPSEC_KM_DEMUX_V4_ enumeration

## Description

The FWPS_FIELDS_IPSEC_KM_DEMUX_V4 enumeration type specifies the data field identifiers for the
FWPS_LAYER_IPSEC_KM_DEMUX_V4
[run-time filtering layer](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## Constants

### `FWPS_FIELD_IPSEC_KM_DEMUX_V4_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_IPSEC_KM_DEMUX_V4_IP_REMOTE_ADDRESS`

The remote IP address.

### `FWPS_FIELD_IPSEC_KM_DEMUX_V4_QM_MODE`

The quick mode (QM) mode.

**Note** Supported starting with Windows 8.

### `FWPS_FIELD_IPSEC_KM_DEMUX_V4_IP_LOCAL_INTERFACE`

The IP local interface.

**Note** Supported starting with Windows 8.

### `FWPS_FIELD_IPSEC_KM_DEMUX_V4_CURRENT_PROFILE_ID`

The profile identifier (network category) of the network interface. The possible network category values are: public (1), private (2), or domain (3).

**Note** Supported starting with Windows 8.

### `FWPS_FIELD_KM_DEMUX_V4_IPSEC_SECURITY_REALM_ID`

The IPsec security realm identifier.

**Note** Supported starting with Windows 10.

### `FWPS_FIELD_IPSEC_KM_DEMUX_V4_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.