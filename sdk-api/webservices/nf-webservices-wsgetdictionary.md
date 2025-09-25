# WsGetDictionary function

## Description

Retrieves an [XML Dictionary](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_dictionary) object. The retrieved Dictionary is returned by the *dictionary* reference parameter.

## Parameters

### `encoding` [in]

Indicates an enumeration of the Dictionary encoding.

### `dictionary`

A reference to a [WS_XML_DICTIONARY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_dictionary) structure for the retrieved **Dictionary**.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.