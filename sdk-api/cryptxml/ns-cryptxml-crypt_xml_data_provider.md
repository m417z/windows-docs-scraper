# CRYPT_XML_DATA_PROVIDER structure

## Description

The **CRYPT_XML_DATA_PROVIDER** structure specifies the interface to the XML data provider.

## Members

### `pvCallbackState`

An application-defined argument that is passed to
the **pfnRead** and **pfnClose** callback functions.

### `cbBufferSize`

 The size, in bytes, of the data provider's buffer. The size can be zero if the size does not matter or if the size cannot be determined by the provider.
This value is used by a caller of **pfnRead** to determine the necessary size of the receiving buffer.

### `pfnRead`

A pointer to a [PFN_CRYPT_XML_DATA_PROVIDER_READ](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-pfn_crypt_xml_data_provider_read) callback function used to read data.

### `pfnClose`

A pointer to a [PFN_CRYPT_XML_DATA_PROVIDER_CLOSE](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-pfn_crypt_xml_data_provider_close) callback function used to release the data provider. When you have finished using the data provider, you must release it.