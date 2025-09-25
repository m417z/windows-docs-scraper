## Description

Specifies the data field identifiers for the [FWPS_LAYER_RPC_UM](https://learn.microsoft.com/windows/win32/api/fwpsu/ne-fwpsu-fwps_builtin_layers) run-time filtering layer.

## Constants

### `FWPS_FIELD_RPC_UM_REMOTE_USER_TOKEN`

The identification of the remote user.

### `FWPS_FIELD_RPC_UM_IF_UUID`

The UUID of the RPC interface.

### `FWPS_FIELD_RPC_UM_IF_VERSION`

The version of the RPC interface.

### `FWPS_FIELD_RPC_UM_IF_FLAG`

Reserved for internal use.

### `FWPS_FIELD_RPC_UM_DCOM_APP_ID`

The identification of the COM application.

### `FWPS_FIELD_RPC_UM_IMAGE_NAME`

The name of the application.

### `FWPS_FIELD_RPC_UM_PROTOCOL`

The possible condition values are **RPC_PROTSEQ_TCP**, **RPC_PROTSEQ_HTTP**, and **RPC_PROTSEQ_NMP**.

### `FWPS_FIELD_RPC_UM_AUTH_TYPE`

The authentication service type. For more information about authentication service types, see
Authentication-Service Constants in the RPC section of the Microsoft Windows SDK documentation.

### `FWPS_FIELD_RPC_UM_AUTH_LEVEL`

The authentication service level. For more information about authentication service levels, see
Authentication-Service Constants in the RPC section of the Windows SDK documentation.

### `FWPS_FIELD_RPC_UM_SEC_ENCRYPT_ALGORITHM`

The certificate-based security service provider interface (SSPI) encryption algorithm.

### `FWPS_FIELD_RPC_UM_SEC_KEY_SIZE`

The certificate-based SSPI encryption key size.

### `FWPS_FIELD_RPC_UM_LOCAL_ADDR_V4`

The local IPv4 address.

### `FWPS_FIELD_RPC_UM_LOCAL_ADDR_V6`

The local IPv6 address.

### `FWPS_FIELD_RPC_UM_LOCAL_PORT`

The local transport protocol port number.

### `FWPS_FIELD_RPC_UM_PIPE`

The name of the remote named pipe.

### `FWPS_FIELD_RPC_UM_REMOTE_ADDR_V4`

The remote IPv4 address.

### `FWPS_FIELD_RPC_UM_REMOTE_ADDR_V6`

The remote IPv6 address. The IPv6 address of the RPC client.

### `FWPS_FIELD_RPC_UM_RPC_OPNUM`

The operation number of the RPC call.

### `FWPS_FIELD_RPC_UM_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

## See also