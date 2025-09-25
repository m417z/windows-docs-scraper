# WS_SERVICE_ENDPOINT structure

## Description

Represents an individual endpoint on a service host. The properties on the endpoint
are used to specify the address, binding and contract.

## Members

### `address`

The URL address on which the endpoint is going to listen.

### `channelBinding`

The binding for the channel/listener.

### `channelType`

The [type of channel](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type) being hosted by the endpoint.

### `securityDescription`

A description of the security required for this channel. This can be **NULL** if no security is required.

### `contract`

The contract of the endpoint.

### `authorizationCallback`

Authorization callback for the service endpoint.

### `properties`

An array of properties to configure the service endpoint.

### `propertyCount`

Number of elements in the WS_SERVICE_ENDPOINT_PROPERTY array.

### `channelProperties`

 Channel properties associated with the endpoint. An application should be careful in modifying default values. For example, modifying send/receive timeouts may result in unexpected behavior and cause the client to fail.