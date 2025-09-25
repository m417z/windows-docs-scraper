# IKEV2_TUNNEL_CONFIG_PARAMS1 structure

## Description

Used to get or set tunnel parameters for Internet Key Exchange version 2 (IKEv2) devices.

Do not use the **IKEV2_TUNNEL_CONFIG_PARAMS1** structure directly in your code; using [IKEV2_TUNNEL_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/RRAS/router-management-data-types) instead ensures that the proper version, based on the operating system the code in compiled under, is used.

## Members

### `dwIdleTimeout`

A value that specifies the time, in seconds, after which the connection will be disconnected if there is no traffic.

### `dwNetworkBlackoutTime`

A value that specifies the retransmission timeout for IKEv2 request packets. IKEv2 expects a response for every request packet sent, this value specifies the time after which the connection is deleted in case a response is not received.

### `dwSaLifeTime`

A value that specifies the lifetime, in seconds, of a security association (SA), after which the SA is no longer valid.

### `dwSaDataSizeForRenegotiation`

A value that specifies the number of kilobytes that are allowed to be transferred using a SA before it must be renegotiated.

### `dwConfigOptions`

Not implemented. Must be set to 0.

### `dwTotalCertificates`

A value that specifies the number of certificates in the **certificateNames** member.

### `certificateNames`

An array of CERT_NAME_BLOB structures that contain X.509 public key infrastructure certificates.