# DOT11EXT_SET_AUTH_ALGORITHM callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSetAuthAlgorithm** function to enable an authentication algorithm on
the wireless LAN (WLAN) adapter.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `dwAuthAlgo` [in]

A
[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm) enumerator value
that identifies the authentication algorithm.

If the value is within the range of **DOT11_AUTH_ALGO_IHV_START** through DOT11_AUTH_ALGO_IHV_END, the
IHV Extensions DLL enables a proprietary authentication algorithm supported by the WLAN adapter.

Otherwise, the DLL is responsible for the processing of a standard authentication algorithm supported
by the operating system. In this situation, the operating system is not involved with the authentication
processing over a basic service set (BSS) network connection through the WLAN adapter.

**Note** The value of
*dwAuthAlgo* must match the value of an authentication algorithm returned by the Native 802.11
miniport driver through setting the appropriate *xxx***AlgoPairs** members of the [DOT11_EXTSTA_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_extsta_attributes) structure, which must match the values that would be returned by queries of [OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR](https://learn.microsoft.com/previous-versions/windows/embedded/gg157261(v=winembedded.80)) or [OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-multicast-algorithm-pair).

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSetAuthAlgorithm(
  _In_opt_ HANDLE hDot11SvcHandle,
  _In_     DWORD  dwAuthAlgo
);
```

## See also

[OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-multicast-algorithm-pair)

[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtPreAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_pre_associate_completion)

[OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR](https://learn.microsoft.com/previous-versions/windows/embedded/gg157261(v=winembedded.80))