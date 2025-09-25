# CryptXmlDllEncodeKeyValue callback function

## Description

The **CryptXmlDllEncodeKeyValue** function encodes a **KeyValue** element.

## Parameters

### `hKey` [in]

The handle of the key value to encode.

### `dwCharset`

A value of the [CRYPT_XML_CHARSET](https://learn.microsoft.com/windows/desktop/api/cryptxml/ne-cryptxml-crypt_xml_charset) enumeration that specifies the character set of the encoded XML.

### `pvCallbackState` [in, out]

A pointer to an argument that is passed to the callback function pointed to by the *pfnWrite* parameter.

### `pfnWrite` [in]

An application defined callback function that receives the encoded XML.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.