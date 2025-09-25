# WS_SERVICE_CONTRACT structure

## Description

Specifies a service contract on an [endpoint](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint).

## Members

### `contractDescription`

The typed contract metadata. See [WS_CONTRACT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_contract_description). Optional, if **defaultMessageHandlerCallback** is given.

### `defaultMessageHandlerCallback`

Callback for processing unhandled messages. Optional if contractDescription is given.

### `methodTable`

The function table. Mandatory, if **contractDescription** is given.