# WSDXMLAddChild function

## Description

Adds a child element.

## Parameters

### `pParent`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that contains the parent element.

### `pChild`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that contains the child element.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pParent* is **NULL**, *pChild* is **NULL**, *pChild* already has a parent, or a sibling could not be added to an existing child of *pParent*. |