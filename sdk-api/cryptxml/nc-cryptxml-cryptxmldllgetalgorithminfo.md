## Description

The **CryptXmlDllGetAlgorithmInfo** function decodes the XML algorithm and returns information about the algorithm.

The **CryptXmlDllGetAlgorithmInfo** function is exposed through the exported [CryptXmlDllGetInterface](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllgetinterface) function.

## Parameters

### `pXmlAlgorithm` [in]

A pointer to a [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that specifies the algorithm.

### `ppAlgInfo` [out]

A pointer to a pointer to a [CRYPT_XML_ALGORITHM_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm_info) structure.

When you have finished using the memory pointed to by the *ppAlgInfo* parameter, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.