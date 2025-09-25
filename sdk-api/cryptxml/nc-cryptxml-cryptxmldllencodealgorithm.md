# CryptXmlDllEncodeAlgorithm callback function

## Description

The **CryptXmlDllEncodeAlgorithm** function encodes **SignatureMethod** or **DigestMethod** elements for agile algorithms with default parameters.

The **CryptXmlDllEncodeAlgorithm** function is exposed through the exported [CryptXmlDllGetInterface](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllgetinterface) function.

## Parameters

### `pAlgInfo` [in]

A pointer to a [CRYPT_XML_ALGORITHM_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm_info) structure.

### `dwCharset`

A [CRYPT_XML_CHARSET](https://learn.microsoft.com/windows/desktop/api/cryptxml/ne-cryptxml-crypt_xml_charset) value that specifies the character set of the encoded XML.

### `pvCallbackState` [in, out]

A pointer to an argument that is passed to the callback function pointed to by the *pfnWrite* parameter.

### `pfnWrite` [in]

A [PFN_CRYPT_XML_WRITE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-pfn_crypt_xml_write_callback) callback function that receives the encoded XML.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.