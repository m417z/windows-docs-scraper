## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_AUTH_ALGORITHM** enumeration defines the authentication algorithm values.

## Constants

### `WDI_AUTH_ALGO_UNKNOWN:0`

Specifies an unknown authentication algorithm.

### `WDI_AUTH_ALGO_80211_OPEN:1`

Specifies an IEEE 802.11 Open System authentication algorithm.

### `WDI_AUTH_ALGO_80211_SHARED_KEY:2`

Specifies an IEEE 802.11 Shared Key authentication algorithm that requires the use of a pre-shared Wired Equivalent Privacy (WEP) key for the 802.11 authentication.

### `WDI_AUTH_ALGO_WPA:3`

Specifies a Wi-Fi Protected Access (WPA) algorithm. IEEE 802.1X port authorization is performed by the supplicant, authenticator, and authentication server. Cipher keys are dynamically derived through the authentication process.

When the WPA algorithm is enabled, the 802.11 station only associates with an access point whose beacon or probe responses contain the authentication suite of type 1 (802.1X) within the WPA information element (IE).

### `WDI_AUTH_ALGO_WPA_PSK:4`

Specifies a Wi-Fi Protected Access (WPA) algorithm that uses preshared keys (PSK). IEEE 802.1X port authorization is performed by the supplicant and authenticator. Cipher keys are dynamically derived through a preshared key that is used on both the supplicant and authenticator.

When the WPA PSK algorithm is enabled, the 802.11 station only associates with an access point whose beacon or probe responses contain the authentication suite of type 2 (preshared key) within the WPA IE.

### `WDI_AUTH_ALGO_WPA_NONE:5`

This value is not supported.

### `WDI_AUTH_ALGO_RSNA:6`

Specifies an IEEE 802.11i Robust Security Network Association (RSNA) algorithm. IEEE 802.1X port authorization is performed by the supplicant, authenticator, and authentication server. Cipher keys are dynamically derived through the authentication process.

When the RSNA algorithm is enabled, the 802.11 station only associates with an access point whose beacon or probe responses contain the authentication suite of type 1 (802.1X) within the Robust Security Network (RSN) IE.

### `WDI_AUTH_ALGO_RSNA_PSK:7`

Specifies an IEEE 802.11i RSNA algorithm that uses PSK. IEEE 802.1X port authorization is performed by the supplicant and authenticator. Cipher keys are dynamically derived through a pre-shared key that is used on both the supplicant and authenticator.

When the RSNA PSK algorithm is enabled, the 802.11 station only associates with an access point whose beacon or probe responses contain the authentication suite of type 2 (preshared key) within the RSN IE.

### `WDI_AUTH_ALGO_WPA3_ENT_192:8`

Specifies a WPA3-Enterprise 192-bit mode algorithm.

### `WDI_AUTH_ALGO_WPA3_SAE:9`

Specifies a WPA3-Simultaneous Authentication of Equals (WPA3-SAE) algorithm.

### `WDI_AUTH_ALGO_OWE:10`

Specifies an opportunistic wireless encryption (OWE) algorithm.

### `WDI_AUTH_ALGO_WPA3_ENT:11`

Specifies a WPA3-Enterprise algorithm.

### `WDI_AUTH_ALGO_IHV_START:0x80000000`

Specifies the start of the range that specifies proprietary authentication algorithms that are developed by an IHV.

### `WDI_AUTH_ALGO_IHV_END:0xffffffff`

Specifies the end of the range that specifies proprietary authentication algorithms that are developed by an IHV.

## Remarks

## See also

[**WDI_TLV_UNICAST_ALGORITHM_LIST**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-unicast-algorithm-list)

[**WDI_TLV_AUTH_ALGO_LIST**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-auth-algo-list)

[**WDI_TLV_ASSOCIATION_RESULT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-association-result-parameters)

[**WDI_TLV_ASSOCIATION_RESPONSE_RESULT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-association-response-result-parameters)