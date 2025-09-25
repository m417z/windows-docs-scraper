# DOT11EXTIHV_PROCESS_UI_RESPONSE callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvProcessUIResponse* function to complete a UI request initiated by the IHV Extensions DLL
through a call to
[Dot11ExtSendUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_ui_request).

## Parameters

### `guidUIRequest` [in]

The GUID that identifies the request. This GUID value was created by the IHV Extensions DLL and
passed through the
*pIhvUIRequest* parameter of the call to
[Dot11ExtSendUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_ui_request).

### `dwByteCount` [in]

The length, in bytes, of the data referenced through the
*pvResponseBuffer* parameter.

### `pvResponseBuffer` [in, optional]

A pointer to the buffer that contains the user data.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_PROCESS_UI_RESPONSE Dot11ExtIhvProcessUIResponse;

DWORD APIENTRY Dot11ExtIhvProcessUIResponse(
  _In_     GUID   guidUIRequest,
  _In_     DWORD  dwByteCount,
  _In_opt_ LPVOID pvResponseBuffer
)
{ ... }
```

## Remarks

The IHV Extensions DLL can issue requests to the IHV UI Extensions DLL for interaction with the user,
such as the display of notifications during the pre-association operation or the input of credential for
the post-association operation. For more information about the IHV UI Extensions DLL, see
[Native 802.11 IHV UI Extensions
DLL](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560635(v=vs.85)).

The IHV Extensions DLL initiates these requests for user interaction through calls to the
[Dot11ExtSendUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_ui_request) function. For
each UI request, the DLL must format a
[DOT11EXT_IHV_UI_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_ui_request) structure to
define the request, and must set the
**guidUIRequest** member of this structure to a GUID value that uniquely identifies the UI request. The
DLL passes the address of the
**DOT11EXT_IHV_UI_REQUEST** structure through the
*pIhvUIRequest* parameter of the
**Dot11ExtSendUIRequest** function.

After receiving this data from the IHV Extensions DLL, the operating system calls the
*Dot11ExtIhvProcessUIResponse* function to process the user response, which is referenced through the
*pvResponseBuffer* parameter. The response data is in a format defined by the IHV and has been validated by the IHV UI
Extensions DLL.

## See also

[DOT11EXT_IHV_UI_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_ui_request)

[Dot11ExtSendUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_ui_request)