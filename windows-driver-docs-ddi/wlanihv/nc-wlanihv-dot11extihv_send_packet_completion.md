# DOT11EXTIHV_SEND_PACKET_COMPLETION callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvSendPacketCompletion* function to complete the send of a packet. The IHV Extensions DLL
initiated the packet send by calling the
[Dot11ExtSendPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_packet) function.

## Parameters

### `hSendCompletion` [in, optional]

The handle value that the IHV Extensions DLL used to identify the packet when it called the
[Dot11ExtSendPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_packet) function.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_SEND_PACKET_COMPLETION Dot11ExtIhvSendPacketCompletion;

DWORD APIENTRY Dot11ExtIhvSendPacketCompletion(
  _In_opt_ HANDLE hSendCompletion
)
{ ... }
```

## Remarks

When the operating system calls the
*Dot11ExtIhvSendPacketCompletion* function, the IHV Extensions DLL can free the resources it
allocated for the packet send.

## See also

[Dot11ExtSendPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_packet)