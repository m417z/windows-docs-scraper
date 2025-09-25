# CryptXmlGetReference function

## Description

The **CryptXmlGetReference** function returns the **Reference** element specified by the supplied handle.

## Parameters

### `hCryptXml` [in]

The handle of the **Reference** element to retrieve.

### `ppStruct` [out]

A pointer to a pointer to a [CRYPT_XML_REFERENCE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_reference) structure that contains the returned **Reference** element.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.