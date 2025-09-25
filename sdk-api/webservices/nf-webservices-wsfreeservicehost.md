# WsFreeServiceHost function

## Description

Releases the memory associated with a [Service Host](https://learn.microsoft.com/windows/desktop/wsw/service-host) object.

## Parameters

### `serviceHost` [in]

A pointer to the **Service Host** object to release. The pointer must reference a valid [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host) object
returned by [WsCreateServiceHost](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateservicehost) and the referenced **Service Host** value may not be **NULL**.