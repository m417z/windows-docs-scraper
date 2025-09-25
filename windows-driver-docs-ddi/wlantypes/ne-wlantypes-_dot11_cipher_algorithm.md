# _DOT11_CIPHER_ALGORITHM enumeration

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_CIPHER_ALGORITHM enumeration defines a cipher algorithm for data encryption and
decryption.

## Constants

### `DOT11_CIPHER_ALGO_NONE:0x00`

Specifies that no cipher algorithm is enabled or supported.

### `DOT11_CIPHER_ALGO_WEP40:0x01`

Specifies a Wired Equivalent Privacy (WEP) algorithm, which is the RC4-based algorithm that is
specified in the IEEE 802.11-2012 standard. This enumerator specifies the WEP cipher algorithm with a
40-bit cipher key.

### `DOT11_CIPHER_ALGO_TKIP:0x02`

Specifies a Temporal Key Integrity Protocol (TKIP) algorithm, which is the RC4-based cipher suite
that is based on the algorithms that are defined in the WPA specification and IEEE 802.11i-2004
standard. This cipher also uses the Michael Message Integrity Code (MIC) algorithm for forgery
protection.

### `DOT11_CIPHER_ALGO_CCMP:0x04`

Specifies an AES-CCMP algorithm, as specified in the IEEE 802.11i-2004 standard and RFC 3610.
Advanced Encryption Standard (AES) is the encryption algorithm defined in FIPS PUB 197.

### `DOT11_CIPHER_ALGO_WEP104:0x05`

Specifies a WEP cipher algorithm with a 104-bit cipher key.

### `DOT11_CIPHER_ALGO_BIP:0x06`

Specifies a BIP cipher algorithm.

### `DOT11_CIPHER_ALGO_GCMP:0x08`

### `DOT11_CIPHER_ALGO_WPA_USE_GROUP:0x100`

Specifies a Wifi Protected Access (WPA) Use Group Key cipher suite.

For more information about the Use Group Key cipher suite, refer to Clause 7.3.2.25.1 of the IEEE
802.11i-2004 standard.

### `DOT11_CIPHER_ALGO_RSN_USE_GROUP:0x100`

Specifies a Robust Security Network (RSN) Use Group Key cipher suite.

For more information about the Use Group Key cipher suite, refer to Clause 7.3.2.25.1 of the IEEE
802.11i-2004 standard.

### `DOT11_CIPHER_ALGO_WEP:0x101`

Specifies a WEP cipher algorithm with a cipher key of any length.

A miniport driver that operates in Extensible Station (ExtSTA) mode specifies the maximum WEP cipher
key length through a query of
[OID_DOT11_EXTSTA_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-extsta-capability).

**Note** The operating system will only enable this cipher algorithm if authentication
algorithms of
**DOT11_AUTH_ALGO_80211_OPEN** or
**DOT11_AUTH_ALGO_80211_SHARED_KEY** have been enabled. For more information about these
authentication algorithms, see
[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm).

### `DOT11_CIPHER_ALGO_IHV_START:0x80000000`

Specifies the start of the range that is used to define proprietary cipher algorithms that are
developed by an independent hardware vendor (IHV).

The
**DOT11_CIPHER_ALGO_IHV_START** enumerator is valid only when the miniport driver is operating in
ExtSTA mode.

### `DOT11_CIPHER_ALGO_IHV_END:0xffffffff`

Specifies the end of the range that is used to define proprietary authentication algorithms that
are developed by an IHV.

The
**DOT11_CIPHER_ALGO_IHV_END** enumerator is valid only when the miniport driver is operating in ExtSTA
mode.

### `DOT11_CIPHER_ALGO_GCMP_256:0x09`

Specifies a GCMP cipher algorithm with a 256-bit cipher key.

### `DOT11_CIPHER_ALGO_CCMP_256:0x0a`

Specifies an AES-CCMP algorithm with a 256-bit cipher key.

### `DOT11_CIPHER_ALGO_BIP_GMAC_128:0x0b`

Specifies a Broadcast Integrity Protocol Galois Message Authentication Code (BIP-GMAC) cipher algorithm with a 128-bit cipher key.

### `DOT11_CIPHER_ALGO_BIP_GMAC_256:0x0c`

Specifies a BIP-GMAC cipher algorithm with a 256-bit cipher key.

### `DOT11_CIPHER_ALGO_BIP_CMAC_256:0x0d`

Specifies a Broadcast Integrity Protocol Cipher-based Message Authentication Code (BIP-CMAC) cipher algorithm with a 256-bit cipher key.

## Remarks

An IHV can assign a value for its proprietary cipher algorithms from
**DOT11_CIPHER_ALGO_IHV_START** through
**DOT11_CIPHER_ALGO_IHV_END**. The IHV must assign a unique number in this range to each of its
proprietary cipher algorithms.

If the IHV develops its own support for a cipher algorithm supported by the operating system, the IHV
must also assign a unique number from this range. For example, if the IHV develops its own version of
TKIP, it must assign a value for this version from
**DOT11_CIPHER_ALGO_IHV_START** through
**DOT11_CIPHER_ALGO_IHV_END**.

A miniport driver must enable or select cipher algorithms based on the following preference order
(listed from highest to lowest):

**DOT11_CIPHER_ALGO_CCMP**

**DOT11_CIPHER_ALGO_TKIP**

**DOT11_CIPHER_ALGO_WEP**

**DOT11_CIPHER_ALGO_WEP104**

**DOT11_CIPHER_ALGO_WEP40**

**DOT11_CIPHER_ALGO_NONE**

If the miniport driver supports IHV-defined cipher algorithms, the miniport driver can determine the
preference order for these algorithms with respect to the 802.11 standard cipher algorithms.

Starting with Windows 7, an 802.11 miniport driver can report any combination of supported
authentication and cipher algorithm pairs in the
[DOT11_AUTH_CIPHER_PAIR_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_auth_cipher_pair_list) structure. However, if the operating system starts Soft AP, it enables
only the
**DOT11_AUTH_ALGO_RSNA_PSK** authentication algorithm and the
**DOT11_CIPHER_ALGO_CCMP** cipher algorithm. To support Soft AP, the miniport driver must support this
authentication/cipher pair.

If WPS is enabled on a NIC that is operating in Extensible AP mode, the miniport driver must allow
peer stations to associate with the Extensible AP by using
[Open System Authentication](https://learn.microsoft.com/windows-hardware/drivers/network/open-system-authentication) or
[Wired Equivalent Privacy (WEP)](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565846(v=vs.85)) algorithms, regardless of
the enabled authorization and cipher algorithms. For more information about WPS and Extensible AP, see
[OID_DOT11_WPS_ENABLED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wps-enabled).

## See also

[OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key)

[DOT11_ASSOCIATION_COMPLETION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_association_completion_parameters)

[DOT11_CIPHER_ALGORITHM_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_algorithm_list)

[DOT11_AUTH_CIPHER_PAIR_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_auth_cipher_pair_list)

[OID_DOT11_CIPHER_DEFAULT_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-default-key-id)

[OID_DOT11_CURRENT_PHY_ID](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-current-phy-id)