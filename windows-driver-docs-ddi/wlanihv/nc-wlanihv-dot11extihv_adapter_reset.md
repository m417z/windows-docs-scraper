# DOT11EXTIHV_ADAPTER_RESET callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the IHV Extensions DLL
*Dot11ExtIhvAdapterReset* function to reset the wireless LAN (WLAN) adapter.

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_ADAPTER_RESET Dot11ExtIhvAdapterReset;

DWORD APIENTRY Dot11ExtIhvAdapterReset(
  _In_opt_ HANDLE hIhvExtAdapter
)
{ ... }
```

## Remarks

The operating system calls
*Dot11ExtIhvAdapterReset* whenever one of the following events occurs.

* The WLAN adapter performs a disconnection operation. For more information about this operation, see
  [Disconnection Operations](https://learn.microsoft.com/windows-hardware/drivers/network/disconnection-operations).
* The operating system resets the Native 802.11 miniport driver, which manages the adapter, through a
  set request of
  [OID_DOT11_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-reset-request).

The
*Dot11ExtIhvAdapterReset* function must restore the WLAN adapter to the same state as when the DLL's
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) function
was called.

For more information about the reset operation for WLAN adapters, see
[802.11 WLAN Adapter Reset](https://learn.microsoft.com/windows-hardware/drivers/network/802-11-wlan-adapter-reset).

## See also

[OID_DOT11_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-reset-request)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)