# CryptXmlDllGetInterface callback function

## Description

The **CryptXmlDllGetInterface** function retrieves a pointer to the cryptographic extension functions for the specified algorithm.

## Parameters

### `dwFlags`

This parameter is reserved and must be set to zero.

### `pMethod` [in]

A pointer to a [CRYPT_XML_ALGORITHM_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm_info) structure to retrieve the interface of.

### `pInterface` [out]

A pointer to a [CRYPT_XML_ALGORITHM_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm_info) structure to receive the interface information.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.

## Remarks

The cryptographic extensions DLL must export the **CryptXmlDllGetInterface** entry.

To get the [CRYPT_XML_CRYPTOGRAPHIC_INTERFACE](https://learn.microsoft.com/windows/win32/api/cryptxml/ns-cryptxml-crypt_xml_cryptographic_interface) table, CryptXml loads the registered cryptographic extensions DLL by using the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function, and then it calls the
**CryptXmlDllGetInterface** function.