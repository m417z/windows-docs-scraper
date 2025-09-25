# CryptXmlDllCreateKey callback function

## Description

the **CryptXmlDllCreateKey** function parses the **KeyValue** element and creates a Cryptography API: Next Generation (CNG) BCrypt key handle to verify a signature.

## Parameters

### `pEncoded` [in]

A pointer to a [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure that contains the **KeyValue** element.

### `phKey` [out]

A pointer to a **BCRYPT_KEY_HANDLE** variable that receives the handle of the key used to verify the signature.

When CryptXML has finished using the key, CryptXML frees it by calling the [BCryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdestroykey) function.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.