# MI_ClientFT_V1 structure

## Description

Client function tables.

## Members

### `applicationFT`

Pointer to the [MI_ApplicationFT](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_applicationft) function table
used by [MI_Application](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_application).

### `sessionFT`

Pointer to the **MI_SessionFT** function table used by
[MI_Session](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_session).

### `operationFT`

Pointer to the [MI_OperationFT](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationft) function table
used by [MI_Operation](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operation).

### `hostedProviderFT`

Pointer to the [MI_HostedProviderFT](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_hostedproviderft) function
table used by [MI_HostedProvider](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_hostedprovider).

### `serializerFT`

Pointer to the [MI_SerializerFT](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_serializerft) function table
used by [MI_Serializer](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_serializer).

### `deserializerFT`

Pointer to the [MI_DeserializerFT](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_deserializerft) function
table used by [MI_Deserializer](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_deserializer).

### `subscribeDeliveryOptionsFT`

Pointer to the
[MI_SubscriptionDeliveryOptionsFT](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptionsft)
function table used by
[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions).

### `destinationOptionsFT`

Pointer to the [MI_DestinationOptionsFT](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptionsft)
function table used by
[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions).

### `operationOptionsFT`

Pointer to the [MI_OperationOptionsFT](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptionsft)
function table used by
[MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions).

### `utilitiesFT`

Pointer to the [MI_UtilitiesFT](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_utilitiesft) function
table.