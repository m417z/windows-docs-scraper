# _DOT11EXT_IHV_UI_REQUEST structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_IHV_UI_REQUEST structure specifies a request made by the IHV Extensions DLL to the IHV
UI extensions DLL.

## Members

### `dwSessionId`

The session identifier (ID) of the current user.

### `guidUIRequest`

A globally unique ID (GUID) which identifies the UI request.

### `UIPageClsid`

The
**IWizardExtension** COM class ID (CLSID) of the target UI page that will handle this request. For
more information about the
**IWizardExtension** COM interface, see
[IWizardExtension COM Interface](https://learn.microsoft.com/windows/win32/api/shobjidl/nn-shobjidl-iwizardextension).

### `dwByteCount`

The length, in bytes, within the buffer referenced through the
**pvUIRequest** member.

### `pvUIRequest`

A pointer to a buffer that contains the request data in a format defined by the independent
hardware vendor (IHV).

## Syntax

```cpp
typedef struct _DOT11EXT_IHV_UI_REQUEST {
  DWORD dwSessionId;
  GUID  guidUIRequest;
  CLSID UIPageClsid;
  DWORD dwByteCount;
  BYTE  *pvUIRequest;
} DOT11EXT_IHV_UI_REQUEST, *PDOT11EXT_IHV_UI_REQUEST;
```

## Remarks

The IHV Extensions DLL can issue requests to the IHV UI extensions DLL to interact with the user for
input to network UI extensions defined by the IHV. The IHV Extensions DLL initiates these requests
through calls to the
[Dot11ExtSendUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_ui_request) or
[Dot11ExtIhvQueryUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_query_ui_request) functions.

For each UI request, the DLL must format a DOT11EXT_IHV_UI_REQUEST structure to define the request,
and must set the
**guidUIRequest** member of this structure to a GUID value that uniquely identifies the UI request.

## See also

[Dot11ExtIhvIsUIRequestPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_is_ui_request_pending)

[Dot11ExtSendUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_ui_request)

[Dot11ExtIhvQueryUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_query_ui_request)