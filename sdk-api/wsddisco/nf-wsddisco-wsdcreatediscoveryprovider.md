# WSDCreateDiscoveryProvider function

## Description

Creates an [IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider) object.

## Parameters

### `pContext` [in]

An [IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext) interface that defines custom message types or namespaces.

If **NULL**, a default context representing the built-in message types and namespaces is used.

### `ppProvider` [out]

Returns a reference to the initialized [IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider) object. Cannot be **NULL**.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |