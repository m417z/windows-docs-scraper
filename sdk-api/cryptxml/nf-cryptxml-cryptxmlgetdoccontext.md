# CryptXmlGetDocContext function

## Description

The **CryptXmlGetDocContext** function returns the document context specified by the supplied handle.

## Parameters

### `hCryptXml` [in]

The handle of the document context to retrieve.

### `ppStruct` [out]

A pointer to a pointer to a [CRYPT_XML_DOC_CTXT](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_doc_ctxt) structure that contains the returned document context.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.