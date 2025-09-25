# DOT11_ADHOC_AUTH_ALGORITHM enumeration

## Description

Specifies the authentication algorithm for user or machine authentication on an ad hoc network.

## Constants

### `DOT11_ADHOC_AUTH_ALGO_INVALID`

The authentication algorithm specified is invalid.

### `DOT11_ADHOC_AUTH_ALGO_80211_OPEN`

Specifies an IEEE 802.11 Open System authentication algorithm.

### `DOT11_ADHOC_AUTH_ALGO_RSNA_PSK`

Specifies an IEEE 802.11i Robust Security Network Association (RSNA) algorithm that uses the pre-shared key (PSK) mode. IEEE 802.1X port authorization is performed by the supplicant and authenticator. Cipher keys are dynamically derived through a pre-shared key that is used on both the supplicant and authenticator.

## Remarks

Authentication and cipher algorithms are used in pairs. The following table shows valid algorithm pairs for use on an ad hoc network.

| Pair Name | DOT11_ADHOC_AUTH_ALGORITHM value | DOT11_ADHOC_CIPHER_ALGORITHM value |
| --- | --- | --- |
| Open-None | DOT11_ADHOC_AUTH_ALGO_80211_OPEN | DOT11_ADHOC_CIPHER_ALGO_NONE |
| Open-WEP | DOT11_ADHOC_AUTH_ALGO_80211_OPEN | DOT11_ADHOC_CIPHER_ALGO_WEP |
| WPA2PSK | DOT11_ADHOC_AUTH_ALGO_RSNA_PSK | DOT11_ADHOC_CIPHER_ALGO_CCMP |

## See also

[DOT11_ADHOC_CIPHER_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/adhoc/ne-adhoc-dot11_adhoc_cipher_algorithm)

[IDot11AdHocSecuritySettings::GetDot11AuthAlgorithm](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocsecuritysettings-getdot11authalgorithm)