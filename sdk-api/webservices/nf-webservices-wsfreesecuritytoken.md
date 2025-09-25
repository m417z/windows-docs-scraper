# WsFreeSecurityToken function

## Description

Releases the memory resource associated with a **Security Token** object.

## Parameters

### `token` [in]

A pointer to the **Security Token** object to release. The pointer must reference a valid [WS_SECURITY_TOKEN](https://learn.microsoft.com/windows/desktop/wsw/ws-security-token) object returned by [WsCreateXmlSecurityToken](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatexmlsecuritytoken).