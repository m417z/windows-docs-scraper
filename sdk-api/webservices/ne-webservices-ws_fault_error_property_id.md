# WS_FAULT_ERROR_PROPERTY_ID enumeration

## Description

Information about a fault.

## Constants

### `WS_FAULT_ERROR_PROPERTY_FAULT:0`

An optional [WS_FAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault) value that is the fault representation of the error. If no
fault representation is present, then the value is **NULL**.

To set the WS_FAULT value, pass a WS_FAULT* to [WsSetFaultErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetfaulterrorproperty).
The error object will make a copy of the WS_FAULT. The error object will also
add the fault string of the fault to the set of error strings in the error object
if the language of the fault string matches that of the error object.

To get the WS_FAULT value, pass a WS_FAULT** to [WsGetFaultErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetfaulterrorproperty),
which will either return **NULL** (indicating no fault has been set), or will
return a non-**NULL** pointer to the WS_FAULT. The non-**NULL** pointer is valid until
[WsResetError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreseterror) or [WsFreeError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreeerror) are called for the error object.

The default value is **NULL**.

### `WS_FAULT_ERROR_PROPERTY_ACTION:1`

An optional [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string) value representing the action to use for the fault.
If the length of the string is zero, then no action is present.

To get the string value, pass a WS_XML_STRING* to [WsGetFaultErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetfaulterrorproperty).
The returned string is valid until [WsResetError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreseterror) or [WsFreeError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreeerror)
are called for the error object.

To set the string value, pass a WS_XML_STRING* to [WsSetFaultErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetfaulterrorproperty).
The error object will make a copy of the string.

The default value is a zero-length string.

### `WS_FAULT_ERROR_PROPERTY_HEADER:2`

An optional [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) value representing a header to
add to the fault message relating to the fault.
If the pointer to the XML_BUFFER is **NULL**, then no header is present.

To get the header value, pass a WS_XML_BUFFER** to [WsGetFaultErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetfaulterrorproperty).
The returned WS_XML_BUFFER is valid until [WsResetError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreseterror) or [WsFreeError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreeerror)
are called for the error object.

To set the header value, pass a WS_XML_BUFFER** to [WsSetFaultErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetfaulterrorproperty).
The error object will make a copy of the buffer.

The default value is **NULL**.