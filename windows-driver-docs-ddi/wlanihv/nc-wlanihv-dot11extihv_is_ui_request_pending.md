# DOT11EXTIHV_IS_UI_REQUEST_PENDING callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvIsUIRequestPending* function to query the status of a UI request initiated by the IHV
Extensions DLL.

## Parameters

### `guidUIRequest` [in]

The GUID that identifies the request. This GUID value was created by the IHV Extensions DLL and
passed through the
*pIhvUIRequest* parameter of the call to
[Dot11ExtSendUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_ui_request).

### `pbIsRequestPending` [out]

A pointer to a Boolean value. If the UI request, identified by the
*guidUIRequest* parameter, is pending, the IHV Extensions DLL must set *
*pbIsRequestPending* to **TRUE**.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_IS_UI_REQUEST_PENDING Dot11ExtIhvIsUIRequestPending;

DWORD APIENTRY Dot11ExtIhvIsUIRequestPending(
  _In_  GUID  guidUIRequest,
  _Out_ PBOOL pbIsRequestPending
)
{ ... }
```

## Remarks

The IHV Extensions DLL can issue requests to the IHV UI Extensions DLL to interact with the user.
Examples of such requests are the display of notifications during the pre-association operation or the
input of credentials for the post-association operation. For more information about the IHV UI Extensions
DLL, see
[Native 802.11 IHV UI Extensions
DLL](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560635(v=vs.85)).

The IHV Extensions DLL initiates these requests for user interaction through calls to the
[Dot11ExtSendUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_ui_request) function. For
each UI request, the DLL must format a
[DOT11EXT_IHV_UI_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_ui_request) structure to
define the request, and must set the
**guidUIRequest** member of this structure to a GUID value that uniquely identifies the UI request. The
IHV Extensions DLL passes the address of the
**DOT11EXT_IHV_UI_REQUEST** structure through the
*pIhvUIRequest* parameter of the
**Dot11ExtSendUIRequest** function.

The operating system can periodically call the
*Dot11ExtIhvIsUIRequestPending* function to query the status of the UI request as identified by the
*guidUIRequest* parameter. If the UI request is still pending, the IHV Extensions DLL must set *
*pbIsRequestPending* to **TRUE**. Otherwise, the DLL must set *
*pbIsRequestPending* to **FALSE**.

## See also

[DOT11EXT_IHV_UI_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_ui_request)

[Dot11ExtSendUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_ui_request)