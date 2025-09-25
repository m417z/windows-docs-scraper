# HTTP_SERVICE_CONFIG_SSL_CCS_QUERY structure

## Description

Specifies a Secure Sockets Layer (SSL) configuration to query for an SSL Centralized Certificate Store (CCS) record on the port when you call the [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function. The SSL certificate record specifies that Http.sys should consult the CCS store to find certificates if the port receives a Transport Layer Security (TLS) handshake.

## Members

### `QueryDesc`

One of the following values from the [HTTP_SERVICE_CONFIG_QUERY_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_query_type) enumeration that indicates whether the call to [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) is a call to retrieve a single record or part of a sequence of calls to retrieve a sequence of records.

| Value | Meaning |
| --- | --- |
| **HttpServiceConfigQueryExact** | The call to [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) is call to retrieve a single SSL CCS certificate record, which the **KeyDesc** member specifies. |
| **HttpServiceConfigQueryNext** | The call to [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) is part of a sequence of calls to retrieve a sequence of SSL CCS certificate records. The value of the **dwToken** member controls which record in the sequence that this call to **HttpQueryServiceConfiguration** retrieves. |

### `KeyDesc`

An [HTTP_SERVICE_CONFIG_SSL_CCS_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_key) structure that identifies the SSL CCS certificate record queried, if the **QueryDesc** member is equal to **HttpServiceConfigQueryExact**. Ignored if **QueryDesc** is equal to **HTTPServiceConfigQueryNext**.

### `dwToken`

The position of the record in the sequence of records that this call to [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) should retrieve if the **QueryDesc** method equals **HTTPServiceConfigQueryNext**, starting from zero. In other words, **dwToken** must be equal to zero on the first call to the **HttpQueryServiceConfiguration** function, one on the second call, two on the third call, and so forth. When the sequence of calls has returned all SSL certificate records, **HttpQueryServiceConfiguration** returns **ERROR_NO_MORE_ITEMS**.
Ignored if the **QueryDesc** is equal to **HttpServiceConfigQueryExact**.

## Remarks

Pass this structure to the [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function by using the *pInputConfigInfo* parameter when the *ConfigId* parameter is set to **HttpServiceConfigSslCcsCertInfo**.

## See also

[HTTP_SERVICE_CONFIG_QUERY_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_query_type)

[HTTP_SERVICE_CONFIG_SSL_CCS_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_key)

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)