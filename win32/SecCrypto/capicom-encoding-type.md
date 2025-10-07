# CAPICOM\_ENCODING\_TYPE enumeration

The **CAPICOM\_ENCODING\_TYPE** enumeration type indicates the encoding type used.

## Members

| Member | Description | Value |
|-----------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------|
| **CAPICOM\_ENCODE\_ANY** | Data is saved as a base64-encoded string or a pure binary sequence. This encoding type is used only for input data that has an unknown encoding type. Introduced in CAPICOM 2.0.<br> | 0xffffffff |
| **CAPICOM\_ENCODE\_BASE64** | Data is saved as a base64-encoded string.<br> | 0 |
| **CAPICOM\_ENCODE\_BINARY** | Data is saved as a pure binary sequence.<br> | 1 |

## Remarks

This enumeration type is used by the following CAPICOM methods and properties:

- [**Certificate.Export**](https://learn.microsoft.com/windows/win32/seccrypto/certificate-export) method
- [**EncodedData.Value**](https://learn.microsoft.com/windows/win32/seccrypto/encodeddata-value) property
- [**EncryptedData.Encrypt**](https://learn.microsoft.com/windows/win32/seccrypto/encrypteddata-encrypt) method
- [**EnvelopedData.Encrypt**](https://learn.microsoft.com/windows/win32/seccrypto/envelopeddata-encrypt) method
- [**ExtendedProperty.Value**](https://learn.microsoft.com/windows/win32/seccrypto/extendedproperty-value) property
- [**SignedData.Sign**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata-sign) method
- [**SignedData.CoSign**](https://learn.microsoft.com/windows/win32/seccrypto/signeddata-cosign) method
- [**Store.Export**](https://learn.microsoft.com/windows/win32/seccrypto/store-export) method
- [**Utilities.GetRandom**](https://learn.microsoft.com/windows/win32/seccrypto/utilities-getrandom) method

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

