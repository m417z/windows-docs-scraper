# DOT11_DIRECTION enumeration

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_DIRECTION enumeration specifies whether the 802.11 station uses a cipher key to decrypt
received packets and/or encrypt transmitted packets.

## Constants

### `DOT11_DIR_INBOUND`

The 802.11 station uses the cipher key to decrypt packets received from the access point (AP) or
peer station.

### `DOT11_DIR_OUTBOUND`

The 802.11 station uses the cipher key to encrypt packets transmitted to the AP or peer
station.

### `DOT11_DIR_BOTH`

The 802.11 station uses the cipher key for packets received from or transmitted to the AP or peer
station.

## Syntax

```cpp
typedef enum DOT11_DIRECTION {
  DOT11_DIR_INBOUND   = 1,
  DOT11_DIR_OUTBOUND  = 2,
  DOT11_DIR_BOTH      = 3
} DOT11_DIRECTION, *PDOT11_DIRECTION;
```

## See also

[Dot11ExtSetDefaultKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_default_key)

[DOT11_CIPHER_KEY_MAPPING_KEY_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_key_mapping_key_value)