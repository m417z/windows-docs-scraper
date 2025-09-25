# CryptXmlGetSignature function

## Description

The **CryptXmlGetSignature** function returns an XML **Signature** element.

## Parameters

### `hCryptXml` [in]

The handle of the **Signature** element.

### `ppStruct` [out]

A pointer to a pointer to a [CRYPT_XML_SIGNATURE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_signature) structure to receive the signature.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.