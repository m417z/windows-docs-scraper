# _DOT11_AUTH_ALGORITHM enumeration

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_AUTH_ALGORITHM enumeration defines a wireless LAN (WLAN) authentication algorithm.

## Constants

### `DOT11_AUTH_ALGO_80211_OPEN:1`

 Specifies an IEEE 802.11 Open System authentication algorithm.

### `DOT11_AUTH_ALGO_80211_SHARED_KEY:2`

Specifies an IEEE 802.11 Shared Key authentication algorithm that requires the use of a pre-shared
Wired Equivalent Privacy (WEP) key for the 802.11 authentication.

### `DOT11_AUTH_ALGO_WPA:3`

Specifies a Wi-Fi Protected Access (WPA) algorithm. IEEE 802.1X port authorization is performed by
the supplicant, authenticator, and authentication server. Cipher keys are dynamically derived through
the authentication process.

This algorithm is valid only for basic service set (BSS) types of
dot11_BSS_type_infrastructure.

When the WPA algorithm is enabled, the 802.11 station associates only with an access point whose
beacon or probe responses contain the authentication suite of type 1 (802.1X) within the WPA information
element (IE).

### `DOT11_AUTH_ALGO_WPA_PSK:4`

Specifies a Wi-Fi Protected Access (WPA) algorithm that uses preshared keys (PSK). IEEE 802.1X
port authorization is performed by the supplicant and authenticator. Cipher keys are dynamically derived
through a preshared key that is used on both the supplicant and authenticator.

This algorithm is valid only for BSS types of
dot11_BSS_type_infrastructure.

When the WPA PSK algorithm is enabled, the 802.11 station will associate only with an access point
whose beacon or probe responses contain the authentication suite of type 2 (preshared key) within the
WPA IE.

### `DOT11_AUTH_ALGO_WPA_NONE:5`

This value is not supported.

### `DOT11_AUTH_ALGO_RSNA:6`

Specifies an IEEE 802.11i Robust Security Network Association (RSNA) algorithm. IEEE 802.1X port
authorization is performed by the supplicant, authenticator, and authentication server. Cipher keys are
dynamically derived through the authentication process.

This algorithm is valid only for BSS types of
dot11_BSS_type_infrastructure.

When the RSNA algorithm is enabled, the 802.11 station will associate only with an access point whose
beacon or probe responses contain the authentication suite of type 1 (802.1X) within the Robust Security
Network (RSN) IE.

### `DOT11_AUTH_ALGO_RSNA_PSK:7`

Specifies an IEEE 802.11i RSNA algorithm that uses PSK. IEEE 802.1X port authorization is
performed by the supplicant and authenticator. Cipher keys are dynamically derived through a pre-shared
key that is used on both the supplicant and authenticator.

When the RSNA PSK algorithm is enabled, the 802.11 station will associate only with an access point
whose beacon or probe responses contain the authentication suite of type 2 (preshared key) within the
RSN IE.

### `DOT11_AUTH_ALGO_IHV_START:0x80000000`

Specifies the start of the range that specifies proprietary authentication algorithms that are
developed by an IHV.

The
DOT11_AUTH_ALGO_IHV_START enumerator is valid only when the miniport driver is operating in
Extensible Station (ExtSTA) mode.

### `DOT11_AUTH_ALGO_IHV_END:0xffffffff`

Specifies the end of the range that specifies proprietary authentication algorithms that are
developed by an IHV.

The
DOT11_AUTH_ALGO_IHV_END enumerator is valid only when the miniport driver is operating in ExtSTA
mode.

### `DOT11_AUTH_ALGO_WPA3:8`

Specifies a WPA3-Enterprise 192-bit mode algorithm.

### `DOT11_AUTH_ALGO_WPA3_ENT_192:DOT11_AUTH_ALGO_WPA3`

Specifies a WPA3-Enterprise 192-bit mode algorithm.

### `DOT11_AUTH_ALGO_WPA3_SAE:9`

Specifies a WPA3-Simultaneous Authentication of Equals (WPA3-SAE) algorithm.

### `DOT11_AUTH_ALGO_OWE:10`

Specifies an opportunistic wireless encryption (OWE) algorithm.

### `DOT11_AUTH_ALGO_WPA3_ENT:11`

Specifies a WPA3-Enterprise algorithm.

## Remarks

An IHV can assign a value for its proprietary authentication algorithms from
DOT11_AUTH_ALGO_IHV_START through
DOT11_AUTH_ALGO_IHV_END. The IHV must assign a unique number from this range for each of its
proprietary authentication algorithms.

If the IHV develops its own support for an authentication algorithm supported by the operating system,
the IHV must also assign a unique number from this range. For example, if the IHV develops its own
version of RSNA, it must assign a value for this version from
DOT11_AUTH_ALGO_IHV_START through
DOT11_AUTH_ALGO_IHV_END.

**Note** The 802.11 station must implicitly enable the 802.11 Open System authentication
algorithm whenever it enables a WPA or RSNA authentication algorithm.

Starting with Windows 7, an 802.11 miniport driver can report any combination of supported
authentication and cipher algorithm pairs in the
[DOT11_AUTH_CIPHER_PAIR_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_auth_cipher_pair_list) structure. However, if the operating system starts Soft AP, it enables
only the
DOT11_AUTH_ALGO_RSNA_PSK authentication algorithm and the
DOT11_CIPHER_ALGO_CCMP cipher algorithm. To support Soft AP, the miniport driver must support this
authentication/cipher pair.

If WPS is enabled on a NIC that is operating in Extensible AP mode, the miniport driver must allow
peer stations to associate with the Extensible AP by using
[Open System Authentication](https://learn.microsoft.com/windows-hardware/drivers/network/open-system-authentication) or
[Wired Equivalent Privacy (WEP)](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565846(v=vs.85)) algorithms, regardless of
the enabled authorization and cipher algorithms. For more information about WPS and Extensible AP, see
[OID_DOT11_WPS_ENABLED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wps-enabled).

## See also

[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair)

[DOT11_AUTH_CIPHER_PAIR_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_auth_cipher_pair_list)

[OID_DOT11_ENABLED_AUTHENTICATION_ALGORITHM](https://learn.microsoft.com/previous-versions/windows/embedded/gg159168(v=winembedded.80))

[DOT11_ASSOCIATION_COMPLETION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_association_completion_parameters)