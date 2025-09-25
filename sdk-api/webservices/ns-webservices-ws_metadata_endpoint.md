# WS_METADATA_ENDPOINT structure

## Description

Information about a single endpoint that was
read from metadata documents.

## Members

### `endpointAddress`

The address of the endpoint.

### `endpointPolicy`

An opaque handle representing the policy of the endpoint.
This handle is good until the metadata object
is freed or reset.

### `portName`

The WSDL port name of the endpoint, if available.

### `serviceName`

The WSDL service name of the endpoint, if available.

### `serviceNs`

The WSDL service namespace of the endpoint, if available.

### `bindingName`

The WSDL binding name of the endpoint, if available.

### `bindingNs`

The WSDL binding namespace of the endpoint, if available.

### `portTypeName`

The WSDL portType name of the endpoint, if available.

### `portTypeNs`

The WSDL portType namespace of the endpoint, if available.