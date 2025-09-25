# DOT11_CIPHER_KEY_MAPPING_KEY_VALUE structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_CIPHER_KEY_MAPPING_KEY_VALUE structure defines a key-mapping cipher key that will be added
to or deleted from the key tables on the 802.11 station. For more information about this cipher key type,
see
[802.11 Cipher Key Types](https://learn.microsoft.com/windows-hardware/drivers/network/802-11-cipher-key-types).

## Members

### `PeerMacAddr`

MAC address of the peer. The peer is either an access point (AP) (for infrastructure BSS networks)
or peer station (for independent BSS networks) with which the 802.11 station is associated.

This member is used to uniquely identify a key entry. For the standard 802.11 cipher algorithms, the
operating system will identify the peer through peer's MAC address. For proprietary cipher algorithms
developed by an independent hardware vendor (IHV), the IHV can use any method to identify a key
entry.

When the NIC is in the Extensible Access Point (ExtAP) OP mode,
**PeerMacAddr** must have a unique value.

### `AlgorithmId`

The value of the cipher algorithm that uses this key. For more information about enumerator values
for cipher algorithms, see
[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm).

### `Direction`

This member specifies whether the 802.11 station uses the key for receive or transmit packets. The
data type for this member is the
[DOT11_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-dot11_direction) enumeration.

### `bDelete`

If set to **TRUE**, the miniport driver must delete the key referenced by
**PeerMacAddr** and
**Direction** . If set to **FALSE**, the miniport driver must add or update the key referenced by
**PeerMacAddr** and
**Direction** .

### `bStatic`

A Boolean value that specifies whether the miniport driver should delete the default key following
a connection or roaming operation.

If set to **FALSE**, the miniport driver must delete the default key referenced by
**uKeyIndex** whenever:

* The 802.11 station disconnects from the BSS network.
* The peer station disconnects from the BSS network.
* The 802.11 station reconnects to the same BSS network.

If set to **TRUE**, the default key referenced by
**uKeyIndex** must not be deleted unless it is:

* Explicitly deleted through a set request of
  [OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key).
* Implicitly deleted through a method request of
  [OID_DOT11_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-reset-request).

### `usKeyLength`

The length, in bytes, of the key material in the
**ucKey** array.

### `ucKey`

The key material.

If
**AlgorithmId** is set to
**DOT11_CIPHER_ALGO_TKIP**, the
**ucKey** array defines the key material through the
[DOT11_KEY_ALGO_TKIP_MIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_key_algo_tkip_mic) structure.

If
**AlgorithmId** is set to
**DOT11_CIPHER_ALGO_CCMP**, the
**ucKey** array defines the key material through the
[DOT11_KEY_ALGO_CCMP](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_key_algo_ccmp) structure.

## Syntax

```cpp
typedef struct DOT11_CIPHER_KEY_MAPPING_KEY_VALUE {
  DOT11_MAC_ADDRESS      PeerMacAddr;
  DOT11_CIPHER_ALGORITHM AlgorithmId;
  DOT11_DIRECTION        Direction;
  BOOLEAN                bDelete;
  BOOLEAN                bStatic;
  USHORT                 usKeyLength;
  UCHAR                  ucKey[1];
} DOT11_CIPHER_KEY_MAPPING_KEY_VALUE, *PDOT11_CIPHER_KEY_MAPPING_KEY_VALUE;
```

## Remarks

The Native 802.11 miniport driver uniquely identifies key-mapping keys through the
**PeerMacAddr** and
**Direction** members. When the
[OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key) is set, the miniport driver can modify or delete an existing key
only if the values of the
**PeerMacAddr** and
**Direction** members from the set request match the members of the existing key.

If the
**bDelete** member is **TRUE**, the following members are not valid and must be ignored:

* **bStatic**
* **usKeyLength**
* **ucKey**

## See also

[OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key)

[DOT11_KEY_ALGO_TKIP_MIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_key_algo_tkip_mic)

[OID_DOT11_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-reset-request)

[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm)

[OID_DOT11_DESIRED_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-bss-type)

[DOT11_KEY_ALGO_CCMP](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_key_algo_ccmp)

[DOT11_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-dot11_direction)