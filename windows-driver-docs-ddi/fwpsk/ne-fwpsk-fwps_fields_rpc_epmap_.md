# FWPS_FIELDS_RPC_EPMAP_ enumeration

## Description

The FWPS_FIELDS_RPC_EPMAP enumeration type specifies the data field identifiers for the
FWPS_LAYER_RPC_EPMAP
[run-time filtering layer](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## Constants

### `FWPS_FIELD_RPC_EPMAP_REMOTE_USER_TOKEN`

The identification of the remote user.

### `FWPS_FIELD_RPC_EPMAP_IF_UUID`

The UUID of the RPC interface.

### `FWPS_FIELD_RPC_EPMAP_IF_VERSION`

The version of the RPC interface.

### `FWPS_FIELD_RPC_EPMAP_PROTOCOL`

The possible condition values are:

* RPC_PROTSEQ_TCP
* RPC_PROTSEQ_HTTP
* RPC_PROTSEQ_NMP

### `FWPS_FIELD_RPC_EPMAP_AUTH_TYPE`

The authentication service type. For more information about authentication service types, see
Authentication-Service Constants in the RPC section of the Microsoft Windows SDK documentation.

### `FWPS_FIELD_RPC_EPMAP_AUTH_LEVEL`

The authentication service level. For more information about authentication service levels, see
Authentication-Service Constants in the RPC section of the Windows SDK documentation.

### `FWPS_FIELD_RPC_EPMAP_SEC_ENCRYPT_ALGORITHM`

The certificate-based security service provider interface (SSPI) encryption algorithm.

### `FWPS_FIELD_RPC_EPMAP_SEC_KEY_SIZE`

The certificate-based SSPI encryption key size.

### `FWPS_FIELD_RPC_EPMAP_LOCAL_ADDR_V4`

The local IPv4 address.

### `FWPS_FIELD_RPC_EPMAP_LOCAL_ADDR_V6`

The local IPv6 address.

### `FWPS_FIELD_RPC_EPMAP_LOCAL_PORT`

The local transport protocol port number.

### `FWPS_FIELD_RPC_EPMAP_PIPE`

The name of the remote named pipe.

### `FWPS_FIELD_RPC_EPMAP_REMOTE_ADDR_V4`

The remote IPv4 address.

### `FWPS_FIELD_RPC_EPMAP_REMOTE_ADDR_V6`

The remote IPv6 address.

### `FWPS_FIELD_RPC_EPMAP_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.