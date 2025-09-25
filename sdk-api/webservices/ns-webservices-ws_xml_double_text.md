# WS_XML_DOUBLE_TEXT structure

## Description

Represents an 8 byte floating point value. (e.g. The value 0.0 represents the text "0")

## Members

### `text`

The base type for all types that derive from [WS_XML_TEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_text).

### `value`

The value.

## Remarks

The textual representation of the value has enough digits to preserve the floating point value.

Negative zero is represented by the text "-0".

Positive infinity is represented by the text "INF";

Negative infinity is represented by the text "-INF";

Unrepresentable values are represented by the text "NaN".

For more information on this representation, refer to IEEE Standard for Binary Floating-Point Arithmetic, available on the Web site http://www.ieee.org/.