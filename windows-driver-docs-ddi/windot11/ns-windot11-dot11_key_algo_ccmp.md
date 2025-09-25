# DOT11_KEY_ALGO_CCMP structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_KEY_ALGO_CCMP structure defines a cipher key that is used by the AES-CCMP algorithm for
data encryption and decryption.

## Members

### `ucIV48Counter`

The initial 48-bit value of the AES-CCMP Packet Number (PN), which is used for replay protection.
For more information about the PN, see
[AES-CCMP](https://learn.microsoft.com/windows-hardware/drivers/network/aes-ccmp).

### `ulCCMPKeyLength`

The length, in bytes, of the AES-CCMP key material in the
**ucCCMPKey** array. If the authentication and cipher key derivation is performed by the operating
system, this member will always have a value of 16.

### `ucCCMPKey`

The AES-CCMP key material.

## Syntax

```cpp
typedef struct DOT11_KEY_ALGO_CCMP {
  UCHAR ucIV48Counter[6];
  ULONG ulCCMPKeyLength;
  UCHAR ucCCMPKey[1];
} DOT11_KEY_ALGO_CCMP, *PDOT11_KEY_ALGO_CCMP;
```

## Remarks

When the AES-CCMP key is created, the 802.11 station must maintain separate PN counters for the key
for the send and receive path. The station must initialize the PN counters in the following way:

* Initialize the PN counter used for the receive path to the value specified in the
  **ucIV48Counter** member.
* Initialize the PN counter used for the send path to any value.

## See also

[OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key)

[AES-CCMP](https://learn.microsoft.com/windows-hardware/drivers/network/aes-ccmp)

[DOT11_CIPHER_DEFAULT_KEY_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_default_key_value)