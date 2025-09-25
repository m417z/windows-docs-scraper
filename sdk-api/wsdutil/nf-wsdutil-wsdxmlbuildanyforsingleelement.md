# WSDXMLBuildAnyForSingleElement function

## Description

Creates an XML element with a specified name and value. The created element can be used as the child of an XML **any** element.

## Parameters

### `pElementName` [in]

Reference to a [WSDXML_NAME](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_name) structure that contains the name of the created element.

### `pszText` [in]

The text value of the created element.

### `ppAny` [out]

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) that contains the created element. *ppAny* must be freed with a call to [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory).

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pElementName* is **NULL** or the length in characters of *pszText* exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **E_POINTER** | *ppAny* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |