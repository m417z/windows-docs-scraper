# DOT11EXT_SET_DEFAULT_KEY_ID callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSetDefaultKeyId** function to set the table index of the default or
per-station cipher key with which the wireless LAN (WLAN) adapter uses by default when encrypting
transmitted packet data.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `uDefaultKeyId` [in]

The index value of the key within the adapter's default or per-station cipher key tables.

For standard 802.11 cipher algorithms, such as WEP or TKIP,
*uDefaultKeyId* must be from 0 through 3. For a proprietary cipher algorithm developed by an IHV,
*uDefaultKeyId* can be any value within the range defined by the IHV.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSetDefaultKeyId(
  _In_opt_ HANDLE hDot11SvcHandle,
  _In_     ULONG  uDefaultKeyId
);
```

## Remarks

The default key identifier (ID) specifies the index of a cipher key in the adapter's default key and
per-station default key tables that the adapter uses for data encryption. The adapter uses the cipher key
referenced by the default key ID as the default encryption key for transmitted packets unless a
key-mapping key exists for the destination media access control (MAC) address. For more information about
these cipher key types, see
[802.11 Cipher Key Types](https://learn.microsoft.com/windows-hardware/drivers/network/802-11-cipher-key-types).

A call to the
**Dot11ExtSetDefaultKeyId** function results in a set request of the
[OID_DOT11_CIPHER_DEFAULT_KEY_ID](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-default-key-id) object identifier (OID) to the Native 802.11 miniport driver, which
manages the WLAN adapter.

## See also

[OID_DOT11_CIPHER_DEFAULT_KEY_ID](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-default-key-id)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[802.11 Cipher Key Types](https://learn.microsoft.com/windows-hardware/drivers/network/802-11-cipher-key-types)