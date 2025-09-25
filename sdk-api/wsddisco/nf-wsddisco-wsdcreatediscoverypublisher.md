# WSDCreateDiscoveryPublisher function

## Description

Creates an [IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher) object.

## Parameters

### `pContext` [in]

An [IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext) interface that defines custom message types or namespaces.

If **NULL**, a default context representing the built-in message types and namespaces is used.

### `ppPublisher` [out]

Returns a reference to the initialized [IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher) object. Cannot be **NULL**.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppPublisher* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |