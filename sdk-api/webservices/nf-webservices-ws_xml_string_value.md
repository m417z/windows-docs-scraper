# WS_XML_STRING_VALUE macro

## Description

Provides an initializer for a [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string) structure when there is no associated dictionary ID.

## Parameters

### `S`

A static constant string, encoded in UTF-8.

## Remarks

This initializer assumes the string is a static constant string. It must be encoded in UTF-8.

The following is example usage:

`WS_XML_STRING myString = WS_XML_STRING_VALUE("MyString");`