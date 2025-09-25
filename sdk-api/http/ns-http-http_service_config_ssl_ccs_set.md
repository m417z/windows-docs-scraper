# HTTP_SERVICE_CONFIG_SSL_CCS_SET structure

## Description

Represents the SSL certificate record that specifies that Http.sys should consult the Centralized Certificate Store (CCS) store to find certificates if the port receives a Transport Layer Security (TLS) handshake. Use this structure to add, delete, retrieve, or update that SSL certificate.

## Members

### `KeyDesc`

An [HTTP_SERVICE_CONFIG_SSL_CCS_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_key) structure that identifies the SSL CCS certificate record.

### `ParamDesc`

An [HTTP_SERVICE_CONFIG_SSL_PARAM](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_param) structure that holds the contents of the specified SSL CCS certificate record.

## Remarks

Pass this structure to the [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) or [HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration) function through the *pConfigInformation* parameter to add or remove an SSL certificate record. Pass this structure to the [HttpUpdateServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpupdateserviceconfiguration) function through the *ConfigInfo* parameter to update an SSL certificate record. Use the *pOutputConfigInfo* parameter of the [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function to retrieve SSL certificate record data in this structure. For all of these operations, set the *ConfigId* parameter of these functions to **HttpServiceConfigSslCcsCertInfo**.

## See also

[HTTP_SERVICE_CONFIG_SSL_CCS_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_key)

[HTTP_SERVICE_CONFIG_SSL_PARAM](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_param)

[HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration)

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)

[HttpUpdateServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpupdateserviceconfiguration)