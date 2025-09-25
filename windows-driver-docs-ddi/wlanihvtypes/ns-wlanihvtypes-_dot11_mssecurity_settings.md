# _DOT11_MSSECURITY_SETTINGS structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_MSSECURITY_SETTINGS structure defines Microsoft security settings (from an active profile)
needed in post-associate processing when using the Microsoft 802.1X implementation.

## Members

### `dot11AuthAlgorithm`

A
[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm) type that specifies
the authentication algorithm.

### `dot11CipherAlgorithm`

A
[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm) type that
specifies the cipher algorithm for data encryption and decryption.

### `fOneXEnabled`

A Boolean value that indicates whether the Microsoft 802.1X implementation is enabled. If **TRUE**,
Microsoft 802.1X is enabled; otherwise, Microsoft 802.1X is disabled.

### `eapMethodType`

An EAP_METHOD_TYPE type that specifies the extensible authentication protocol (EAP) method. For
information about EAP_METHOD_TYPE, see the Microsoft Windows SDK.

### `dwEapConnectionDataLen`

The size, in bytes, of the EAP connection data buffer pointed to by the
**pEapConnectionData** member.

### `pEapConnectionData`

A pointer to the EAP connection data buffer.

## Syntax

```cpp
typedef struct _DOT11_MSSECURITY_SETTINGS {
  DOT11_AUTH_ALGORITHM   dot11AuthAlgorithm;
  DOT11_CIPHER_ALGORITHM dot11CipherAlgorithm;
  BOOL                   fOneXEnabled;
  EAP_METHOD_TYPE        eapMethodType;
  DWORD                  dwEapConnectionDataLen;
  BYTE                   *pEapConnectionData;
} DOT11_MSSECURITY_SETTINGS, *PDOT11_MSSECURITY_SETTINGS;
```

## See also

[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm)

[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm)