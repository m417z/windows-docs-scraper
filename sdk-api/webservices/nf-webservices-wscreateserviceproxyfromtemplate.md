# WsCreateServiceProxyFromTemplate function

## Description

Helper routine for creating a [service proxy](https://learn.microsoft.com/windows/desktop/wsw/service-proxy) from policy templates.

## Parameters

### `channelType` [in]

A [WS_CHANNEL_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type) enumeration value representing the channel type for the service proxy.

### `properties`

An array of [WS_PROXY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_proxy_property) structures containing optional properties for the service proxy.

The value of this parameter may be **NULL**, in which case, the *propertyCount* parameter must be 0 (zero).

### `propertyCount` [in]

The number of properties in the *properties* array.

### `templateType` [in]

A [WS_BINDING_TEMPLATE_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_binding_template_type) enumeration value representing the type of templates used to create the service proxy.

Please see the **Remarks** for more information.

### `templateValue`

The optional template structure to be created and filled in by an application. This template structure must be consistent with the input template type (in the *templateType*). When *templateValue* parameter is **NULL**, it is equivalent to the corresponding template structure initialized to zero.

Please see the **Remarks** for more information.

### `templateSize` [in]

The size, in bytes, of the template structure (in the *templateValue* parameter).

### `templateDescription` [in]

The description of *templateValue*. This must match *templateType*.

Please see the **Remarks** for more information.

### `templateDescriptionSize` [in]

The size of the template description.

### `serviceProxy`

On success, a pointer that receives the address of the [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) structure representing the new service proxy.
When you no longer need this structure, you must free it by calling [WsFreeServiceProxy](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreeserviceproxy).

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

## Remarks

**WsCreateServiceProxyFromTemplate** creates the [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) structure from input policy templates and additional user input.

The following table shows the mapping between *templateType* values and the corresponding data types to be used in *templateValue* and *templateDescription*.

| templateType | templateValue | templateDescription |
| --- | --- | --- |
| WS_HTTP_BINDING_TEMPLATE_TYPE | WS_HTTP_BINDING_TEMPLATE | WS_HTTP_POLICY_DESCRIPTION |
| WS_HTTP_SSL_BINDING_TEMPLATE_TYPE | WS_HTTP_SSL_BINDING_TEMPLATE | WS_HTTP_SSL_POLICY_DESCRIPTION |
| WS_HTTP_HEADER_AUTH_BINDING_TEMPLATE_TYPE | WS_HTTP_HEADER_AUTH_BINDING_TEMPLATE | WS_HTTP_HEADER_AUTH_POLICY_DESCRIPTION |
| WS_HTTP_SSL_HEADER_AUTH_BINDING_TEMPLATE_TYPE | WS_HTTP_SSL_HEADER_AUTH_BINDING_TEMPLATE | WS_HTTP_SSL_HEADER_AUTH_POLICY_DESCRIPTION |
| WS_HTTP_SSL_USERNAME_BINDING_TEMPLATE_TYPE | WS_HTTP_SSL_USERNAME_BINDING_TEMPLATE | WS_HTTP_SSL_USERNAME_POLICY_DESCRIPTION |
| WS_HTTP_SSL_KERBEROS_APREQ_BINDING_TEMPLATE_TYPE | WS_HTTP_SSL_KERBEROS_APREQ_BINDING_TEMPLATE | WS_HTTP_SSL_KERBEROS_APREQ_POLICY_DESCRIPTION |
| WS_TCP_BINDING_TEMPLATE_TYPE | WS_TCP_BINDING_TEMPLATE | WS_TCP_POLICY_DESCRIPTION |
| WS_TCP_SSPI_BINDING_TEMPLATE_TYPE | WS_TCP_SSPI_BINDING_TEMPLATE | WS_TCP_SSPI_POLICY_DESCRIPTION |
| WS_TCP_SSPI_USERNAME_BINDING_TEMPLATE_TYPE | WS_TCP_SSPI_USERNAME_BINDING_TEMPLATE | WS_TCP_SSPI_USERNAME_POLICY_DESCRIPTION |
| WS_TCP_SSPI_KERBEROS_APREQ_BINDING_TEMPLATE_TYPE | WS_TCP_SSPI_KERBEROS_APREQ_BINDING_TEMPLATE | WS_TCP_SSPI_KERBEROS_APREQ_POLICY_DESCRIPTION |
| WS_HTTP_SSL_USERNAME_SECURITY_CONTEXT_BINDING_TEMPLATE_TYPE | WS_HTTP_SSL_USERNAME_SECURITY_CONTEXT_BINDING_TEMPLATE | WS_HTTP_SSL_USERNAME_SECURITY_CONTEXT_POLICY_DESCRIPTION |
| WS_HTTP_SSL_KERBEROS_APREQ_SECURITY_CONTEXT_BINDING_TEMPLATE_TYPE | WS_HTTP_SSL_KERBEROS_APREQ_SECURITY_CONTEXT_BINDING_TEMPLATE | WS_HTTP_SSL_KERBEROS_APREQ_SECURITY_CONTEXT_POLICY_DESCRIPTION |
| WS_TCP_SSPI_USERNAME_SECURITY_CONTEXT_BINDING_TEMPLATE_TYPE | WS_TCP_SSPI_USERNAME_SECURITY_CONTEXT_BINDING_TEMPLATE | WS_TCP_SSPI_USERNAME_SECURITY_CONTEXT_POLICY_DESCRIPTION |
| WS_TCP_SSPI_KERBEROS_APREQ_SECURITY_CONTEXT_BINDING_TEMPLATE_TYPE | WS_TCP_SSPI_KERBEROS_APREQ_SECURITY_CONTEXT_BINDING_TEMPLATE | WS_TCP_SSPI_KERBEROS_APREQ_SECURITY_CONTEXT_POLICY_DESCRIPTION |