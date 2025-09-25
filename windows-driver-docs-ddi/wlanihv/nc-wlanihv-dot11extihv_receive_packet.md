# DOT11EXTIHV_RECEIVE_PACKET callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvReceivePacket* function to forward a packet, received by the wireless LAN (WLAN) adapter,
to the IHV Extensions DLL for processing.

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `dwInBufferSize` [in]

The length, in bytes, of the received packet referenced by the
*pvInBuffer* parameter.

### `pvInBuffer` [in]

A pointer to a buffer, allocated by the operating system, which contains the packet data, as
described in the Remarks section.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_RECEIVE_PACKET Dot11ExtIhvReceivePacket;

DWORD APIENTRY Dot11ExtIhvReceivePacket(
  _In_opt_ HANDLE hIhvExtAdapter,
  _In_     DWORD  dwInBufferSize,
  _In_     LPVOID pvInBuffer
)
{ ... }
```

## Remarks

The operating system calls the
*Dot11ExtIhvReceivePacket* function when the following occur:

* The WLAN adapter receives a packet and the Native 802.11 miniport driver, which manages the adapter,
  indicates the packet to the operating system.
* The packet's IEEE EtherType matches an entry in the list of EtherTypes specified by the IHV
  Extensions DLL through a call to the
  [Dot11ExtSetEtherTypeHandling](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_ethertype_handling) function.

The buffer pointed to by
*pvPacket* should contain the following packet data, specified in network byte order:

* MAC address of destination (6 bytes), formatted according to the guidelines discussed in
  [802.11 MAC Header
  Management](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc757419(v=ws.10))
* IEEE EtherType (2 bytes)
* Payload

## See also

[Dot11ExtSetEtherTypeHandling](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_ethertype_handling)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)