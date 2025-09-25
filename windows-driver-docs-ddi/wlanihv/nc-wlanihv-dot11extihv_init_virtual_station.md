# DOT11EXTIHV_INIT_VIRTUAL_STATION callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvInitVirtualStation* function to initialize the IHV Extensions DLL for virtual station
operations, and to initialize the API interface between the operating system and the DLL.

## Parameters

### `pDot11ExtVSAPI` [in]

A pointer to a
[DOT11EXT_VIRTUAL_STATION_APIS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_virtual_station_apis) structure, which contains the addresses of the IHV Extensibility
virtual station functions that are supported by the operating system. The operating system formats this
parameter with the function addresses before making a call to the
*Dot11ExtIhvInitVirtualStation* function.

### `pvReserved`

This parameter is reserved for use by the operating system and should be **NULL**.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_INIT_VIRTUAL_STATION Dot11ExtIhvInitVirtualStation;

DWORD APIENTRY Dot11ExtIhvInitVirtualStation(
  _In_       PDOT11EXT_VIRTUAL_STATION_APIS pDot11ExtVSAPI,
  _Reserved_ LPVOID                         pvReserved
)
{ ... }
```

## Remarks

It is optional for the IHV Extensions DLL to implement and export this function.

The operating system calls the
*Dot11ExtIhvInitVirtualStation* function immediately after it calls the
[Dot11ExtIhvInitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_service) function,
but before it calls the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) function.

In response to a call to
*Dot11ExtIhvInitVirtualStation*, the IHV Extensions DLL can initialize its internal data structures
with the information provided from the
*Dot11ExtIhvInitService* function call.

**Note** The IHV Extensions DLL is allowed to call the virtual station API functions that
the
*pDot11ExtVSAPI* parameter points to only after the
*Dot11ExtIhvInitVirtualStation* function returns.

The operating system resolves the address of the
*Dot11ExtIhvInitVirtualStation* function by calling the
**GetProcAddress** function. As a result, the developer of the IHV Extensions DLL must follow these
guidelines if this function is implemented.

* The DLL must implement a function named Dot11ExtIhvInitVirtualStation, which has the format that is
  described in this topic.
* The
  **EXPORTS** statement of the source module-definition (.def) file, which is used to build the IHV
  Extensions DLL, must contain a function name entry for the
  *Dot11ExtIhvInitVirtualStation* function.

For more information about
**GetProcAddress**, see the Microsoft Windows SDK documentation.

## See also

[DOT11EXT_APIS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_apis)

[DOT11EXT_IHV_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_handlers)

[Dot11ExtIhvGetVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_get_version_info)