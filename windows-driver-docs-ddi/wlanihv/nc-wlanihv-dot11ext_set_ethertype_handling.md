# DOT11EXT_SET_ETHERTYPE_HANDLING callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSetEtherTypeHandling** function to do the following:

* Configure the wireless LAN (WLAN) adapter with a list of packet decryption exemptions. Each exemption
  is applied based on the IEEE EtherType of the received packet.
* Register with the operating system for the EtherTypes of received packets that will be forwarded to
  IHV Extensions DLL through calls to the
  [Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet) IHV
  Handler function.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `uMaxBackLog` [in]

The maximum number of received packets that the operating system queues if the IHV Extensions DLL
has not returned from a call to the
[Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet) IHV
Handler function. When
*uMaxBackLog* is reached, the operating system discards the oldest packet in the queue.

### `uNumOfExemption` [in]

The number of entries within the privacy exemptions array referenced by the
*pExemption* parameter. A value of zero disables privacy exemptions on the WLAN adapter.

### `pExemption` [in, optional]

A pointer to an array of privacy exemptions. Each entry in the array is formatted as a
[DOT11_PRIVACY_EXEMPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_privacy_exemption) structure.

### `uNumOfRegistration` [in]

Number of entries within the IEEE EtherType registrations array referenced by the
*pusRegistration* parameter. A value of zero disables the ability of the IHV Extensions DLL to
receive any packets through calls to the
[Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet) IHV
Handler function.

### `pusRegistration` [in, optional]

A pointer to an array of IEEE EtherType registrations. Each entry has the EtherType value in
big-endian format.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSetEtherTypeHandling(
  _In_opt_ HANDLE                   hDot11SvcHandle,
  _In_     ULONG                    uMaxBackLog,
  _In_     ULONG                    uNumOfExemption,
  _In_opt_ PDOT11_PRIVACY_EXEMPTION pExemption,
  _In_     ULONG                    uNumOfRegistration,
  _In_opt_ USHORT                   *pusRegistration
);
```

## Remarks

When calling the
**Dot11ExtSetEtherTypeHandling** function, the IHV Extensions DLL must follow
these guidelines:

* The IHV Extensions DLL can call
  **Dot11ExtSetEtherTypeHandling** from within the calls to either the
  [Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) or
  [Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate) IHV Handler functions.
* The IHV Extensions DLL must not call
  **Dot11ExtSetEtherTypeHandling** after successfully completing the
  pre-association operation through a call to
  [Dot11ExtPreAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_pre_associate_completion).

The operating system defaults to an empty list of privacy exemptions and EtherType registrations prior
to the call of the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

## See also

[Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet)

[DOT11_PRIVACY_EXEMPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_privacy_exemption)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtPreAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_pre_associate_completion)

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate)