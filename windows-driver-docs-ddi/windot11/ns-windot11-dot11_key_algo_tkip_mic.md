# DOT11_KEY_ALGO_TKIP_MIC structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_KEY_ALGO_TKIP_MIC structure defines a cipher key that is used by the TKIP algorithm for
data encryption and decryption. The structure also defines a message integrity code (MIC) used by the
Michael algorithm for verifying data integrity.

## Members

### `ucIV48Counter`

The initial 48-bit value of the TKIP Sequence Counter (TSC), which is used for replay protection.
For more information about the TSC, see
[TKIP](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565613(v=vs.85)).

### `ulTKIPKeyLength`

The length, in bytes, of the TKIP key material in the
**ucTKIPMICKeys** array. If the authentication and cipher key derivation is performed by the operating
system, this member will always have a value of 16.

### `ulMICKeyLength`

The length, in bytes, of the MIC key material in the
**ucTKIPMICKeys** array. If the authentication and cipher key derivation is performed by the operating
system, this member will always have a value of 16. The first 8 bytes will be the MIC key used for
received packets and the last 8 bytes will be the MIC key used for transmitted packets.

### `ucTKIPMICKeys`

The TKIP and MIC key material.

## Syntax

```cpp
typedef struct DOT11_KEY_ALGO_TKIP_MIC {
  UCHAR ucIV48Counter[6];
  ULONG ulTKIPKeyLength;
  ULONG ulMICKeyLength;
  UCHAR ucTKIPMICKeys[1];
} DOT11_KEY_ALGO_TKIP_MIC, *PDOT11_KEY_ALGO_TKIP_MIC;
```

## Remarks

The TKIP key starts at
**ucTKIPMICKeys** [0]. The MIC key starts at
**ucTKIPMICKeys** [
**ulTKIPKeyLength** ].

When the TKIP key is created, the 802.11 station must maintain separate TSC counters for the key for
the send and receive path. The station must initialize the TSC counters in the following way:

* Initialize the TSC counter used for the receive path to the value specified in the
  **ucIV48Counter** member.
* Initialize the TSC counter used for the send path to any value.

## See also

[OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key)

[TKIP](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565613(v=vs.85))

[DOT11_CIPHER_DEFAULT_KEY_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_default_key_value)