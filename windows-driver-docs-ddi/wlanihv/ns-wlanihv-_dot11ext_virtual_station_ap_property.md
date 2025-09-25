# _DOT11EXT_VIRTUAL_STATION_AP_PROPERTY structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_VIRTUAL_STATION_AP_PROPERTY structure specifies the properties of an access point (AP)
hosted on a virtual 802.11 station.

## Members

### `dot11SSID`

A
[DOT11_SSID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-_dot11_ssid) structure that contains the service
set identifier (SSID) used by the virtual station AP.

### `dot11AuthAlgo`

A
[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm) structure that
contains the authentication algorithm used by the virtual station AP.

### `dot11CipherAlgo`

A
[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm) structure that
contains the cipher algorithm used by the virtual station AP.

### `bIsPassPhrase`

A Boolean value that indicates how the operating system should interpret the value of the
**ucKeyData** member. For more information, see the following Remarks section.

### `dwKeyLength`

The length, in bytes, of the useful part of the
**ucKeyData** member. For more information, see the following Remarks section.

### `ucKeyData`

A UCHAR value that specifies the key used by the virtual station AP's Preshared Keys (PSK)
authentication algorithm. For more information, see the following Remarks section.

## Syntax

```cpp
typedef struct _DOT11EXT_VIRTUAL_STATION_AP_PROPERTY {
  DOT11_SSID             dot11SSID;
  DOT11_AUTH_ALGORITHM   dot11AuthAlgo;
  DOT11_CIPHER_ALGORITHM dot11CipherAlgo;
  BOOL                   bIsPassPhrase;
  DWORD                  dwKeyLength;
  UCHAR                  ucKeyData[DOT11EXT_PSK_MAX_LENGTH];
} DOT11EXT_VIRTUAL_STATION_AP_PROPERTY, *PDOT11EXT_VIRTUAL_STATION_AP_PROPERTY;
```

## Remarks

The operating system uses the following logic to interpret the value of the
**ucKeyData** member:

* If
  **bIsPassPhrase** = **FALSE**,
  + If
    **dwKeyLength** = 32,
    **ucKeyData** is interpreted as binary data.
  + If
    **dwKeyLength** = 64,
    **ucKeyData** is interpreted as 32 hexadecimal values.
  + If
    **dwKeyLength** is not equal to 32 or 64, the operating system ignores the call and returns an
    error.
* If
  **bIsPassPhrase** = **TRUE**,
  **ucKeyData** is interpreted as a pass phrase, and the buffer must be NULL terminated. In this case,
  **dwKeyLength** should have a value that equals 1 plus the length of the key string.

## See also

[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm)

[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm)

[DOT11_SSID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-_dot11_ssid)