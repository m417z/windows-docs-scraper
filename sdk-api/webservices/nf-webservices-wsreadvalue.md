# WsReadValue function

## Description

Reads text from a Reader and parses it according to the specified value type.
The Reader reads from its current position up to the next Start or End element and parses them according to the specified value type. If the Reader is already positioned on a Start or End element the buffer remains empty.
Comments are skipped and CDATA content is treated the same as other element content.

Leading and trailing whitespaces are ignored. If the value cannot be parsed according to the specified value type, the function returns a **WS_E_INVALID_FORMAT** error code. (See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

**Note** This function can fail for any of the reasons listed in [WsReadNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadnode).

## Parameters

### `reader` [in]

A pointer to the **XML Reader** from which the value is read.

### `valueType` [in]

The text interpretation type.

### `value`

A pointer to the parsed data if parsing was successful according to the specified value type. The size required is determined by value type. See [WS_VALUE_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_value_type) for more information.

### `valueSize` [in]

The byte size of the retrieved value.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

An example that reads an element containing an integer value.

``` syntax
// Advance the reader to the element
HRESULT hr = WsReadToStartElement(reader, localName, ns, NULL, error);
if (FAILED(hr))
{
    return hr;
}
// Advance past the element to the content
hr = WsReadStartElement(reader, error);
if (FAILED(hr))
{
    return hr;
}
// Read the content as an integer
__int32 i;
hr = WsReadValue(reader, WS_INT32_VALUE_TYPE, &i, sizeof(i), error);
if (FAILED(hr))
{
    return hr;
}
// Read the end element
hr = WsReadEndElement(reader, error);
if (FAILED(hr))
{
    return hr;
}
```

The grammar for the values types.

``` syntax

WS_BOOL_VALUE_TYPE     = "true"
                       | "false"
                       | "1"
                       | "0"
WS_INTxxx_VALUE_TYPE   = sign? digits
WS_UINTxxx_VALUE_TYPE  = digits
WS_FLOAT_VALUE_TYPE    = WS_DOUBLE_VALUE_TYPE
WS_DOUBLE_VALUE_TYPE   = sign? digits ("." digits)? exponent?
                       | "NaN"
                       | "INF"
                       | "-INF"
WS_DECIMAL_VALUE_TYPE  = sign? digits ("." digits)?
WS_GUID_VALUE_TYPE     = xxxxxxxx "-" xxxx "-" xxxx "-" xxxx "-" xxxxxxxxxxxx
WS_TIMESPAN_VALUE_TYPE = sign? (digits ".")? hh ":" mm ":" ss ("." d7)?
WS_DATETIME_VALUE_TYPE = yyyy "-" MM "-" dd "T" hh ":" mm ":" ss  ("." d7)? tz?
WS_DURATION_VALUE_TYPE = sign? "P" (digits "Y")  (digits "M")? (digits "D")?
                       | sign? "P" (digits "Y")? (digits "M")? (digits "D")?
                       | sign? "P" (digits "Y")? (digits "M")? (digits "D")
                       | sign? "P" (digits "Y")? (digits "M")? (digits "D")? "T" (digits "H")  (digits "M")? (digits ("." digits)? "S")?
                       | sign? "P" (digits "Y")? (digits "M")? (digits "D")? "T" (digits "H")? (digits "M")  (digits ("." digits)? "S")?
                       | sign? "P" (digits "Y")? (digits "M")? (digits "D")? "T" (digits "H")? (digits "M")? (digits ("." digits)? "S")
sign                   = "-"
                       | "+"
exponent               = E sign? digits
                       | e sign? digits
digits                 = [0-9]+
x                      = [0-9]
                       | [A-F]
                       | [a-f]
yyyy                   = 1-9999
hh                     = 0-23
mm                     = 0-59
ss                     = 0-59
MM                     = 1-31
tz                     = "Z"
                       | sign hh ":" mm
d7                     = digit digit? digit? digit? digit? digit? digit?

```