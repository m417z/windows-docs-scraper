# WLAN_SECURITY_ATTRIBUTES structure

## Description

The **WLAN_SECURITY_ATTRIBUTES** structure defines the security attributes for a wireless connection.

## Members

### `bSecurityEnabled`

Indicates whether security is enabled for this connection.

### `bOneXEnabled`

Indicates whether 802.1X is enabled for this connection.

### `dot11AuthAlgorithm`

A [DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-auth-algorithm) value that identifies the authentication algorithm.

### `dot11CipherAlgorithm`

A [DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-cipher-algorithm) value that identifies the cipher algorithm.

## See also

[WLAN_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_attributes)