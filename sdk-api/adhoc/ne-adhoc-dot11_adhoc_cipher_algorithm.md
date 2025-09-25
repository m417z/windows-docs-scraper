# DOT11_ADHOC_CIPHER_ALGORITHM enumeration

## Description

Specifies a cipher algorithm used to encrypt and decrypt information on an ad hoc network.

## Constants

### `DOT11_ADHOC_CIPHER_ALGO_INVALID`

The cipher algorithm specified is invalid.

### `DOT11_ADHOC_CIPHER_ALGO_NONE`

Specifies that no cipher algorithm is enabled or supported.

### `DOT11_ADHOC_CIPHER_ALGO_CCMP`

Specifies a Counter Mode with Cipher Block Chaining Message Authentication Code Protocol (CCMP) algorithm. The CCMP algorithm is specified in the IEEE 802.11i-2004 standard and RFC 3610. CCMP is used with the Advanced Encryption Standard (AES) encryption algorithm, as defined in FIPS PUB 197.

### `DOT11_ADHOC_CIPHER_ALGO_WEP`

Specifies a Wired Equivalent Privacy (WEP) algorithm of any length.

## Remarks

Authentication and cipher algorithms are used in pairs. The following table shows valid algorithm pairs for use on an ad hoc network.

| Pair Name | DOT11_ADHOC_AUTH_ALGORITHM value | DOT11_ADHOC_CIPHER_ALGORITHM value |
| --- | --- | --- |
| Open-None | DOT11_ADHOC_AUTH_ALGO_80211_OPEN | DOT11_ADHOC_CIPHER_ALGO_NONE |
| Open-WEP | DOT11_ADHOC_AUTH_ALGO_80211_OPEN | DOT11_ADHOC_CIPHER_ALGO_WEP |
| WPA2PSK | DOT11_ADHOC_AUTH_ALGO_RSNA_PSK | DOT11_ADHOC_CIPHER_ALGO_CCMP |

## See also

[DOT11_ADHOC_AUTH_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/adhoc/ne-adhoc-dot11_adhoc_auth_algorithm)

[IDot11AdHocSecuritySettings::GetDot11CipherAlgorithm](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocsecuritysettings-getdot11cipheralgorithm)