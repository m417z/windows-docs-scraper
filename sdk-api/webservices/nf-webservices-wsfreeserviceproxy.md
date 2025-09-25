# WsFreeServiceProxy function

## Description

Releases the memory associated with a Service Proxy resource.

## Parameters

### `serviceProxy` [in]

A pointer to the **Service Proxy** to release. The pointer must reference a valid [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) object
returned by [WsCreateServiceProxy](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateserviceproxy). The referenced value may not be **NULL**.

## Remarks

For details of when it is allowed to call this function, see [Service Proxy](https://learn.microsoft.com/windows/desktop/wsw/service-proxy) .