# DOT11EXTIHV_GET_VERSION_INFO callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvGetVersionInfo* function immediately after loading the IHV Extensions DLL to determine the
version of the interface supported by the DLL.

## Parameters

### `pDot11IHVVersionInfo` [out]

A pointer to a
[DOT11_IHV_VERSION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11_ihv_version_info) structure,
which contains the interface version numbers.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_GET_VERSION_INFO Dot11ExtIhvGetVersionInfo;

DWORD APIENTRY Dot11ExtIhvGetVersionInfo(
  _Out_ PDOT11_IHV_VERSION_INFO pDot11IHVVersionInfo
)
{ ... }
```

## Remarks

The operating system calls the
*Dot11ExtIhvGetVersionInfo* function to determine what version of the interface to use with the IHV
Extension DLL. The operating system makes this call immediately after loading the DLL, and this call is
the first that the operating system makes into the DLL.

Unlike other IHV Extensibility and Handler functions, whose addresses are resolved through a table of
function pointers that are exchanged through a call to
[Dot11ExtIhvInitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_service), the
address of the
*Dot11ExtIhvGetVersionInfo* function is resolved by the operating system by the operating system
calling the
**GetProcAddress** function. As a result, the developer of the IHV Extensions DLL must follow these
guidelines.

* The DLL must implement a function named Dot11ExtIhvGetVersionInfo, which has the format that is
  described in this topic.
* The
  **EXPORTS** statement of the source module-definition (.def) file, which is used to build the IHV
  Extensions DLL, must contain a function name entry for the
  *Dot11ExtIhvGetVersionInfo* function.

For more information about
**GetProcAddress**, refer to the Microsoft Windows SDK documentation.

## See also

[DOT11_IHV_VERSION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11_ihv_version_info)

[Dot11ExtIhvInitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_service)