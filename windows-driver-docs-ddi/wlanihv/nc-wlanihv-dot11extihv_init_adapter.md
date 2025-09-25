# DOT11EXTIHV_INIT_ADAPTER callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvInitAdapter* function to have the IHV Extensions DLL allocate and initialize an adapter
context.

## Parameters

### `pDot11Adapter` [in]

A pointer to a
[DOT11_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_adapter) structure, which identifies the
adapter to be initialized.

### `hDot11SvcHandle` [in, optional]

A handle assigned by the operating system for the adapter. The IHV Extensions DLL must use this
handle value when calling any IHV Extensibility function that declares an
*hDot11SvcHandle* parameter, such as
[Dot11ExtPreAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_pre_associate_completion).

### `phIhvExtAdapter` [out]

A pointer to a handle variable. The IHV Extensions DLL must assign a unique handle value for the
adapter and set *
*phIhvExtAdapter* to the handle value. The operating system uses this handle value when it calls any
IHV Handler function that declares an
*hIhvExtAdapter* parameter, such as
[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate).

Typically, the IHV Extensions DLL allocates a state array for the adapter context and returns the
address of the array as the handle value.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_INIT_ADAPTER Dot11ExtIhvInitAdapter;

DWORD APIENTRY Dot11ExtIhvInitAdapter(
  _In_     PDOT11_ADAPTER pDot11Adapter,
  _In_opt_ HANDLE         hDot11SvcHandle,
  _Out_    PHANDLE        phIhvExtAdapter
)
{ ... }
```

## Remarks

The operating system calls the
*Dot11ExtIhvInitAdapter* function whenever a WLAN adapter becomes available and enabled for use, such
as when a PCMCIA adapter is inserted.

For more information about WLAN adapter initialization, see
[802.11 WLAN Adapter Arrival](https://learn.microsoft.com/windows/win32/api/l2cmn/ns-l2cmn-l2_notification_data).

## See also

[Native 802.11 IHV
Extensibility Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-extensibility-functions)

[Dot11ExtPreAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_pre_associate_completion)

[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate)

[DOT11_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_adapter)