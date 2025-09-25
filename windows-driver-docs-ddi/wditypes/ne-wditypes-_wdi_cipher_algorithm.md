# _WDI_CIPHER_ALGORITHM enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_CIPHER_ALGORITHM enumeration defines the cipher algorithm values.

## Constants

### `WDI_CIPHER_ALGO_NONE`

Specifies that no cipher algorithm is enabled or supported.

### `WDI_CIPHER_ALGO_WEP40`

Specifies a Wired Equivalent Privacy (WEP) algorithm, which is the RC4-based algorithm that is specified in the IEEE 802.11-2012 standard. This enumerator specifies the WEP cipher algorithm with a 40-bit cipher key.

### `WDI_CIPHER_ALGO_TKIP`

Specifies a Temporal Key Integrity Protocol (TKIP) algorithm, which is the RC4-based cipher suite that is based on the algorithms that are defined in the WPA specification and IEEE 802.11i-2004 standard. This cipher also uses the Michael Message Integrity Code (MIC) algorithm for forgery protection.

### `WDI_CIPHER_ALGO_CCMP`

Specifies an AES-CCMP algorithm, as specified in the IEEE 802.11i-2004 standard and RFC 3610. Advanced Encryption Standard (AES) is the encryption algorithm defined in FIPS PUB 197.

### `WDI_CIPHER_ALGO_WEP104`

Specifies a WEP cipher algorithm with a 104-bit cipher key.

### `WDI_CIPHER_ALGO_BIP`

Specifies a BIP cipher algorithm.

### `WDI_CIPHER_ALGO_GCMP`

Added in Windows 10, version 1607, WDI version 1.0.21.

Specifies a Galois/Counter Mode Protocol (GCMP) cipher algorithm. It is the only encryption protocol supported for 802.11ad (DMG) Phy.

### `WDI_CIPHER_ALGO_GCMP_256`

Added in Windows 10, version 2004, WDI version 1.1.9.

Specifies a GCMP cipher algorithm with a 256-bit cipher key.

### `WDI_CIPHER_ALGO_CCMP_256`

Added in Windows 10, version 2004, WDI version 1.1.9.

Specifies an AES-CCMP algorithm with a 256-bit cipher key.

### `WDI_CIPHER_ALGO_BIP_GMAC_128`

Added in Windows 10, version 2004, WDI version 1.1.9.

Specifies a Broadcast Integrity Protocol Galois Message Authentication Code (BIP-GMAC) cipher algorithm with a 128-bit cipher key.

### `WDI_CIPHER_ALGO_BIP_GMAC_256`

Added in Windows 10, version 2004, WDI version 1.1.9.

Specifies a BIP-GMAC cipher algorithm with a 256-bit cipher key.

### `WDI_CIPHER_ALGO_BIP_CMAC_256`

Added in Windows 10, version 2004, WDI version 1.1.9.

Specifies a Broadcast Integrity Protocol Cipher-based Message Authentication Code (BIP-CMAC) cipher algorithm with a 256-bit cipher key.

### `WDI_CIPHER_ALGO_WPA_USE_GROUP`

Specifies a Wi-Fi Protected Access (WPA) Use Group Key cipher suite. For more information about the Use Group Key cipher suite, refer to Clause 7.3.2.25.1 of the IEEE 802.11i-2004 standard.

### `WDI_CIPHER_ALGO_RSN_USE_GROUP`

Specifies a Robust Security Network (RSN) Use Group Key cipher suite. For more information about the Use Group Key cipher suite, refer to Clause 7.3.2.25.1 of the IEEE 802.11i-2004 standard.

### `WDI_CIPHER_ALGO_WEP`

Specifies a WEP cipher algorithm with a cipher key of any length.

### `WDI_CIPHER_ALGO_IHV_START`

Specifies the start of the range that is used to define proprietary cipher algorithms that are developed by an independent hardware vendor (IHV).

### `WDI_CIPHER_ALGO_IHV_END`

Specifies the end of the range that is used to define proprietary authentication algorithms that are developed by an IHV.