# CryptXmlSign function

## Description

The **CryptXmlSign** function creates a cryptographic signature of a **SignedInfo** element.

## Parameters

### `hSignature` [in]

The handle to a [CRYPT_XML_SIGNATURE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_signature) structure.

### `hKey` [in, optional]

The handle of a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used to sign the **SignedInfo** element.
This parameter must be **NULL** for HMAC-based signature algorithms.

### `dwKeySpec`

A **DWORD** value that specifies the key type. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE**<br><br>1 | The [key pair](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) is a key exchange pair. |
| **AT_SIGNATURE**<br><br>2 | The key pair is a signature pair. |
| **CERT_NCRYPT_KEY_SPEC**<br><br>0xFFFFFFFF | The key is a Cryptography API: Next Generation (CNG) key. |

### `dwFlags`

A **DWORD** value that controls how the data is signed. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_SIGN_ADD_KEYVALUE**<br><br>0x00000001 | Populate the **KeyValue** element from the handle specified in the *hKey* parameter.<br><br>**Important** The **CRYPT_XML_SIGN_ADD_KEYVALUE** flag cannot be used when the *dwKeyInfoSpec* parameter is set to **CRYPT_XML_KEYINFO_SPEC_ENCODED**. |
| **CRYPT_XML_FLAG_DISABLE_EXTENSIONS**<br><br>0x10000000 | Only default implementations for the signature and digest are used. When this flag is set, no other registered extensions are loaded. |

### `dwKeyInfoSpec`

The type of data structure pointed to by the *pvKeyInfoSpec* parameter. Here are some possible combinations.

| *dwKeyInfec* | *pvKeyInfoSpec* |
| --- | --- |
| **CRYPT_XML_KEYINFO_SPEC_NONE** | Is set to **NULL** |
| **CRYPT_XML_KEYINFO_SPEC_ENCODED** | Points to a [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure |
| **CRYPT_XML_KEYINFO_SPEC_PARAM** | Points to a [CRYPT_XML_KEYINFO_PARAM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_keyinfo_param) structure |

### `pvKeyInfoSpec` [in, optional]

A pointer to a structure, the type of which is determined by the value of the *dwKeyInfoSpec* parameter.

### `pSignatureMethod` [in]

A pointer to a [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that specifies the signature method.

### `pCanonicalization` [in]

A pointer to a [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that specifies the canonicalization method.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.

## Remarks

If a certificate cannot be found CryptXmlSign will create a UI for certificate selection. If this window is generated from a process running in [session 0](https://techcommunity.microsoft.com/t5/ask-the-performance-team/application-compatibility-session-0-isolation/ba-p/372361), the application may unexpectedly terminate.