# WCN_VALUE_TYPE_AUTHENTICATION_TYPE enumeration

## Description

The **WCN_VALUE_TYPE_AUTHENTICATION_TYPE** enumeration defines the authentication types supported by the Enrollee (access point or station).

## Constants

### `WCN_VALUE_AT_OPEN:0x1`

Specifies IEEE 802.11 Open System authentication.

### `WCN_VALUE_AT_WPAPSK:0x2`

Specifies WPA security. Authentication is performed between the supplicant and authenticator over IEEE 802.1X. Encryption keys are dynamic and are derived through the preshared key used by the supplicant and authenticator.

**Note** Not supported in WPS 2.0.

### `WCN_VALUE_AT_SHARED:0x4`

Specifies IEEE 802.11 Shared Key authentication that uses a preshared WEP key.

**Note** Not supported in WPS 2.0.

### `WCN_VALUE_AT_WPA:0x8`

Specifies WPA security. Authentication is performed between the supplicant, authenticator, and authentication server over IEEE 802.1X. Encryption keys are dynamic and are derived through the authentication process.

**Note** Not supported by most access points, consider WPA2PSK authentication instead.

**Note** Not supported in WPS 2.0.

### `WCN_VALUE_AT_WPA2:0x10`

Specifies WPA2 security. Authentication is performed between the supplicant, authenticator, and authentication server over IEEE 802.1X. Encryption keys are dynamic and are derived through the authentication process.

**Note** Not supported by most access points, consider WPA2PSK authentication instead.

### `WCN_VALUE_AT_WPA2PSK:0x20`

Specifies WPA2 security. Authentication is performed between the supplicant and authenticator over IEEE 802 1X. Encryption keys are dynamic and are derived through the preshared key used by the supplicant and authenticator.

### `WCN_VALUE_AT_WPAWPA2PSK_MIXED:0x22`

Specifies WPAPSK/WPA2PSK mixed-mode encryption.

**Note** Available starting in Windows 8.1.

## See also

[WCN_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/wcntypes/ne-wcntypes-wcn_attribute_type)