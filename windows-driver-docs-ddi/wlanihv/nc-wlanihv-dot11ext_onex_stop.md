# DOT11EXT_ONEX_STOP callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtStopOneX** function to cancel an 802.1X authentication operation with
the access point (AP). The DLL initiated the authentication through a call to the
[Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start) function.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the wireless LAN (WLAN) adapter. This handle
value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtStopOneX(
  _In_opt_ HANDLE hDot11SvcHandle
);
```

## Remarks

When it calls the
[Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start) function, the IHV
Extensions DLL initiates an 802.1X authentication operation by using the 802.1X module of the Native
802.11 framework. This allows the DLL to use the standard extensible authentication protocol (EAP)
algorithms that are supported by the operating system.

Before the 802.1X authentication operation completes, the IHV Extensions DLL can call the
**Dot11ExtStopOneX** function to cancel the operation.

When calling the
**Dot11ExtStopOneX** function, the IHV Extensions DLL must follow these
guidelines.

* **Dot11ExtStopOneX** can only be called while an 802.1X authentication
  operation is pending. The IHV Extensions DLL initiates the authentication with the AP by calling
  [Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start). When the 802.1X
  authentication operation is completed, the operating system calls the
  [Dot11ExtIhvOneXIndicateResult](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_onex_indicate_result) IHV Handler function.
* After the IHV Extensions DLL calls
  **Dot11ExtStopOneX**, it must not call
  [Dot11ExtProcessOneXPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_process_onex_packet) to
  forward 802.1X EAP over LAN (EAPOL) packets to the operating system. For more information about EAPOL
  packets, refer to Clause 7 of the IEEE 802.1X-2001 standard.

For more information about using the 802.1X module for authentication, see
[Interface to the Native
802.11 802.1X Module](https://learn.microsoft.com/windows-hardware/drivers/network/interface-to-the-native-802-11-802-1x-module).

## See also

[Dot11ExtPostAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_post_associate_completion)

[Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet)

[Dot11ExtProcessOneXPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_process_onex_packet)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtIhvOneXIndicateResult](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_onex_indicate_result)

[Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start)

[Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate)