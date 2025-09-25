# _DOT11_ADAPTER structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_ADAPTER structure identifies a wireless LAN (WLAN) adapter, as well as the operating
attributes of the instance of the Native 802.11 miniport driver that manages the adapter.

## Members

### `gAdapterId`

The globally unique identifier (GUID) of the WLAN adapter.

### `pszDescription`

A description of the WLAN adapter.

### `Dot11CurrentOpMode`

The current Native 802.11 operation mode of the miniport driver instance that manages the WLAN
adapter. The value of
**Dot11CurrentOpMode** is formatted as a
[DOT11_CURRENT_OPERATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_current_operation_mode) value.

## Syntax

```cpp
typedef struct _DOT11_ADAPTER {
  GUID                         gAdapterId;
  LPWSTR                       pszDescription;
  DOT11_CURRENT_OPERATION_MODE Dot11CurrentOpMode;
} DOT11_ADAPTER, *PDOT11_ADAPTER;
```

## Remarks

The operating system calls the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
handler function whenever a WLAN adapter becomes available and enabled for use, such as when a PCMCIA
adapter is inserted. The operating system defines the WLAN adapter by passing in the DOT11_ADAPTER
structure through the
*pDot11Adapter* parameter of the
*Dot11ExtIhvInitAdapter* function.

## See also

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[DOT11_CURRENT_OPERATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_current_operation_mode)