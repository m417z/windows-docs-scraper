# CryptXmlGetAlgorithmInfo function

## Description

The **CryptXmlGetAlgorithmInfo** function decodes the [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure and returns information about the algorithm.

## Parameters

### `pXmlAlgorithm` [in]

A pointer to a [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that specifies the algorithm about which to return information.

### `dwFlags`

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_FLAG_DISABLE_EXTENSIONS**<br><br>0x10000000 | Only default implementations for the signature and digest are used. When this flag is set, no other registered extensions are loaded. |

### `ppAlgInfo` [out]

A pointer to a pointer to a [CRYPT_XML_ALGORITHM_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm_info) structure. When you have finished using the memory pointed to by the *ppAlgInfo* parameter, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.