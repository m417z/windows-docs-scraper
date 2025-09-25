# WS_HEADER_TYPE enumeration

## Description

Identifies a type of header.

## Constants

### `WS_ACTION_HEADER:1`

The Action addressing header.

This header can be used with the following [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)s:

* [WS_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_XML_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_WSZ_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)

### `WS_TO_HEADER:2`

The To addressing header.

This header can be used with the following [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)s:

* [WS_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_XML_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_WSZ_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)

### `WS_MESSAGE_ID_HEADER:3`

The MessageID addressing header.

This header can be used with the following [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)s:

* [WS_UNIQUE_ID_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_XML_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_WSZ_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)

This header is not supported for [WS_ADDRESSING_VERSION_TRANSPORT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version).

### `WS_RELATES_TO_HEADER:4`

The RelatesTo addressing header.

This header can be used with the following [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)s:

* [WS_UNIQUE_ID_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_XML_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_WSZ_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)

This header is not supported for [WS_ADDRESSING_VERSION_TRANSPORT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version).

### `WS_FROM_HEADER:5`

The From addressing header.

This header is used with [WS_ENDPOINT_ADDRESS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type).

This header is not supported for [WS_ADDRESSING_VERSION_TRANSPORT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version).

### `WS_REPLY_TO_HEADER:6`

The ReplyTo addressing header.

This header is used with [WS_ENDPOINT_ADDRESS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type).

This header is not supported for [WS_ADDRESSING_VERSION_TRANSPORT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version).

### `WS_FAULT_TO_HEADER:7`

The FaultTo addressing header, in [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address) format.

This header is used with [WS_ENDPOINT_ADDRESS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type).

This header is not supported for [WS_ADDRESSING_VERSION_TRANSPORT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version).