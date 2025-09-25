# DOT11EXTIHV_RECEIVE_INDICATION callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvReceiveIndication* function to issue an IHV-specific indication to the IHV Extensions DLL
from the wireless LAN (WLAN) adapter.

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `indicationType` [in]

The
[DOT11EXT_IHV_INDICATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ne-wlanihv-_dot11ext_ihv_indication_type) indication type.

### `uBufferLength` [in]

The length, in bytes, of the data within the buffer that is referenced by the
*pvBuffer* parameter.

### `pvBuffer` [in, optional]

The pointer to a buffer, allocated by the operating system, which contains the notification data.
The IHV is responsible for defining the format of the notification data.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_RECEIVE_INDICATION Dot11ExtIhvReceiveIndication;

DWORD APIENTRY Dot11ExtIhvReceiveIndication(
  _In_opt_ HANDLE                       hIhvExtAdapter,
  _In_     DOT11EXT_IHV_INDICATION_TYPE indicationType,
  _In_     ULONG                        uBufferLength,
  _In_opt_ LPVOID                       pvBuffer
)
{ ... }
```

## Remarks

When the Native 802.11 miniport driver, which manages the WLAN adapter, makes an
[NDIS_STATUS_MEDIA_SPECIFIC_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-media-specific-indication) indication, the operating system forwards the notification
data to the IHV Extensions DLL by calling the
*Dot11ExtIhvReceiveIndication* function.

## See also

[NDIS_STATUS_MEDIA_SPECIFIC_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-media-specific-indication)

[DOT11EXT_IHV_INDICATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ne-wlanihv-_dot11ext_ihv_indication_type)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)