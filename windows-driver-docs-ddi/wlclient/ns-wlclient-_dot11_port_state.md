# _DOT11_PORT_STATE structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_PORT_STATE structure defines the port state for a security session with a peer within a
basic service set (BSS) network. The peer could either be an access point (AP) within an infrastructure BSS
network, or a peer station within an independent BSS (IBSS) network.

## Members

### `PeerMacAddress`

The media access control (MAC) address of the AP or peer station with which the security session
has been initiated.

### `uSessionId`

The security session identifier (ID) assigned by the operating system.

### `bPortControlled`

A Boolean value that defines whether the port is controlled for access to the BSS network. A value
of **TRUE** specifies that the port has controlled access to the network.

For more information about controlled and uncontrolled port access, refer to Clause 6.3 of the IEEE
802.1X-1999 standard.

### `bPortAuthorized`

A Boolean value that defines whether the port is authorized to access the BSS network. A value of
**TRUE** specifies that the port has been authorized for network access.

For more information about authorized port access, refer to Clause 6.3 of the IEEE 802.1X-1999
standard.

## Syntax

```cpp
typedef struct _DOT11_PORT_STATE {
  DOT11_MAC_ADDRESS PeerMacAddress;
  ULONG             uSessionId;
  BOOL              bPortControlled;
  BOOL              bPortAuthorized;
} DOT11_PORT_STATE, *PDOT11_PORT_STATE;
```

## Remarks

The operating system passes in the current port state of the security session through the
*pPortState* parameter of the
[Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate) IHV handler function. When this function is called, the IHV
Extensions DLL must not change the data referenced by the
*pPortState* parameter.

## See also

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtIhvPerformPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_post_associate)