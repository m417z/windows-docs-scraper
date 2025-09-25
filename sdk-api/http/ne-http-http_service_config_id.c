typedef enum _HTTP_SERVICE_CONFIG_ID {
  HttpServiceConfigIPListenList,
  HttpServiceConfigSSLCertInfo,
  HttpServiceConfigUrlAclInfo,
  HttpServiceConfigTimeout,
  HttpServiceConfigCache,
  HttpServiceConfigSslSniCertInfo,
  HttpServiceConfigSslCcsCertInfo,
  HttpServiceConfigSetting,
  HttpServiceConfigSslCertInfoEx,
  HttpServiceConfigSslSniCertInfoEx,
  HttpServiceConfigSslCcsCertInfoEx,
  HttpServiceConfigSslScopedCcsCertInfo,
  HttpServiceConfigSslScopedCcsCertInfoEx,
  HttpServiceConfigMax
} HTTP_SERVICE_CONFIG_ID, *PHTTP_SERVICE_CONFIG_ID;