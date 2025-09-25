# _DOT11_WFD_GO_INTENT structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_GO_INTENT** structure represents the Group Intent value used during Group Owner Negotiation

## Members

### `TieBreaker`

If set, indicates that group ownership is granted.

### `Intent`

Group ownership intent level. The value of the local device intent is compared to the remote device intent to negotiate ownership.

## Syntax

```cpp
typedef struct _DOT11_WFD_GO_INTENT {
  UCHAR TieBreaker:1;
  UCHAR Intent:7;
} DOT11_WFD_GO_INTENT, *PDOT11_WFD_GO_INTENT;
```