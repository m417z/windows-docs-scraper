# DOT11EXT_ONEX_START callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtStartOneX** function to initiate an 802.1X authentication operation
with the access point (AP). In this situation, the authentication is managed by the 802.1X module of the
Native 802.11 framework instead of by the IHV Extensions DLL.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the wireless LAN (WLAN) adapter. This handle
value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `pEapAttributes` [in, optional]

A pointer to an EAP_ATTRIBUTES array structure that contains the EAP attributes returned by the
authentication session. For more information about EAP_ATTRIBUTES, see the Microsoft Windows SDK
documentation.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtStartOneX(
  _In_opt_ HANDLE         hDot11SvcHandle,
  _In_opt_ EAP_ATTRIBUTES *pEapAttribute
);
```

## Remarks

The IHV Extensions DLL can initiate an 802.1X authentication operation by using the 802.1X module of
the Native 802.11 framework. This allows the DLL to use the standard extensible authentication protocol
(EAP) algorithms that are supported by the operating system.

The IHV Extensions DLL initiates the 802.1X authentication operation by calling the
**Dot11ExtStartOneX** function.
**Dot11ExtStartOneX** can only be called either during a post-association
operation or after the operation has completed. For more information about this operation, see
[Post-Association Operations](https://learn.microsoft.com/windows-hardware/drivers/network/post-association-operations).

When the
**Dot11ExtStartOneX** function is called, the operating system sends an EAP
over LAN (EAPOL) Start packet to the AP. If the AP fails to respond after three transmissions of the
EAPOL-Start packet, the operating system fails the 802.1X authentication operation and calls the
[Dot11ExtIhvOneXIndicateResult](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_onex_indicate_result) IHV Handler function. For more information about the EAPOL-Start
packet, refer to Clause 7.5 and Clause 8.4.2 of the IEEE 802.1X-1999 standard.

After the 802.1X authentication operation is initiated, the IHV Extensions DLL must follow these
guidelines.

* The IHV Extensions must forward all EAPOL packets to the operating system for processing. When the
  DLL receives an EAPOL packet through a call to the
  [Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet) IHV
  Handler function, the DLL must call
  [Dot11ExtProcessOneXPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_process_onex_packet) to
  forward the packet to the operating system.

  For more information about EAPOL packets, refer to Clause 7 of the IEEE 802.1X-2001 standard.

  **Note** The IHV Extensions DLL is responsible for processing EAPOL-Key packets and must
  not forward these to the operating system.
* When the 802.1X authentication operation is completed, the operating system calls the
  [Dot11ExtIhvOneXIndicateResult](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_onex_indicate_result) IHV Handler function to indicate that authorization is in
  progress.
* The IHV Extensions DLL can cancel the 802.1X authentication operation by calling
  [Dot11ExtStopOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_stop).

For more information about using the 802.1X module for authentication, see
[Interface to the Native
802.11 802.1X Module](https://learn.microsoft.com/windows-hardware/drivers/network/interface-to-the-native-802-11-802-1x-module).

## See also

[Dot11ExtPostAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_post_associate_completion)

[Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet)

[Dot11ExtProcessOneXPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_process_onex_packet)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtIhvOneXIndicateResult](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_onex_indicate_result)

[Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate)

[Dot11ExtStopOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_stop)