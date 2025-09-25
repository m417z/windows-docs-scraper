# DOT11EXT_SET_DEFAULT_KEY callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSetDefaultKey** function to add or delete a cipher key from the
default key or per-station default key tables of the wireless LAN (WLAN) adapter. For more information
about these key types, see
[802.11 Cipher Key Types](https://learn.microsoft.com/windows-hardware/drivers/network/802-11-cipher-key-types).

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `pKey` [in]

A pointer to a
[DOT11_CIPHER_DEFAULT_KEY_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_default_key_value) structure, which defines the cipher key.

### `dot11Direction` [in]

A
[DOT11_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-dot11_direction) value that specifies whether
the key can be used only for received packets (DOT11_DIR_INBOUND) or both received and sent packets
(DOT11_DIR_BOTH).

**Note** The IHV Extensions DLL must not pass a value of
**DOT11_DIR_OUTBOUND** to this parameter.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSetDefaultKey(
  _In_opt_ HANDLE                          hDot11SvcHandle,
  _In_     PDOT11_CIPHER_DEFAULT_KEY_VALUE pKey,
  _In_     DOT11_DIRECTION                 dot11Direction
);
```

## Remarks

A call to the
**Dot11ExtSetDefaultKey** function results in a set request of the
[OID_DOT11_CIPHER_DEFAULT_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-default-key-id) object identifier to the WLAN adapter.

A default cipher key is defined by setting the
**MacAddr** member of the
[DOT11_CIPHER_DEFAULT_KEY_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_default_key_value) structure to a value of 0x000000000000. A per-station default cipher
key is defined by setting the
**MacAddr** member to a valid unicast media access control (MAC) address.

A cipher key is deleted from the adapter's key tables if the
**bDelete** member of the
[DOT11_CIPHER_DEFAULT_KEY_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_default_key_value) structure is set to **TRUE**.

## See also

[DOT11_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-dot11_direction)

[Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter)

[802.11 Cipher Key Types](https://learn.microsoft.com/windows-hardware/drivers/network/802-11-cipher-key-types)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[OID_DOT11_CIPHER_DEFAULT_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-default-key-id)

[DOT11_CIPHER_DEFAULT_KEY_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_default_key_value)