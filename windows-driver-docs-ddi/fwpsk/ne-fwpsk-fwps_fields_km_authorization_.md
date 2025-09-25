# FWPS_FIELDS_KM_AUTHORIZATION_ enumeration

## Description

The FWPS_FIELDS_KM_AUTHORIZATION enumeration type specifies the data field identifiers for the
FWPS_LAYER_KM_AUTHORIZATION
[run-time filtering layer](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## Constants

### `FWPS_FIELD_KM_AUTHORIZATION_REMOTE_ID`

The peer's identifier. This can be the User or Machine Token depending on the type, auth type, and
mode.

### `FWPS_FIELD_KM_AUTHORIZATION_AUTHENTICATION_TYPE`

The type of authentication used.

### `FWPS_FIELD_KM_AUTHORIZATION_KM_TYPE`

The type of Keying Module (KM) used.

### `FWPS_FIELD_KM_AUTHORIZATION_DIRECTION`

The possible values are:

* FWP_DIRECTION_INBOUND
* FWP_DIRECTION_OUTBOUND

### `FWPS_FIELD_KM_AUTHORIZATION_KM_MODE`

The authorization mode.

### `FWPS_FIELD_KM_AUTHORIZATION_IPSEC_POLICY_KEY`

The associated IPsec policy key.

### `FWPS_FIELD_KM_AUTHORIZATION_NAP_CONTEXT`

The Network Access Protection (NAP) certificate context.

### `FWPS_FIELD_KM_AUTHORIZATION_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.