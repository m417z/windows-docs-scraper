# DOT11EXT_SET_KEY_MAPPING_KEY callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSetKeyMappingKey** function to add or delete a cipher key from the
key-mapping key tables of the wireless LAN (WLAN) adapter. For more information about these key types, see
[802.11 Cipher Key Types](https://learn.microsoft.com/windows-hardware/drivers/network/802-11-cipher-key-types).

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `pKey` [in]

A pointer to a
[DOT11_CIPHER_KEY_MAPPING_KEY_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_key_mapping_key_value) structure, which defines the cipher key.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSetKeyMappingKey(
  _In_opt_ HANDLE                              hDot11SvcHandle,
  _In_     PDOT11_CIPHER_KEY_MAPPING_KEY_VALUE pKey
);
```

## Remarks

A key-mapping cipher key is deleted from the adapter's key tables if the
**bDelete** member of the
[DOT11_CIPHER_KEY_MAPPING_KEY_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_key_mapping_key_value) structure is set to **TRUE**.

A call to the
**Dot11ExtSetKeyMappingKey** function results in a set request of the
[OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key) object identifier (OID) to the Native 802.11 miniport driver that
manages the WLAN adapter.

## See also

[OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key)

[802.11 Cipher Key Types](https://learn.microsoft.com/windows-hardware/drivers/network/802-11-cipher-key-types)

[DOT11_CIPHER_KEY_MAPPING_KEY_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_key_mapping_key_value)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)