# WSDXMLCleanupElement function

## Description

Frees memory associated with an XML element.

## Parameters

### `pAny` [in]

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pAny* is **NULL**. |