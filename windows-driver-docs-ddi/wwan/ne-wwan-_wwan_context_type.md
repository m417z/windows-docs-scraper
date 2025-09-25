# _WWAN_CONTEXT_TYPE enumeration

## Description

The WWAN_CONTEXT_TYPE enumeration lists the different types of connection contexts that are supported
by the MB device.

## Constants

### `WwanContextTypeNone`

The context is not yet provisioned.

### `WwanContextTypeInternet`

The context represents a connection to the Internet.

### `WwanContextTypeVpn`

The context represents a connection to virtual private network (VPN to a corporate
network).

### `WwanContextTypeVoice`

The context represents a connection to a Voice-over-IP (VOIP) service.

### `WwanContextTypeVideoShare`

The context represents a connection to a video sharing service.

### `WwanContextTypeCustom`

The context represents a connection to a custom service.

### `WwanContextTypePurchase`

Purchase a connection. For example, a walled garden, hot-lining or captive portal.

### `WwanContextTypeMms`

The context represents a connection for a multimedia message (MMS).

### `WwanContextTypeIms`

The context represents a connection for IP Multimedia Subsystem (IMS).

### `WwanContextTypeAdmin`

The context is used for administrative purposes such as device management.

### `WwanContextTypeApp`

The context represents a connection for certain applications allowlisted by mobile operators.

### `WwanContextTypeXcap`

The context is used for XCAP provisioning on IMS services.

### `WwanContextTypeTethering`

The context is used for mobile hotspot tethering.

### `WwanContextTypeEmergencyCall`

The context is used for IMS emergency calling.

### `WwanContextTypeLteAttach`

The context represents an attachment to LTE.

### `WwanContextTypeSupl`

### `WwanContextTypeMax`

The total number of supported context types.

## Remarks

This enumeration indicates the usage of the provisioned context. For example, whether the context is
used to connect to the Internet, or to a VPN into a corporate network. Miniport drivers should specify
**WwanContextTypeNone** for empty (unprovisioned) context slots.

## See also

[WWAN_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context)