## Description

The **WPA_AKM_SUITE** enumeration defines Wi-Fi Protected Access (WPA) authentication and key management (AKM) suites.

## Constants

### `wpa_akm_none:(WPA_OUI_PREFIX,` 0)

No WPA AKM suite.

### `wpa_akm_1x:(WPA_OUI_PREFIX,` 1)

IEEE 802.1X authentication with a Pseudo-Random Function (PRF) of 128 bits.

### `wpa_akm_psk:(WPA_OUI_PREFIX,` 2)

Pre-Shared Key (PSK) authentication with a PRF of 128 bits.

### `wpa_akm_max:wpa_akm_psk`

The maximum range of the **WPA_AKM_SUITE** enum.

## Remarks

## See also

[**AKM_FROM_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/nf-windot11-akm_from_type)

[**RSNA_AKM_SUITE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-rsna_akm_suite)

[WiFiCx Wi-Fi 7 feature requirements](https://learn.microsoft.com/windows-hardware/drivers/netcx/wificx-wi-fi-7)