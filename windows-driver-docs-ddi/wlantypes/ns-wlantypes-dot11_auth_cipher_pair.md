# DOT11_AUTH_CIPHER_PAIR structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_AUTH_CIPHER_PAIR structure defines a pair of 802.11 authentication and cipher algorithms
that can be enabled at the same time on the 802.11 station.

## Members

### `AuthAlgoId`

An authentication algorithm as specified by a
[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm) value.

### `CipherAlgoId`

A cipher algorithm as specified by a
[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm) value.

## Syntax

```cpp
typedef struct DOT11_AUTH_CIPHER_PAIR {
  DOT11_AUTH_ALGORITHM   AuthAlgoId;
  DOT11_CIPHER_ALGORITHM CipherAlgoId;
} DOT11_AUTH_CIPHER_PAIR, *PDOT11_AUTH_CIPHER_PAIR;
```

## Remarks

The DOT11_AUTH_CIPHER_PAIR structure defines an authentication and cipher algorithm that can be
enabled together for basic service set (BSS) network connections.

A miniport driver returns a list of these structures when either
[OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR](https://learn.microsoft.com/previous-versions/windows/embedded/gg157261(v=winembedded.80)) or
[OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-multicast-algorithm-pair) is queried.

Starting with Windows 7, an 802.11 miniport driver can report any combination of supported
authentication and cipher algorithm pairs in the
[DOT11_AUTH_CIPHER_PAIR_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_auth_cipher_pair_list) structure. However, if the operating system starts Soft AP, it enables
only the
**DOT11_AUTH_ALGO_RSNA_PSK** authentication algorithm and the
**DOT11_CIPHER_ALGO_CCMP** cipher algorithm. To support Soft AP, the miniport driver must support this
authentication/cipher pair.

**Note** IBSS (Ad hoc) and SoftAP are deprecated. Starting with Windows 8.1 and Windows Server 2012 R2, use [Wi-Fi Direct](https://learn.microsoft.com/windows-hardware/drivers/partnerapps/wi-fi-direct).

If WPS is enabled on a NIC that is operating in Extensible AP mode, the miniport driver must allow
peer stations to associate with the Extensible AP by using
[Open System Authentication](https://learn.microsoft.com/windows-hardware/drivers/network/open-system-authentication) or
[Wired Equivalent Privacy (WEP)](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565846(v=vs.85)) algorithms, regardless of
the enabled authorization and cipher algorithms. For more information about WPS and Extensible AP, see
[OID_DOT11_WPS_ENABLED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wps-enabled).

## See also

[OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-multicast-algorithm-pair)

[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm)

[DOT11_AUTH_CIPHER_PAIR_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_auth_cipher_pair_list)

[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm)

[OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR](https://learn.microsoft.com/previous-versions/windows/embedded/gg157261(v=winembedded.80))