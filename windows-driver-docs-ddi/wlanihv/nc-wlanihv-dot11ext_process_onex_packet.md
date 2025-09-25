# DOT11EXT_PROCESS_ONEX_PACKET callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtProcessOneXPacket** function to forward EAP over LAN (EAPOL) packets
to the operating system for processing during an 802.1X authentication operation with the access point
(AP).

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the wireless LAN (WLAN) adapter. This handle
value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `dwInPacketSize` [in]

The length, in bytes, of the packet data within the buffer that is referenced by the
*pvInPacket* parameter.

### `pvInPacket` [in]

The EAPOL packet received from the AP. The
*pvInPacket* parameter must reference the EAPOL packet starting from the packet type field in the
EAPOL protocol data unit (PDU). For more information about the EAPOL packet type field, refer to Clause
7.5.4 in the IEEE 802.1X-2001 standard.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtProcessOneXPacket(
  _In_opt_ HANDLE hDot11SvcHandle,
  _In_     DWORD  dwInPacketSize,
  _In_     LPVOID pvInPacket
);
```

## Remarks

When it calls the
[Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start) function, the IHV
Extensions DLL initiates an 802.1X authentication operation by using the 802.1X module of the Native
802.11 framework. This allows the DLL to use the standard extensible authentication protocol (EAP)
algorithms that are supported by the operating system.

While the 802.1X authentication operation is pending, the IHV Extensions DLL forwards received EAP
over LAN (EAPOL) packets to the operating system through a call to the
**Dot11ExtProcessOneXPacket** function. The IHV Extensions DLL receives these
packets through the
[Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet) IHV
Handler function.

**Note** The IHV Extensions DLL is responsible for processing EAPOL-Key packets and must not
forward these to the operating system.

For more information about EAPOL packets, refer to Clause 7 of the IEEE 802.1X-2001 standard.

For more information about using the 802.1X module for authentication, see
[Interface to the Native
802.11 802.1X Module](https://learn.microsoft.com/windows-hardware/drivers/network/interface-to-the-native-802-11-802-1x-module)

## See also

[Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtIhvOneXIndicateResult](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_onex_indicate_result)

[Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start)

[Dot11ExtStopOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_stop)