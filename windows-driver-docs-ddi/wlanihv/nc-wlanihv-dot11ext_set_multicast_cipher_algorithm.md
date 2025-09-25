# DOT11EXT_SET_MULTICAST_CIPHER_ALGORITHM callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSetMulticastCipherAlgorithm** function to enable a multicast cipher
algorithm on the wireless LAN (WLAN) adapter.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `dwMulticastCipherAlgo` [in]

A
[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm) enumerator
value that identifies the multicast cipher algorithm.

If the value is within the range of **DOT11_CIPHER_ALGO_IHV_START** through DOT11_CIPHER_ALGO_IHV_END,
the IHV Extensions DLL enables a proprietary cipher algorithm supported by the WLAN adapter.

Otherwise, the DLL is responsible for processing a standard cipher algorithm supported by the
operating system. In this situation, the operating system is not involved with any aspect of the cipher
algorithm, including key management and replay protection, over a basic service set (BSS) network
connection through the WLAN adapter.

**Note** The value of
*dwMulticastCipherAlgo* must match the value of a cipher algorithm returned by the Native 802.11
miniport driver through setting the appropriate *xxx***AlgoPairs** members of the [DOT11_EXTSTA_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_extsta_attributes) structure, which must match the values that would be returned by queries of
[OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR](https://learn.microsoft.com/previous-versions/windows/embedded/gg157261(v=winembedded.80)) or
[OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-multicast-algorithm-pair).

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSetMulticastCipherAlgorithm(
  _In_opt_ HANDLE hDot11SvcHandle,
  _In_     DWORD  dwMulticastCipherAlgo
);
```

## See also

[OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR](https://learn.microsoft.com/previous-versions/windows/embedded/gg157261(v=winembedded.80))

[OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-multicast-algorithm-pair)

[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)