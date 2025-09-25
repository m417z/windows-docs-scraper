# WsFreeReader function

## Description

Releases the memory resource associated with an XML_Reader object.

## Parameters

### `reader` [in]

A pointer to the **XML Reader** object to release. The pointer must reference a valid [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) object returned by [WsCreateReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatereader) and the referenced **XML Reader** value may not be **NULL**.