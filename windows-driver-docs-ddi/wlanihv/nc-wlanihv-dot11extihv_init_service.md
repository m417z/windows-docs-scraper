# DOT11EXTIHV_INIT_SERVICE callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvInitService* function to initialize the IHV Extensions DLL as well as the API interface
between the operating system and the DLL.

## Parameters

### `dwVerNumUsed` [in]

The interface version used by the operating system. The value of this parameter must be between
the ranges of version numbers returned in the
*pDot11IHVVersionInfo* parameter of the
[Dot11ExtIhvGetVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_get_version_info) IHV Handler function.

### `pDot11ExtAPI` [in]

A pointer to a
[DOT11EXT_APIS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_apis) structure, which contains the
addresses of the IHV Extensibility functions that are supported by the operating system. The operating
system formats this parameter with the function addresses before making the call to the
*Dot11ExtIhvInitService* function.

### `pvReserved`

This parameter is reserved for use by the operating system.

### `pDot11IHVHandlers` [out]

A pointer to a
[DOT11EXT_IHV_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_handlers) structure,
which contains the addresses of the IHV Handler functions supported by the IHV Extensions DLL. The DLL
formats this parameter with the function addresses before returning from the call to the
*Dot11ExtIhvInitService* function.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_INIT_SERVICE Dot11ExtIhvInitService;

DWORD APIENTRY Dot11ExtIhvInitService(
  _In_       DWORD                  dwVerNumUsed,
  _In_       PDOT11EXT_APIS         pDot11ExtAPI,
  _Reserved_ LPVOID                 pvReserved,
  _Out_      PDOT11EXT_IHV_HANDLERS pDot11IHVHandlers
)
{ ... }
```

## Remarks

The operating system calls the
*Dot11ExtIhvInitService* function immediately after the call to the
[Dot11ExtIhvGetVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_get_version_info) function. When called,
*Dot11ExtIhvInitService* must initialize the IHV Extensions DLL as necessary. When the function
returns, the DLL must be prepared to accept additional calls to the IHV Handler function.

Unlike how it treats other IHV Extension and Handler functions whose addresses are resolved through
the
*pDot11IHVHandlers* parameter, the operating system resolves the address of the
*Dot11ExtIhvInitService* function by calling the
**GetProcAddress** function. As a result, the developer of the IHV Extensions DLL must follow these
guidelines.

* The DLL must implement a function named Dot11ExtIhvInitService, which has the format that is
  described in this topic.
* The
  **EXPORTS** statement of the source module-definition (.def) file, which is used to build the IHV
  Extensions DLL, must contain a function name entry for the
  *Dot11ExtIhvInitService* function.

For more information about
**GetProcAddress**, refer to the Microsoft Windows SDK documentation.

## See also

[DOT11EXT_APIS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_apis)

[DOT11EXT_IHV_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_handlers)

[Dot11ExtIhvGetVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_get_version_info)