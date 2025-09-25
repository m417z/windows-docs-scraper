# DOT11_KEY_ALGO_BIP structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_KEY_ALGO_BIP structure defines a cipher key that is used by the Broadcast Integrity Protocol (BIP) algorithm for management frame integrity protection.

## Members

### `ucIPN`

### `ulBIPKeyLength`

The length, in bytes, of the BIP key material in **ucBIPKey** array.

### `ucBIPKey`

The BIP key material.

### `ucIPN`

The initial IGTK packet number (IPN) used for replay protection.

## Syntax

```cpp
typedef struct _DOT11_KEY_ALGO_BIP {
  UCHAR ucIPN[6];
  ULONG ulBIPKeyLength;
  UCHAR ucBIPKey[1];
} DOT11_KEY_ALGO_BIP, *PDOT11_KEY_ALGO_BIP;
```