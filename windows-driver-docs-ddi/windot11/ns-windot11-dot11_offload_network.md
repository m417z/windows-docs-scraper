# DOT11_OFFLOAD_NETWORK structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_OFFLOAD_NETWORK structure describes a network list offload.

## Members

### `Ssid`

SSID interface.

### `UnicastCipher`

Cipher algorithm for data encryption and decryption.

### `AuthAlgo`

Wireless LAN authentication algorithm.

### `Dot11ChannelHints`

Array of hints listing 802.11 PHY and media types and channels.

## Syntax

```cpp
typedef struct _DOT11_OFFLOAD_NETWORK {
  DOT11_SSID             Ssid;
  DOT11_CIPHER_ALGORITHM UnicastCipher;
  DOT11_AUTH_ALGORITHM   AuthAlgo;
  DOT11_CHANNEL_HINT     Dot11ChannelHints[DOT11_MAX_CHANNEL_HINTS];
} DOT11_OFFLOAD_NETWORK, *PDOT11_OFFLOAD_NETWORK;
```