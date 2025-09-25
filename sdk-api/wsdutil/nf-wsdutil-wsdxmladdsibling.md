# WSDXMLAddSibling function

## Description

Adds a sibling element.

## Parameters

### `pFirst` [in]

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that contains the first sibling.

### `pSecond` [in]

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that contains the second sibling.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pFirst* or *pSecond* is **NULL**. |