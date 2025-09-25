# WS_DYNAMIC_STRING_CALLBACK callback function

## Description

Determines whether the specified string can be written in optimized form. This callback is used in [WS_XML_WRITER_BINARY_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_binary_encoding)

## Parameters

### `callbackState` [in]

User-defined state that was passed to the function that accepted the *WS_DYNAMIC_STRING_CALLBACK*.

### `string` [in]

The string to look up in the dynamic dictionary.

### `found` [out]

Whether or not the string was found in the dynamic dictionary is returned here.

### `id` [out]

The id of the string is returned here.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.