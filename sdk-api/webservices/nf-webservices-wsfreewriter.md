# WsFreeWriter function

## Description

Releases the memory resource associated with an XML Writer object.

## Parameters

### `writer` [in]

A pointer to the **XML Writer** object to release. The pointer must reference a valid [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object
returned by [WsCreateWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatewriter) and the referenced value may not be **NULL**.

## Remarks

If necessary, [WsFlushWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsflushwriter) should be called before calling **WsFreeWriter** to guarantee
all data is emitted.