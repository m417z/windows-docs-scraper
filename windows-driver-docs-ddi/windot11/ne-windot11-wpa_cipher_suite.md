## Description

The **WPA_CIPHER_SUITE** enumeration defines Wi-Fi Protected Access (WPA) cipher suites.

## Constants

### `wpa_cipher_none:CIPHER_FROM_TYPE(WPA_OUI_PREFIX,` 0)

No cipher suite.

### `wpa_cipher_wep40:CIPHER_FROM_TYPE(WPA_OUI_PREFIX,` 1)

WEP-40 (Wired Equivalent Privacy).

### `wpa_cipher_tkip:CIPHER_FROM_TYPE(WPA_OUI_PREFIX,` 2)

TKIP (Temporal Key Integrity Protocol).

### `wpa_cipher_ccmp_128:CIPHER_FROM_TYPE(WPA_OUI_PREFIX,` 4)

CCMP-128 (Counter Mode Cipher Block Chaining Message Authentication Code Protocol).

### `wpa_cipher_wep104:CIPHER_FROM_TYPE(WPA_OUI_PREFIX,` 5)

WEP-104.

### `wpa_cipher_bip_cmac_128:CIPHER_FROM_TYPE(WPA_OUI_PREFIX,` 6)

BIP-CMAC-128 (Broadcast Integrity Protocol Cipher-based Message Authentication Code).

### `wpa_cipher_max:wpa_cipher_bip_cmac_128`

The maximum range of the **WPA_CIPHER_SUITE** enumeration.

## Remarks

## See also

[**RSNA_CIPHER_SUITE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-rsna_cipher_suite)

[WiFiCx Wi-Fi 7 feature requirements](https://learn.microsoft.com/windows-hardware/drivers/netcx/wificx-wi-fi-7)