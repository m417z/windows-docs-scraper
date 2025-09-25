# CRYPT_XML_CRYPTOGRAPHIC_INTERFACE structure

## Description

The **CRYPT_XML_CRYPTOGRAPHIC_INTERFACE** structure is passed to the [CryptXmlDllGetInterface](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllgetinterface) function pointer to expose the implemented CryptXML functions.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `fpCryptXmlEncodeAlgorithm`

A pointer to the implementation of the [CryptXmlDllEncodeAlgorithm](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllencodealgorithm) function.

### `fpCryptXmlCreateDigest`

A pointer to the implementation of the [CryptXmlDllCreateDigest](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllcreatedigest) function.

### `fpCryptXmlDigestData`

A pointer to the implementation of the [CryptXmlDllDigestData](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldlldigestdata) function.

### `fpCryptXmlFinalizeDigest`

A pointer to the implementation of the [CryptXmlDllFinalizeDigest](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllfinalizedigest) function.

### `fpCryptXmlCloseDigest`

A pointer to the implementation of the [CryptXmlDllCloseDigest](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllclosedigest) function.

### `fpCryptXmlSignData`

A pointer to the implementation of the [CryptXmlDllSignData](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllsigndata) function.

### `fpCryptXmlVerifySignature`

A pointer to the implementation of the [CryptXmlDllVerifySignature](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllverifysignature) function.

### `fpCryptXmlGetAlgorithmInfo`

A pointer to the implementation of the [CryptXmlDllGetAlgorithmInfo](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllgetalgorithminfo) function.