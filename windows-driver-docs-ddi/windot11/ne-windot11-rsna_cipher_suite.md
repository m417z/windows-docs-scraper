## Description

The **RSNA_CIPHER_SUITE** enumeration defines Robust Security Network Association (RSNA) cipher suites.

## Constants

### `rsna_cipher_group:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 0)

The default group cipher suite for the RSNA protocol.

### `rsna_cipher_wep40:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 1)

WEP-40 (Wired Equivalent Privacy).

### `rsna_cipher_tkip:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 2)

TKIP (Temporal Key Integrity Protocol).

### `rsna_cipher_reserved:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 3)

Reserved.

### `rsna_cipher_ccmp_128:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 4)

CCMP-128 (Counter Mode Cipher Block Chaining Message Authentication Code Protocol).

### `rsna_cipher_wep104:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 5)

WEP-104.

### `rsna_cipher_bip_cmac_128:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 6)

BIP-CMAC-128 (Broadcast Integrity Protocol Cipher-based Message Authentication Code).

### `rsna_cipher_no_group_traffic:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 7)

No group traffic is allowed.

### `rsna_cipher_gcmp_128:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 8)

GCMP-128 (Galois/Counter Mode Protocol).

### `rsna_cipher_gcmp_256:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 9)

GCMP-256.

### `rsna_cipher_ccmp_256:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 10)

CCMP-256.

### `rsna_cipher_bip_gmac_128:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 11)

BIP-GMAC-128 (Broadcast Integrity Protocol Galois Message Authentication Code).

### `rsna_cipher_bip_gmac_256:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 12)

BIP-GMAC-256.

### `rsna_cipher_bip_cmac_256:CIPHER_FROM_TYPE(RSNA_OUI_PREFIX,` 13)

BIP-CMAC-256.

### `rsna_cipher_max:rsna_cipher_bip_cmac_256`

The maximum range of the **RSNA_CIPHER_SUITE** enum.

## Remarks

## See also

[**RSNA_AKM_CIPHER_PAIR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-rsna_akm_cipher_pair)

[WiFiCx Wi-Fi 7 feature requirements](https://learn.microsoft.com/windows-hardware/drivers/netcx/wificx-wi-fi-7)