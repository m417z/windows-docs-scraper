# _DOT11_WFD_CONFIGURATION_TIMEOUT structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_CONFIGURATION_TIMEOUT** structure contains configuration time-out parameters.

## Members

### `GOTimeout`

The time, in milliseconds, allowed to configure as a Group Owner (GO). The miniport must convert this value to the correct units before including it in a Peer-to-Peer Information Element (P2P IE).

### `ClientTimeout`

The time, in milliseconds, allowed to configure as a client. The miniport must convert this value to the correct units before including it in a P2P IE.

## Syntax

```cpp
typedef struct _DOT11_WFD_CONFIGURATION_TIMEOUT {
  UCHAR GOTimeout;
  UCHAR ClientTimeout;
} DOT11_WFD_CONFIGURATION_TIMEOUT, *PDOT11_WFD_CONFIGURATION_TIMEOUT;
```