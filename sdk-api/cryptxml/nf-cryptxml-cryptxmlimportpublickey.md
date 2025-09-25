# CryptXmlImportPublicKey function

## Description

The CryptXmlImportPublicKey function imports the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) specified by the supplied handle.

## Parameters

### `dwFlags`

A **DWORD** value that controls which CryptXML extensions are loaded. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_FLAG_DISABLE_EXTENSIONS**<br><br>0x10000000 | Only default implementations for the signature and digest are used. When this flag is set, no other registered extensions are loaded. |

### `pKeyValue` [in]

A pointer to a [CRYPT_XML_KEY_VALUE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_value) structure to receive the imported key.

### `phKey` [out]

A pointer to the handle of the key to import.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.