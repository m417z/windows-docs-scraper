# DOT11EXT_SEND_PACKET callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSendPacket** function to transmit a packet through the wireless LAN
(WLAN) adapter.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `uPacketLen` [in]

The length, in bytes, of the caller-allocated buffer referenced by the
*pvPacket* parameter.

### `pvPacket` [in]

A pointer to a caller-allocated buffer that contains the data to be transmitted, as described in
the Remarks section.

### `hSendCompletion` [in, optional]

A handle value that uniquely identifies the send packet.

When the WLAN adapter completes the send operation, the operating system notifies the IHV Extensions
DLL through a call to the
[Dot11ExtIhvSendPacketCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_send_packet_completion) IHV Handler function. When making this call, the operating system
passes the handle value of the packet through the
*hSendCompletion* parameter.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSendPacket(
  _In_opt_ HANDLE hDot11SvcHandle,
  _In_     ULONG  uPacketLen,
  _In_     LPVOID pvPacket,
  _In_opt_ HANDLE hSendCompletion
);
```

## Remarks

The IHV Extensions DLL must follow these guidelines when calling the
**Dot11ExtSendPacket** function.

* The packet sent through a call of the
  **Dot11ExtSendPacket** function will complete asynchronously. The IHV
  Extensions DLL must not free the memory referenced by the
  *pvPacket* parameter until the
  [Dot11ExtIhvSendPacketCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_send_packet_completion) IHV Handler function is called with the same handle value as the
  *hSendCompletion* parameter.
* The IHV Extensions DLL must set the
  *hSendCompletion* parameter to a value that uniquely identifies the packet data that is referenced
  by the
  *pvPacket* parameter.

For more information about the IHV Handler functions, see
[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions).

The buffer pointed to by
*pvPacket* should contain the following packet data, specified in network byte order:

* MAC address of destination (6 bytes), formatted according to the guidelines discussed in
  [802.11 MAC Header
  Management](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc757419(v=ws.10))
* IEEE EtherType (2 bytes)
* Payload

This packet data is passed to the miniport driver.

## See also

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtIhvSendPacketCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_send_packet_completion)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[802.11 MAC Header Management](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc757419(v=ws.10))