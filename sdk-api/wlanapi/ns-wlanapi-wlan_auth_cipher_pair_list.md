# WLAN_AUTH_CIPHER_PAIR_LIST structure

## Description

The **WLAN_AUTH_CIPHER_PAIR_LIST** structure contains a list of authentication and cipher algorithm pairs.

## Members

### `dwNumberOfItems`

Contains the number of supported auth-cipher pairs.

### `pAuthCipherPairList.unique`

### `pAuthCipherPairList.size_is`

### `pAuthCipherPairList.size_is.dwNumberOfItems`

### `pAuthCipherPairList`

A [DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-auth-cipher-pair) structure containing a list of auth-cipher pairs.

## See also

[WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface)