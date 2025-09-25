# WSD_SECURITY_CERT_VALIDATION_V1 structure

## Description

Represents the criteria for matching client certificates against those of an HTTPS server.

Do not use [WSD_SECURITY_CERT_VALIDATION_V1](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437346(v=vs.85)) directly in your code; using **WSD_SECURITY_CERT_VALIDATION** instead ensures that the proper version, based on the Windows version.

## Members

### `certMatchArray`

An array of [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structures that contain certificates to be matched against those provided by the HTTPS server or client. Only one matching certificate is required for validation. This parameter can be NULL.

### `dwCertMatchArrayCount`

The count of certificates in *certMatchArray*.

### `hCertMatchStore`

A handle to a certificate store that contains certificates to be matched against those provided by the HTTPS server or client. Only one matching certificate is required for validation. This parameter can be NULL.

### `hCertIssuerStore`

A handle to a certificate store that contains root certificates against which a certificate from the HTTPS server or client should chain to. Validation succeeds as long as the certificate chains up to at least one root certificate. This parameter can be NULL.

### `dwCertCheckOptions`

A bitwise OR combination of values that specify which certificate checks to ignore.

| Value | Meaning |
| --- | --- |
| **WSDAPI_SSL_CERT_DEFAULT_CHECKS**<br><br>0x0 | Handle any revoked certificate errors. |
| **WSDAPI_SSL_CERT_IGNORE_REVOCATION**<br><br>0x1 | Ignore revoked certificate errors. |
| **WSDAPI_SSL_CERT_IGNORE_EXPIRY**<br><br>0x2 | Ignore expired certificate errors. |
| **WSDAPI_SSL_CERT_IGNORE_WRONG_USAGE**<br><br>0x4 | Ignore certificate use errors. |
| **WSDAPI_SSL_CERT_IGNORE_UNKNOWN_CA**<br><br>0x8 | Ignore unknown certificate authority errors. |
| **WSDAPI_SSL_CERT_IGNORE_INVALID_CN**<br><br>0x10 | Ignore invalid common name certificate errors. |

## Remarks

This structure is used in the **pConfigData** member of the [WSD_CONFIG_PARAM](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_config_param) structure.

When the **configParamType** of [WSD_CONFIG_PARAM](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_config_param) is **WSD_SECURITY_SSL_SERVER_CERT_VALIDATION**, this structure can be used to validate SSL server certificates presented by an SSL server.

When the **configParamType** of [WSD_CONFIG_PARAM](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_config_param) is **WSD_SECURITY_SSL_CLIENT_CERT_VALIDATION**, this structure can be used to validate SSL client certificates presented by an SSL client.

**WSD_SECURITY_CERT_VALIDATION** defines 3 certificate matching mechanisms. To obtain a match, at least one such mechanism must be satisfied.

If the application is built using Windows 8 SDK targeted for Windows 8 OS, **WSD_SECURITY_CERT_VALIDATION** resolves into the new structure. However, as a result, the application can then only run on Windows 8 machines.

If the application is built using Windows 8 SDK targeted for Windows 7 OS, **WSD_SECURITY_CERT_VALIDATION** will resolve into the old structure ([WSD_SECURITY_CERT_VALIDATION_V1](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437346(v=vs.85))). While it's a given that the application will be supported for Windows 7, it also on Windows 8 since **wsdapi.dll** on Windows 8 will handle both the old and the newer versions of this structure.

An application already built using Windows 7 SDK will use the old version of this structure. It will run fine on Windows 8 since **wsdapi.dll** on Windows 8 can handle both versions.