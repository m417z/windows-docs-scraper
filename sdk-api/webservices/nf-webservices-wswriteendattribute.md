# WsWriteEndAttribute function

## Description

This operation finishes writing an attribute to the current element.
If [WsWriteStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartattribute) is called the Writer does not permit another element
or attribute to be written until **WsWriteEndAttribute** is called.

## Parameters

### `writer` [in]

A pointer to the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object to which the attribute is written. The pointer must reference a valid **XML Writer** object.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |