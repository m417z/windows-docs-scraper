# NETISO_ERROR_TYPE enumeration

## Description

The **NETISO_ERROR_TYPE** enumerated type specifies the type of error related to a network isolation operation.

## Constants

### `NETISO_ERROR_TYPE_NONE:0x00`

No error.

### `NETISO_ERROR_TYPE_PRIVATE_NETWORK:0x01`

The failure was caused because the privateNetworkClientServer capability is missing.

### `NETISO_ERROR_TYPE_INTERNET_CLIENT:0x02`

The failure was caused because the internetClient capability is missing.

### `NETISO_ERROR_TYPE_INTERNET_CLIENT_SERVER:0x03`

The failure was caused because the internetClientServer capability is missing.

### `NETISO_ERROR_TYPE_MAX:0x04`

Maximum value for testing purposes.

## See also

[NetworkIsolationDiagnoseConnectFailureAndGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-networkisolationdiagnoseconnectfailureandgetinfo)