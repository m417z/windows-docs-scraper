# DOT11EXTIHV_STOP_POST_ASSOCIATE callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvStopPostAssociate* function to cancel the post-association operation initiated through a
call to the
[Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate) IHV Handler function.

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the wireless LAN (WLAN) adapter. This
handle value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `pPeer` [in]

A pointer to a
[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address) structure, which
contains the media access control (MAC) of the access point (AP) with which the IHV Extensions DLL
initiated a post-association operation.

**Note** For Windows Vista, the IHV Extensions DLL supports only infrastructure basic
service set (BSS) networks.

### `dot11AssocStatus` [in]

A
[DOT11_ASSOC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/dot11-assoc-status-status-codes) type that specifies the
association status of the 802.11 station to the network.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_STOP_POST_ASSOCIATE Dot11ExtIhvStopPostAssociate;

DWORD APIENTRY Dot11ExtIhvStopPostAssociate(
  _In_opt_ HANDLE             hIhvExtAdapter,
  _In_     PDOT11_MAC_ADDRESS pPeer,
  _In_     DOT11_ASSOC_STATUS dot11AssocStatus
)
{ ... }
```

## Remarks

The operating system calls the
*Dot11ExtIhvStopPostAssociate* function to cancel the post-association operation whenever one of the
following occurs.

* The WLAN adapter completes a disassociation operation with the AP. In this situation, the Native
  802.11 miniport driver, which manages the adapter, makes a media-specific
  [NDIS_STATUS_DOT11_DISASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-disassociation) indication. For more information about the disassociation
  operation, see
  [Disassociation Operations](https://learn.microsoft.com/windows-hardware/drivers/network/disassociation-operations).
* The WLAN adapter is disabled or removed. In this situation, the operating system calls the
  *Dot11ExtIhvStopPostAssociate* function before it calls the
  [Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter) function.

The operating system calls the
*Dot11ExtIhvStopPostAssociate* function to notify the IHV Extensions DLL that the data port created
for the association is down. The operating system calls this function regardless of whether the DLL has
completed the post-association operation through a call to
[Dot11ExtPostAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_post_associate_completion).

For more information about the post-association operation, see
[Post-Association Operations](https://learn.microsoft.com/windows-hardware/drivers/network/post-association-operations).

## See also

[DOT11_ASSOC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/dot11-assoc-status-status-codes)

[Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[NDIS_STATUS_DOT11_DISASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-disassociation)

[Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate)

[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address)