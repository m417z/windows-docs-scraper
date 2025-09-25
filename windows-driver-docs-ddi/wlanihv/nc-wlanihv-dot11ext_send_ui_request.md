# DOT11EXT_SEND_UI_REQUEST callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSendUIRequest** function to request user notification or input
through the
[Native 802.11 IHV UI Extensions
DLL](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560635(v=vs.85)).

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the wireless LAN (WLAN) adapter. This handle
value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `pIhvUIRequest` [in]

A pointer to a caller-allocated buffer, formatted as a
[DOT11EXT_IHV_UI_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_ui_request) structure.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSendUIRequest(
  _In_opt_ HANDLE                   hDot11SvcHandle,
  _In_     PDOT11EXT_IHV_UI_REQUEST pIhvUIRequest
);
```

## Remarks

The IHV Extensions DLL must follow these guidelines when calling the
**Dot11ExtSendUIRequest** function.

* Requests for event notification by the
  [Native 802.11 IHV UI Extensions
  DLL](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560635(v=vs.85)) are completed through a call to the
  [Dot11ExtIhvProcessUIResponse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_process_ui_response) IHV Handler function. The IHV Extensions DLL must not free the
  memory referenced by the
  *pIhvUIRequest* parameter until the request is completed.
* If the operating system calls the
  [Dot11ExtIhvAdapterReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_adapter_reset) or
  [Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter) IHV
  handler functions, the IHV Extensions DLL can assume that the UI request has been canceled. In this
  situation, the DLL must free the memory referenced by the
  *pIhvUIRequest* parameter.
* The operating system can query the completion status of the request through a call to the
  [Dot11ExtIhvIsUIRequestPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_is_ui_request_pending) IHV Handler function.

## See also

[Dot11ExtIhvAdapterReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_adapter_reset)

[Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter)

[Dot11ExtIhvProcessUIResponse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_process_ui_response)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtIhvIsUIRequestPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_is_ui_request_pending)