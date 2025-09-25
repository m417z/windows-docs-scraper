# _WDI_AUTH_ALGORITHM enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The **WDI_AUTH_ALGORITHM** enumeration defines the authentication algorithm values.

## Constants

### `WDI_AUTH_ALGO_UNKNOWN`

Specifies an unknown authentication algorithm.

### `WDI_AUTH_ALGO_80211_OPEN`

Specifies an IEEE 802.11 Open System authentication algorithm.

### `WDI_AUTH_ALGO_80211_SHARED_KEY`

Specifies an IEEE 802.11 Shared Key authentication algorithm that requires the use of a pre-shared Wired Equivalent Privacy (WEP) key for the 802.11 authentication.

### `WDI_AUTH_ALGO_WPA`

Specifies a Wi-Fi Protected Access (WPA) algorithm. IEEE 802.1X port authorization is performed by the supplicant, authenticator, and authentication server. Cipher keys are dynamically derived through the authentication process.

When the WPA algorithm is enabled, the 802.11 station only associates with an access point whose beacon or probe responses contain the authentication suite of type 1 (802.1X) within the WPA information element (IE).

### `WDI_AUTH_ALGO_WPA_PSK`

Specifies a Wi-Fi Protected Access (WPA) algorithm that uses preshared keys (PSK). IEEE 802.1X port authorization is performed by the supplicant and authenticator. Cipher keys are dynamically derived through a preshared key that is used on both the supplicant and authenticator.

When the WPA PSK algorithm is enabled, the 802.11 station only associates with an access point whose beacon or probe responses contain the authentication suite of type 2 (preshared key) within the WPA IE.

### `WDI_AUTH_ALGO_WPA_NONE`

This value is not supported.

### `WDI_AUTH_ALGO_RSNA`

Specifies an IEEE 802.11i Robust Security Network Association (RSNA) algorithm. IEEE 802.1X port authorization is performed by the supplicant, authenticator, and authentication server. Cipher keys are dynamically derived through the authentication process.

When the RSNA algorithm is enabled, the 802.11 station only associates with an access point whose beacon or probe responses contain the authentication suite of type 1 (802.1X) within the Robust Security Network (RSN) IE.

### `WDI_AUTH_ALGO_RSNA_PSK`

Specifies an IEEE 802.11i RSNA algorithm that uses PSK. IEEE 802.1X port authorization is performed by the supplicant and authenticator. Cipher keys are dynamically derived through a pre-shared key that is used on both the supplicant and authenticator.

When the RSNA PSK algorithm is enabled, the 802.11 station only associates with an access point whose beacon or probe responses contain the authentication suite of type 2 (preshared key) within the RSN IE.

### `WDI_AUTH_ALGO_WPA3_ENT_192`

Specifies a Wi-Fi Protected Access 3 (WPA3) 192-bit enterprise algorithm.

### `WDI_AUTH_ALGO_WPA3_SAE`

Specifies a WPA3-Simultaneous Authentication of Equals (WPA3-SAE) algorithm.

### `WDI_AUTH_ALGO_OWE`

Specifies an opportunistic wireless encryption (OWE) algorithm.

### `WDI_AUTH_ALGO_WPA3_ENT`

Specifies a Wi-Fi Protected Access 3 (WPA3) enterprise algorithm.

### `WDI_AUTH_ALGO_IHV_START`

Specifies the start of the range that specifies proprietary authentication algorithms that are developed by an IHV.

### `WDI_AUTH_ALGO_IHV_END`

Specifies the end of the range that specifies proprietary authentication algorithms that are developed by an IHV.