# WS_FAULT structure

## Description

A Fault is a value carried in the body of a message which conveys a
processing failure. Faults are modeled using the **WS_FAULT** structure.

## Members

### `code`

The head of the list of fault codes which identifies the type of fault.

The fault codes are ordered from most generic to most specific.
There must be at least one fault code. The first fault code
must correspond to a fault code defined by SOAP.
For [WS_ENVELOPE_VERSION_SOAP_1_1](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version), only the most specific fault code
is serialized (the first one in the list).

If the namespace URI of the first fault code is the empty string,
then the first fault code will be transformed as follows
when the fault is serialized, as follows:

* The appropriate SOAP namespace will be used based on the
  [WS_ENVELOPE_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version).
* If the local name is "Sender" when using
  [WS_ENVELOPE_VERSION_SOAP_1_1](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version), then "Client" will be used instead.
* If the local name is "Receiver" when using
  [WS_ENVELOPE_VERSION_SOAP_1_1](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version), then "Server" will be used instead.

These transformations allow a SOAP fault code
to be specified without having to worry about which SOAP version is used.

### `reasons`

The text describing the fault. This is an array to allow for different
languages.

### `reasonCount`

The number of reasons in the reasons array. This would be more than one
if the text was represented in multiple languages. There must be at
least one fault reason.

For [WS_ENVELOPE_VERSION_SOAP_1_1](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version), only the first reason is serialized.

### `actor`

The name of the processor that caused the fault. If the string is zero
length, then it's assumed to be the endpoint.

### `node`

The location of the processor that caused the fault. If the string is zero
length, then it's assumed to be the endpoint.

For [WS_ENVELOPE_VERSION_SOAP_1_1](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version), this value is not serialized.

### `detail`

The fault detail allows for XML content to be included along with the fault. If
there is no detail, then this field may be **NULL**.

For [WS_ENVELOPE_VERSION_SOAP_1_1](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version), this should only be used if the fault
does not relate to processing of a header of the message. Faults relating to
headers should use a custom header to relay information about the fault.

If there is detail for the fault, the [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) should contain
an element that corresponds to the detail element of a SOAP fault. The
fault-specific XML content is contained within the detail element.
The local name and namespace of the element are ignored; they are replaced with
the appropriate element name according to the [WS_ENVELOPE_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version) when the detail element is written.