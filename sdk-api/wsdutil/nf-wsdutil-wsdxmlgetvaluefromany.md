# WSDXMLGetValueFromAny function

## Description

Retrieves a text value from a specified child element of an XML **any** element.

## Parameters

### `pszNamespace` [in]

The namespace of the element to retrieve.

### `pszName` [in]

The name of the element to retrieve.

### `pAny` [in]

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that contains the **any** element that is the parent of the element to retrieve.

### `ppszValue` [out]

The text value of the element specified by *pszNamespace* and *pszName*. The memory usage of *ppszValue* is managed elsewhere. Consequently, the calling application should not attempt to deallocate *ppszValue*.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | The length in characters of *pszNamespace* or *pszName* exceeds WSD_MAX_TEXT_LENGTH (8192), or *pAny* is **NULL**. |
| **E_POINTER** | *ppszValue* is **NULL**. |
| **E_FAIL** | The method failed. |