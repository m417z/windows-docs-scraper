## Description

Specifies the data field identifiers for the [FWPS_LAYER_KM_AUTHORIZATION](https://learn.microsoft.com/windows/win32/api/fwpsu/ne-fwpsu-fwps_builtin_layers) run-time filtering layer.

## Constants

### `FWPS_FIELD_KM_AUTHORIZATION_REMOTE_ID`

The peer's identifier. This can be the User or Machine Token depending on the type, auth type, and
mode.

### `FWPS_FIELD_KM_AUTHORIZATION_AUTHENTICATION_TYPE`

The type of authentication used.

### `FWPS_FIELD_KM_AUTHORIZATION_KM_TYPE`

The type of Keying Module (KM) used.

### `FWPS_FIELD_KM_AUTHORIZATION_DIRECTION`

The possible values are **FWP_DIRECTION_INBOUND** and **FWP_DIRECTION_OUTBOUND**.

### `FWPS_FIELD_KM_AUTHORIZATION_KM_MODE`

The authorization mode.

### `FWPS_FIELD_KM_AUTHORIZATION_IPSEC_POLICY_KEY`

The associated IPsec policy key.

### `FWPS_FIELD_KM_AUTHORIZATION_NAP_CONTEXT`

The Network Access Protection (NAP) certificate context.

### `FWPS_FIELD_KM_AUTHORIZATION_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

## See also