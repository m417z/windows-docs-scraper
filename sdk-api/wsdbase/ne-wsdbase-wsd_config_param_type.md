# WSD_CONFIG_PARAM_TYPE enumeration

## Description

Specifies the kind of data stored in a
[WSD_CONFIG_PARAM](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_config_param) structure.

## Constants

### `WSD_CONFIG_MAX_INBOUND_MESSAGE_SIZE:1`

The *pConfigData* member is a pointer to a **DWORD** that specifies the maximum size, in octets, of an inbound message.

The *dwConfigDataSize* member is 4.

### `WSD_CONFIG_MAX_OUTBOUND_MESSAGE_SIZE:2`

The *pConfigData* member is a pointer to a **DWORD** that specifies the maximum size, in octets, of an outbound message.

The *dwConfigDataSize* member is 4.

### `WSD_SECURITY_SSL_CERT_FOR_CLIENT_AUTH:3`

Used to pass in the client certificate that WSDAPI will use for client authentication in an SSL connection.

The *pConfigData* member is a pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that represents the client certificate. The caller needs to have read access to the private key of the certificate.

The *dwConfigDataSize* member is the size of the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.

### `WSD_SECURITY_SSL_SERVER_CERT_VALIDATION:4`

Used to pass in the SSL server certificate validation information into WSDAPI. When establishing the SSL connection, WSDAPI will accept only a server certificate that matches the criteria specified by the [WSD_SECURITY_CERT_VALIDATION](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_security_cert_validation) structure.

The *pConfigData* member is a pointer to a [WSD_SECURITY_CERT_VALIDATION](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_security_cert_validation) structure.

The *dwConfigDataSize* member is the size of the [WSD_SECURITY_CERT_VALIDATION](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_security_cert_validation) structure.

### `WSD_SECURITY_SSL_CLIENT_CERT_VALIDATION:5`

Used to pass in the SSL client certificate validation information into WSDAPI. On incoming SSL connections, if a client certificate is available, WSDAPI will reject the connection if the client certificate doesn't match the validation criteria specified by the [WSD_SECURITY_CERT_VALIDATION](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_security_cert_validation) structure.

The *pConfigData* member is a pointer to a [WSD_SECURITY_CERT_VALIDATION](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_security_cert_validation) structure.

The *dwConfigDataSize* member is the size of the [WSD_SECURITY_CERT_VALIDATION](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_security_cert_validation) structure.

### `WSD_SECURITY_SSL_NEGOTIATE_CLIENT_CERT:6`

Specifies that on incoming SSL connections, WSDAPI will request a client certificate from the SSL client if one is not already made available by the client. If the remote entity cannot provide a client certificate, the connection will be rejected. Note that the SSL record that is created for that port must explicitly allow for client certificate negotiation.

The *pConfigData* member is **NULL**.

The *dwConfigDataSize* member is 0.

### `WSD_SECURITY_COMPACTSIG_SIGNING_CERT:7`

Used to specify which certificate is to be used by WSDAPI to sign outbound WS_Discovery UDP messages.

The *pConfigData* member is a pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that represents the signing certificate. The caller needs to have read access to the certificate's private key..

The *dwConfigDataSize* member is the size of the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.

### `WSD_SECURITY_COMPACTSIG_VALIDATION:8`

This is used to specify the parameters used to verify inbound signed WS_Discovery UDP message.

The *pConfigData* member is a pointer to a [WSD_SECURITY_SIGNATURE_VALIDATION](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_security_signature_validation) structure.

The *dwConfigDataSize* member is the size of the [WSD_SECURITY_SIGNATURE_VALIDATION](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_security_signature_validation) structure.

### `WSD_CONFIG_HOSTING_ADDRESSES:9`

This applies only to the [WSDCreateDeviceHost2](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-wsdcreatedevicehost2) function. It is used to specify an array of addresses on which the device host should be hosted on. The equivalent is functionality provided through the *ppHostAddresses* and *dwHostAddressCount* parameters of the [WSDCreateDeviceHostAdvanced](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-wsdcreatedevicehostadvanced) function.

The *pConfigData* member is a pointer to a [WSD_CONFIG_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_config_addresses) structure. The **addresses** member of this structure points to an array of [IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress) objects, each of which is an address on which the device host will listen on.

The *dwConfigDataSize* member is the size of the [WSD_CONFIG_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_config_addresses) structure.

### `WSD_CONFIG_DEVICE_ADDRESSES:10`

This applies only to the [WSDCreateDeviceProxy2](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-wsdcreatedeviceproxy2) function. It is used to specify an address for the device for which the proxy is created. The equivalent is functionality provided through the *deviceConfig* parameter of the [WSDCreateDeviceProxyAdvanced](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-wsdcreatedeviceproxyadvanced) function.

The *pConfigData* member is a pointer to a [WSD_CONFIG_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_config_addresses) structure. The **addresses** member of this structure points to an array of [IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress) objects, each of which is an address of the device to which the proxy is created. Currently only one such address is allowed.

The *dwConfigDataSize* member is the size of the [WSD_CONFIG_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_config_addresses) structure.

### `WSD_SECURITY_REQUIRE_HTTP_CLIENT_AUTH:11`

Indicates a requirement for HTTP Authentication using one of the auth schemes specified through WSD_SECURITY_HTTP_AUTH_SCHEMES. Specific scenarios include:

* When specified during a [WSDCreateDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-wsdcreatedevicehost) operation, DPWS clients will be required to authenticate messages sent to the Hosted Services of the WSDAPI device host using HTTP Authentication.
* If this is value is expressed in conjunction with WSD_SECURITY_SSL_NEGOTIATE_CLIENT_CERT, then WSDAPI will require HTTP clients to send a client certificate and utilize HTTP authentication.

### `WSD_SECURITY_REQUIRE_CLIENT_CERT_OR_HTTP_CLIENT_AUTH:12`

When this value is specified, WSDAPI will request HTTP clients to send a client certificate. If the client cannot provide one, then WSDAPI will require HTTP authentication. If the client can do neither, it will be rejected by WSDAPI. Specific scenarios include:

* When specified during a [WSDCreateDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-wsdcreatedevicehost) operation, this behavior will apply to web service messages from DPWS clients.

**Note** This parameter cannot be used in conjunction with WSD_SECURITY_SSL_NEGOTIATE_CLIENT_CERT. If it is, WSDAPI will return E_INVALIDARG.

### `WSD_SECURITY_USE_HTTP_CLIENT_AUTH:13`

If the server requires authentication, WSDAPI will authenticate using HTTP authentication. Specific scenarios include:

* When specified during a [WSDCreateDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-wsdcreatedevicehost) operation, this behavior will apply to web service messages from DPWS clients.
* If this value is expressed in conjunction with WSD_SECURITY_SSL_CERT_FOR_CLIENT_AUTH, WSDAPI will send the client certificate and authenticate using HTTP authentication if either operation is required by server.