# WsXmlStringEquals function

## Description

Compares two [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string) objects for equality. The operation performs an ordinal comparison
of the character values contained by the String objects.

## Parameters

### `string1` [in]

A pointer to the first string to compare.

### `string2` [in]

A pointer to the second string to compare.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The strings are equal. |
| **S_FALSE** | The strings are not equal. |
| **E_INVALIDARG** | One or more parameters are not correct. |

## Remarks

This function is typically used to compare localNames and namespaces in XML.