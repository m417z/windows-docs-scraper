# WsFreeError function

## Description

Releases the memory resource associated with an **Error** object created using [WsCreateError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateerror).
This releases the object and its constituent information.

## Parameters

### `error` [in]

A pointer to the **Error** object to release. The pointer must reference a valid **WS_ERROR** object
returned by [WsCreateError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateerror). The referenced value may
not be NULL.