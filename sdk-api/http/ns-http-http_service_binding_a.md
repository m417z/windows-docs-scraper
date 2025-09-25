# HTTP_SERVICE_BINDING_A structure

## Description

The **HTTP_SERVICE_BINDING_A** structure provides Service Principle Name (SPN) in ASCII.

## Members

### `Base`

An [HTTP_SERVICE_BINDING_BASE](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_base) value, the **Type** member of which must be set to **HttpServiceBindingTypeA**.

### `Buffer`

A pointer to a buffer that represents the SPN.

### `BufferSize`

The length, in bytes, of the string in **Buffer**.