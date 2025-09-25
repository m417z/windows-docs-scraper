# _DOT11_ASSOCIATION_STATE enumeration

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_ASSOCIATION_STATE enumeration defines the authentication and association state of an 802.11
station.

## Constants

### `dot11_assoc_state_zero`

The association state is undefined.

### `dot11_assoc_state_unauth_unassoc`

The 802.11 station is unauthenticated with the peer and is not associated.

### `dot11_assoc_state_auth_unassoc`

The 802.11 station is authenticated with the peer but is not associated.

### `dot11_assoc_state_auth_assoc`

The 802.11 station is authenticated and associated with the peer.

## Syntax

```cpp
typedef enum _DOT11_ASSOCIATION_STATE {
  dot11_assoc_state_zero            = 0,
  dot11_assoc_state_unauth_unassoc  = 1,
  dot11_assoc_state_auth_unassoc    = 2,
  dot11_assoc_state_auth_assoc      = 3
} DOT11_ASSOCIATION_STATE, *PDOT11_ASSOCIATION_STATE;
```